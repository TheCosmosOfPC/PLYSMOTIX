int ldrPin = A0;
int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.println(lightValue);

  if (lightValue < 500) {  // Adjust threshold as needed
    digitalWrite(ledPin, HIGH); // Turn LED on if dark
  } else {
    digitalWrite(ledPin, LOW); // Turn off if bright
  }

  delay(500);
}