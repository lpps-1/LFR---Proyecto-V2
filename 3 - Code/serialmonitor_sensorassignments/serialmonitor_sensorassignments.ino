#include <Arduino.h>

// -------------------- Sensor Pins --------------------
#define NUM_SENSORS 5
int sensorPins[NUM_SENSORS] = {A6, A3, A2, A1, A0}; // L2, L1, C, R1, R2

// Thresholds
int threshold[NUM_SENSORS] = {643, 642, 642, 642, 642};

// Sensor names
const char* sensorNames[NUM_SENSORS] = {"L2", "L1", "C", "R1", "R2"};

void setup() {
  Serial.begin(9600);

  // Initialize sensor pins as input
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(sensorPins[i], INPUT);
  }

  Serial.println("Sensor debug started...");
}

void loop() {
  bool sensorStates[NUM_SENSORS];

  // Read sensors
  for (int i = 0; i < NUM_SENSORS; i++) {
    int val = analogRead(sensorPins[i]);
    sensorStates[i] = val < threshold[i];  // LOW value = line detected
  }

  // Print active sensors
  Serial.print("Sensors on line: ");
  bool any = false;
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (sensorStates[i]) {
      Serial.print(sensorNames[i]);
      Serial.print(" ");
      any = true;
    }
  }
  if (!any) Serial.print("None");

  Serial.println();

  delay(200); // update every 200ms
}
