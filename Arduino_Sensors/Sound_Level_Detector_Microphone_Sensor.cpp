#define MIC_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int soundLevel = analogRead(MIC_PIN);
  Serial.print("Sound Level: ");
  Serial.println(soundLevel);

  if (soundLevel > 600) {
    Serial.println("⚠️ Loud Sound Detected!");
  }
  
  delay(1000);
}
// Description: Detects sound levels using a microphone sensor.

