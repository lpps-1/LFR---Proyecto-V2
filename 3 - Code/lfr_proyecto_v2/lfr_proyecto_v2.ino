#include <SparkFun_TB6612.h>

#define NUM_SENSORS 5

// -------------------- SENSOR PINS --------------------
int sensorPins[NUM_SENSORS] = {A3, A1, A0, A6, A2};

// -------------------- MANUAL CALIBRATION VALUES --------------------
int whiteValues[NUM_SENSORS] = {974, 974, 973, 974, 974};
int blackValues[NUM_SENSORS] = {346, 345, 345, 345, 343};

int threshold[NUM_SENSORS];

// -------------------- MOTOR PINS --------------------
#define AIN1 7
#define AIN2 8
#define PWMA 5
#define BIN1 9
#define BIN2 10
#define PWMB 11
#define STBY 12

Motor motorA(AIN1, AIN2, PWMA, -1, STBY);
Motor motorB(BIN1, BIN2, PWMB, -1, STBY);

// -------------------- SPEED SETTINGS --------------------
int fullSpeed     = 240;
int turnSpeed     = 160;   // BASE correction
int hardTurnSpeed = 190;  

int motorDirection = -1;

// -------------------- LINE MEMORY --------------------
enum LastSeen { LEFT, RIGHT, NONE };
LastSeen lastOnTrack = NONE;

// -------------------- START BUTTON --------------------
#define START_BTN 6

// -------------------- THRESHOLD CALC --------------------
void calculateThresholds() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    threshold[i] = (whiteValues[i] + blackValues[i]) / 2;
  }
}

// -------------------- SETUP --------------------
void setup() {
  pinMode(START_BTN, INPUT_PULLUP);
  Serial.begin(9600);
  calculateThresholds();
}

// -------------------- LOOP --------------------
void loop() {
  if (digitalRead(START_BTN) == LOW) {
    delay(50);
    if (digitalRead(START_BTN) == LOW) followLine();
  }
}

// -------------------- LINE FOLLOW --------------------
void followLine() {
  while (true) {

    int s[NUM_SENSORS];
    for (int i = 0; i < NUM_SENSORS; i++) {
      s[i] = analogRead(sensorPins[i]);
    }

    bool L2 = s[0] < threshold[0];
    bool L1 = s[1] < threshold[1];
    bool C  = s[2] < threshold[2];
    bool R1 = s[3] < threshold[3];
    bool R2 = s[4] < threshold[4];

    bool any = L2 || L1 || C || R1 || R2;

    if (any) {

      // ---------- PERFECT CENTER ----------
      if (C) {
        moveForward(fullSpeed);

        if (L1 || L2) lastOnTrack = LEFT;
        else if (R1 || R2) lastOnTrack = RIGHT;
      }

      // ---------- LEFT SIDE ----------
      else if (L1) {
        turnLeft(turnSpeed);          // SLIGHT correction
        lastOnTrack = LEFT;
      }
      else if (L2) {
        turnLeft(turnSpeed + 40);     // HARDER correction
        lastOnTrack = LEFT;
      }

      // ---------- RIGHT SIDE ----------
      else if (R1) {
        turnRight(turnSpeed);
        lastOnTrack = RIGHT;
      }
      else if (R2) {
        turnRight(turnSpeed + 40);
        lastOnTrack = RIGHT;
      }
    }

    // ---------- COMPLETELY LOST ----------
    else {
      if (lastOnTrack == LEFT)  spinAntiClockwise(hardTurnSpeed);
      else                      spinClockwise(hardTurnSpeed);
    }

    delay(2);
  }
}

// -------------------- MOTOR WRAPPERS --------------------
void moveForward(int speed) {
  motorA.drive(speed * motorDirection);
  motorB.drive(speed * motorDirection);
}

// SLIGHT turn = only 25% speed reduction
void turnLeft(int speed) {
  motorA.drive(-speed * motorDirection);
  motorB.drive(speed * motorDirection);
}

void turnRight(int speed) {
  motorA.drive(speed * motorDirection);
  motorB.drive(-speed * motorDirection);
}

void spinAntiClockwise(int speed) {
  motorA.drive(-speed * motorDirection);
  motorB.drive((speed *1/2) * motorDirection);
}

void spinClockwise(int speed) {
  motorA.drive((speed *1/2) * motorDirection);
  motorB.drive(-speed * motorDirection);
}
  