#define MQ135_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int airQuality = analogRead(MQ135_PIN);
  Serial.print("Air Quality: ");
  Serial.println(airQuality);

  if (airQuality > 400) {
    Serial.println("⚠️ Poor Air Quality!");
  }
  
  delay(2000);
}
//Description: Detects air pollution levels using an MQ-135 sensor.