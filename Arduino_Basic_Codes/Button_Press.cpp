// LED turns on when button is pressed

int buttonPin = 2; // Button input pin
int ledPin = 13;   // LED output pin

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // Button pressed (LOW due to pull-up)
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}