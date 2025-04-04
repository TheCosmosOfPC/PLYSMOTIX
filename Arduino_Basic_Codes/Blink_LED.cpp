// Turns an LED on and off at 1-second intervals

int ledPin = 13; // Pin connected to LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(1000); // Wait 1 second
  digitalWrite(ledPin, LOW); // Turn LED off
  delay(1000); // Wait 1 second
}
