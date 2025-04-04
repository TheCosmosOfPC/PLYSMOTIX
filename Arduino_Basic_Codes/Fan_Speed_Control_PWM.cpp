int fanPin = 9;    // Fan connected to PWM pin
int potPin = A0;   // Potentiometer input

void setup() {
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int speed = analogRead(potPin) / 4; // Convert 0-1023 to 0-255
  analogWrite(fanPin, speed); // Control fan speed
  Serial.print("Fan Speed: ");
  Serial.println(speed);
  delay(100);
}