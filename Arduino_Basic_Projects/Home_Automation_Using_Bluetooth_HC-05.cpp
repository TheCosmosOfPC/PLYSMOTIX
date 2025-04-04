#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX (connect to HC-05 module)

int relayPin = 8;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    if (command == '1') {
      digitalWrite(relayPin, HIGH);
      Serial.println("Light ON");
    } else if (command == '0') {
      digitalWrite(relayPin, LOW);
      Serial.println("Light OFF");
    }
  }
}
//Description: This project allows you to turn a light ON/OFF using Bluetooth commands sent from a mobile app.

