#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);
int relayPin = 5; // GPIO5 (D1 on NodeMCU)

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("WiFi Connected!");
  server.begin();
  pinMode(relayPin, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/ON") != -1) {
      digitalWrite(relayPin, HIGH);
      Serial.println("Relay ON");
    } else if (request.indexOf("/OFF") != -1) {
      digitalWrite(relayPin, LOW);
      Serial.println("Relay OFF");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<h1>Smart Home Relay</h1>");
    client.stop();
  }
}