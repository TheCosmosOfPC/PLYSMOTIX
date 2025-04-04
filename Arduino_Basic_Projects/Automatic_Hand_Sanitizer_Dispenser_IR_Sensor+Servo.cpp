#include <Servo.h>

int sensorPin = 2;
Servo dispenser;

void setup() {
  pinMode(sensorPin, INPUT);
  dispenser.attach(9);
  dispenser.write(0); // Initial position
}

void loop() {
  if (digitalRead(sensorPin) == LOW) {
    dispenser.write(90);
    delay(2000);
    dispenser.write(0);
  }
}
//Description: This project uses an IR sensor to detect hands and automatically dispense sanitizer using a servo motor.