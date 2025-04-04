int red = 2, yellow = 3, green = 4;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);

  digitalWrite(yellow, HIGH);
  delay(2000);
  digitalWrite(yellow, LOW);

  digitalWrite(red, HIGH);
  delay(5000);
  digitalWrite(red, LOW);
}
//Description: Simulates a traffic light system with red, yellow, and green LEDs.

