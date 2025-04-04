#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {
  if (BT.available()) {
    char c = BT.read();
    Serial.print("Received: ");
    Serial.println(c);
  }
  if (Serial.available()) {
    BT.write(Serial.read());
  }
}