#define PIR_PIN 2
#define BUZZER 8

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    Serial.println("Motion Detected!");
    digitalWrite(BUZZER, HIGH);
    delay(2000);
    digitalWrite(BUZZER, LOW);
  }
}
//Description: Detects motion using a PIR sensor and activates a buzzer alarm.