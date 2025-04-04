#include <Servo.h>

#define TRIG 9
#define ECHO 10

Servo binLid;

void setup() {
  binLid.attach(6);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance < 30) {
    binLid.write(90);
    delay(3000);
    binLid.write(0);
  }
}
//Description: The trash bin lid automatically opens when a person’s hand is detected near it.