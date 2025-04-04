#include <Servo.h>

Servo myServo;  // Create servo object
int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(0);   // Move to 0 degrees
  delay(1000);
  myServo.write(90);  // Move to 90 degrees
  delay(1000);
  myServo.write(180); // Move to 180 degrees
  delay(1000);
}