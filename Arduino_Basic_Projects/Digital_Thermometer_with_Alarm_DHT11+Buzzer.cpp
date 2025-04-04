#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define BUZZER 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  Serial.print("Temperature: ");
  Serial.println(temp);

  if (temp > 30) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
//Description: This project measures temperature and activates a buzzer if the temperature exceeds a set limit.

