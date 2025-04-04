#include <LiquidCrystal_I2C.h>

#define TRIG 9
#define ECHO 10

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  float speed = (duration / 2) / 29.1; // Distance in cm

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(speed);
  lcd.print(" cm/s");

  delay(500);
}
//Description: This project uses an ultrasonic sensor to measure the speed of an object moving past the sensor.

