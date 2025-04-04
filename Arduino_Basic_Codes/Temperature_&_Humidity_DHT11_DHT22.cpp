#include <DHT.h>

#define DHTPIN 2       // Pin where DHT sensor is connected
#define DHTTYPE DHT11  // Change to DHT22 if using DHT22 sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();  // Read temperature in Celsius
  float hum = dht.readHumidity();      // Read humidity

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  delay(2000); // Wait 2 seconds before next reading
}