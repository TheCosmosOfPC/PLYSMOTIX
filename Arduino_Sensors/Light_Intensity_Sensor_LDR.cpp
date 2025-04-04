#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  Serial.print("Light Intensity: ");
  Serial.println(lightLevel);
  delay(1000);
}
//Description: Measures ambient light intensity using an LDR (Light Dependent Resistor).

