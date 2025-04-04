int PIR = 2;
int buzzer = 8;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(buzzer, HIGH);
    delay(5000);
    digitalWrite(buzzer, LOW);
  }
}
//Description: If motion is detected, a buzzer sounds an alarm.