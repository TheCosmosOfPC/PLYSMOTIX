#include <Adafruit_Fingerprint.h>

SoftwareSerial mySerial(2, 3); // RX, TX
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  Serial.begin(9600);
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Fingerprint sensor found!");
  } else {
    Serial.println("No sensor detected!");
    while (1);
  }
}

void loop() {
  Serial.println("Place your finger...");
  if (finger.getImage() != FINGERPRINT_OK) return;

  if (finger.image2Tz() != FINGERPRINT_OK) return;
  if (finger.fingerFastSearch() != FINGERPRINT_OK) {
    Serial.println("Fingerprint not recognized");
    return;
  }

  Serial.print("Access Granted! ID: ");
  Serial.println(finger.fingerID);
}