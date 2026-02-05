#ifndef BLACK_LINE_H
#define BLACK_LINE_H

#include <SparkFun_TB6612.h>

// -------------------- Sensor Pins --------------------
#define NUM_SENSORS 5
static int sensorPins[NUM_SENSORS] = {A6, A3, A2, A1, A0}; // mirrored new robot wiring
static int threshold[NUM_SENSORS] = {643, 642, 642, 642, 642};

// -------------------- Motor Pins --------------------
#define AIN1 7
#define AIN2 8
#define PWMA 5
#define BIN1 9
#define BIN2 10
#define PWMB 11
#define STBY 12

static Motor motorA(AIN1, AIN2, PWMA, 1, STBY);
static Motor motorB(BIN1, BIN2, PWMB, 1, STBY);

// -------------------- Speed Variables --------------------
static int fullSpeed = 240;      // forward speed
static int turnSpeed = 190;      // slight turn speed
static int hardTurnSpeed = 230;  // hard turn

static int motorDirection = -1; // invert if needed

// Last side seen
enum LastSeen { LEFT, RIGHT, NONE };
static LastSeen lastOnTrack = NONE;

// Start/Stop flags
static bool blackLineActive = false;
static bool blackLineStopped = true;

// -------------------- Initialization --------------------
static void initBlackLine() {
    for (int i = 0; i < NUM_SENSORS; i++) pinMode(sensorPins[i], INPUT);
    pinMode(STBY, OUTPUT);
    digitalWrite(STBY, HIGH);  // enable motors
}

// -------------------- Start / Stop --------------------
static void startBlackLine() {
    blackLineActive = true;
    blackLineStopped = false;
    lastOnTrack = NONE;
}

static void stopBlackLine() {
    blackLineActive = false;
    blackLineStopped = true;
    motorA.drive(0);
    motorB.drive(0);
}

// -------------------- Motor Wrappers --------------------
static void moveForward(int speed) {
    motorA.drive(speed * motorDirection);
    motorB.drive(speed * motorDirection);
}

static void turnLeft(int speed) {
    motorA.drive((speed / 2) * motorDirection);
    motorB.drive(speed * motorDirection);
}

static void turnRight(int speed) {
    motorA.drive(speed * motorDirection);
    motorB.drive((speed / 2) * motorDirection);
}

static void spinAntiClockwise(int speed) {
    motorA.drive(speed * motorDirection);
    motorB.drive(-speed * motorDirection);
}

static void spinClockwise(int speed) {
    motorA.drive(-speed * motorDirection);
    motorB.drive(speed * motorDirection);
}

// -------------------- Line Following Step --------------------
static void blackLineStep() {
    if (!blackLineActive) return;

    int sensorValues[NUM_SENSORS];
    bool anySensorOnLine = false;

    // Read sensors
    for (int i = 0; i < NUM_SENSORS; i++) {
        sensorValues[i] = analogRead(sensorPins[i]);
        if (sensorValues[i] < threshold[i]) anySensorOnLine = true;
    }

    if (anySensorOnLine) {

        // Move forward normally
        moveForward(fullSpeed);

        // ---- FIXED MIRRORED LOGIC ----
        // RIGHT side is index 0, LEFT side is index 4
        if (sensorValues[4] < threshold[4] || sensorValues[3] < threshold[3])
            lastOnTrack = LEFT;
        else if (sensorValues[1] < threshold[1] || sensorValues[0] < threshold[0])
            lastOnTrack = RIGHT;

    } else {

        // ---- FIXED RECOVERY DIRECTION ----
        if (lastOnTrack == LEFT)
            spinClockwise(hardTurnSpeed);       // turn RIGHT to re-find
        else if (lastOnTrack == RIGHT)
            spinAntiClockwise(hardTurnSpeed);   // turn LEFT to re-find
        else
            spinClockwise(hardTurnSpeed);       // default
    }
}

#endif
