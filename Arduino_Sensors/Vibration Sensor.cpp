#define VIBRATION_PIN 3

void setup() {
  pinMode(VIBRATION_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(VIBRATION_PIN) == HIGH) {
    Serial.println("Vibration Detected!");
  }
  delay(500);
}
//Description: Detects vibration/shock using a vibration sensor.

