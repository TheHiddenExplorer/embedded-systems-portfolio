#include <SPI.h>
#include <MFRC522.h>
#defineSS_PIN 10
#defineRST_PIN 9
MFRC522rfid(SS_PIN, RST_PIN);
void setup() {
Serial.begin(9600);
SPI.begin();
rfid.PCD_Init();
Serial.println("Scanacard...");
}
void loop() {
if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
Serial.print("UID:");
for (bytei = 0; i < rfid.uid.size; i++) {
Serial.print(""); Serial.print(rfid.uid.uidByte[i], HEX);
}
Serial.println();
rfid.PICC_HaltA();
}
}
