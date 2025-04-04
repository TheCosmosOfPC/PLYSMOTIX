int gasPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int gasValue = analogRead(gasPin);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > 600) { // Adjust threshold based on calibration
    Serial.println("Warning! High Gas Level Detected!");
  }

  delay(1000);
}