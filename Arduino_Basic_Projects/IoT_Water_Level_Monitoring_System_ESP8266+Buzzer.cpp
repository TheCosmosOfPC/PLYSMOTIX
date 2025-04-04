#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

int sensorPin = A0;
int buzzer = D1;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int level = analogRead(sensorPin);
  Serial.print("Water Level: ");
  Serial.println(level);

  if (level > 800) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(2000);
}
//Description: Detects water level and alerts using a buzzer.

