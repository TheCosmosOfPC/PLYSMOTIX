#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

WiFiServer server(80);
int lightPin = 5;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("WiFi Connected!");
  server.begin();
  pinMode(lightPin, OUTPUT);
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/ON") != -1) {
      digitalWrite(lightPin, HIGH);
      Serial.println("Light ON");
    } else if (request.indexOf("/OFF") != -1) {
      digitalWrite(lightPin, LOW);
      Serial.println("Light OFF");
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();
    client.println("<h1>Voice-Controlled Light</h1>");
    client.stop();
  }
}
