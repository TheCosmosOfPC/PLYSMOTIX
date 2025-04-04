#define TILT_PIN 2

void setup() {
  pinMode(TILT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(TILT_PIN) == HIGH) {
    Serial.println("Tilt Detected!");
  }
  delay(500);
}
//Description: Detects tilt movement using a tilt sensor.