#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";
const char* mqttServer = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("WiFi connected!");

  client.setServer(mqttServer, 1883);
  while (!client.connected()) {
    if (client.connect("ESP8266Client")) {
      Serial.println("MQTT Connected!");
      client.publish("test/topic", "Hello MQTT");
    } else {
      delay(5000);
    }
  }
}

void loop() {
  client.loop();
}