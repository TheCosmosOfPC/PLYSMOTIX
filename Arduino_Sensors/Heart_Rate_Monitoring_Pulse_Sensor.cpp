#define PULSE_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int pulseValue = analogRead(PULSE_PIN);
  Serial.print("Heart Rate: ");
  Serial.println(pulseValue);
  delay(1000);
}
//Description: Measures heart rate using a pulse sensor.