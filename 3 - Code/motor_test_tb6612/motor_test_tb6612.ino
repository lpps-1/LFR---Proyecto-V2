#include <SparkFun_TB6612.h>

// Motor Driver Pins (CHANGE IF YOUR WIRING IS DIFFERENT)
#define AIN1 7
#define AIN2 8
#define PWMA 5

#define BIN1 9
#define BIN2 10
#define PWMB 11

#define STBY 12

// Motor objects (last param is offset, 1 or -1 depending motor wiring direction)
Motor motorA(AIN1, AIN2, PWMA, 1, STBY);
Motor motorB(BIN1, BIN2, PWMB, 1, STBY);

void setup() {
  // Wake up motor driver
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);

  // Run forward
  motorA.drive(155);  // Speed range: -255 to 255
  motorB.drive(155);

  delay(10000); // Run for 3 seconds

  motorA.brake();
  motorB.brake();
}

void loop() {}
