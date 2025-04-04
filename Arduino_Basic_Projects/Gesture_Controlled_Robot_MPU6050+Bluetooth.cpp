#include <Wire.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);
#define MPU 0x68

void setup() {
  Wire.begin();
  Serial.begin(9600);
  BTSerial.begin(9600);

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  int x = Wire.read() << 8 | Wire.read();
  int y = Wire.read() << 8 | Wire.read();

  if (x > 10000) BTSerial.println("F");
  else if (x < -10000) BTSerial.println("B");
  else if (y > 10000) BTSerial.println("L");
  else if (y < -10000) BTSerial.println("R");
}
//Description: Controls a robot’s movement using hand gestures with an MPU6050 sensor.

