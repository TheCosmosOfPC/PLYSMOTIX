// Fades an LED in and out using PWM

int ledPin = 9; // PWM pin for LED

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness); // Increase brightness
    delay(10);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness); // Decrease brightness
    delay(10);
  }
}