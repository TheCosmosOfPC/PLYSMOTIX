#include <Stepper.h>

#define STEPS 2048  // Steps per revolution for 28BYJ-48 stepper motor
Stepper myStepper(STEPS, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(10);  // Set speed in RPM
}

void loop() {
  myStepper.step(1024); // Move forward
  delay(2000);
  myStepper.step(-1024); // Move backward
  delay(2000);
}
