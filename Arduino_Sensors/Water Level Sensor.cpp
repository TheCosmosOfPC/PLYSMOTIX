#define WATER_SENSOR A0
#define BUZZER 7

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int waterLevel = analogRead(WATER_SENSOR);
  Serial.print("Water Level: ");
  Serial.println(waterLevel);

  if (waterLevel > 600) {
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
//Description: Measures water level using a water level sensor and triggers an alarm if it's too high.