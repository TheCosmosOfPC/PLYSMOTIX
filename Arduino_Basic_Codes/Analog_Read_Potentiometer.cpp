// Reads a potentiometer value and prints it

int potPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(potPin);
  Serial.println(value);
  delay(500);
}