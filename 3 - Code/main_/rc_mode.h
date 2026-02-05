#ifndef RC_MODE_H
#define RC_MODE_H

#include <Arduino.h>
#include <SparkFun_TB6612.h>
#include <Adafruit_SSD1306.h>

// Motor pins and offsets
#define AIN1 7
#define AIN2 8
#define PWMA 5
#define BIN1 9
#define BIN2 10
#define PWMB 11
#define STBY 12

const int offsetA = 1;
const int offsetB = -1;
const int moveSpeed = 255;
const int turnSpeed = 255;

// Motors
Motor motorLeft  = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motorRight = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

// Persistent Bluetooth connection flag
bool btConnected = false;
unsigned long lastDataTime = 0;       // last time a valid command was received
const unsigned long CONNECTION_TIMEOUT = 2000; // 2 seconds without data = disconnected

// External display object from main.ino
extern Adafruit_SSD1306 display;

// ---- RC functions ----
void rcHandleInput() {
    if (Serial.available() > 0) {
        char cmd = Serial.read();
        lastDataTime = millis();
        btConnected = true;  // mark connected

        switch (cmd) {
            case 'R':   // Forward
                motorLeft.drive(moveSpeed);
                motorRight.drive(moveSpeed);
                break;
            case 'L':   // Backward
                motorLeft.drive(-moveSpeed);
                motorRight.drive(-moveSpeed);
                break;
            case 'B':   // Left turn
                motorLeft.drive(turnSpeed);
                motorRight.drive(-turnSpeed);
                break;
            case 'F':   // Right turn
                motorLeft.drive(-turnSpeed);
                motorRight.drive(turnSpeed);
                break;
            case 'S':   // Stop
            default:
                motorLeft.brake();
                motorRight.brake();
                break;
        }
    }

    // If no data for more than CONNECTION_TIMEOUT, mark disconnected
    if (millis() - lastDataTime > CONNECTION_TIMEOUT) {
        btConnected = false;
        motorLeft.brake();
        motorRight.brake();
    }
}

void rcStopMotors() {
    motorLeft.brake();
    motorRight.brake();
}

void rcDisplayStatus() {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 28);

    if (btConnected) {
        display.print("Connected to Zaid's S10");
    } else {
        display.print("Not Connected");
    }

    display.display();
}

#endif
