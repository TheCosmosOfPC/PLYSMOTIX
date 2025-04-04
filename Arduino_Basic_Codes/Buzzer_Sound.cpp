// Produces a beep sound using a buzzer

int buzzerPin = 8;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(buzzerPin, HIGH);
  delay(500); // Beep for 0.5 seconds
  digitalWrite(buzzerPin, LOW);
  delay(500); // Silence for 0.5 seconds
}
