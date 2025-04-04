// Controls the speed and direction of a DC motor using L298N

int enA = 9;   // PWM speed control
int in1 = 8;   // Direction control
int in2 = 7;   // Direction control

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // Move motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150); // Set speed (0-255)
  delay(3000);

  // Stop motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(2000);

  // Move motor backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);
  delay(3000);
}