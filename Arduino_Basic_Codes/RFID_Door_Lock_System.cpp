#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

byte authorizedUID[] = {0x12, 0x34, 0x56, 0x78}; // Replace with your card UID
int lockPin = 8; // Lock relay pin

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(lockPin, OUTPUT);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  Serial.print("UID: ");
  boolean accessGranted = true;
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    if (rfid.uid.uidByte[i] != authorizedUID[i]) accessGranted = false;
  }
  Serial.println();

  if (accessGranted) {
    Serial.println("Access Granted!");
    digitalWrite(lockPin, HIGH);
    delay(5000); // Keep lock open for 5 seconds
    digitalWrite(lockPin, LOW);
  } else {
    Serial.println("Access Denied!");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}