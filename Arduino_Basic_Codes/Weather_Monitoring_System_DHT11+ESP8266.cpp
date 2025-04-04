#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("WiFi Connected!");
  server.begin();
  dht.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.print("<h1>Temperature: ");
    client.print(temp);
    client.print("°C</h1>");
    client.print("<h1>Humidity: ");
    client.print(hum);
    client.print("%</h1>");
    client.stop();
  }
  delay(2000);
}
