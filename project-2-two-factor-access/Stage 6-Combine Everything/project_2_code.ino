#include <SPI.h>
#include <MFRC522.h>
#include <Keypad.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

byte authorizedUID[4] = {0xAD, 0x90, 0x1C, 0x1D};
String correctPIN = "4321";
String enteredPIN = "";

const byte ROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'}, {'4','5','6','B'},
  {'7','8','9','C'}, {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, A0};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int ledGreen = A1, ledRed = A2, buzzerPin = A3, relayPin = A4;
bool cardVerified = false;

unsigned long cardTime = 0;

void setup() {
Serial.begin(9600);
SPI.begin();
rfid.PCD_Init();
pinMode(ledGreen, OUTPUT);
pinMode(ledRed, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(relayPin, OUTPUT);
}

bool uidMatches() {
  if (rfid.uid.size != 4){
      return false;
    }
    for (byte i = 0; i < 4; i++){
      if (rfid.uid.uidByte[i] != authorizedUID[i]){
      return false;
      }
    }
return true;
}

void grantAccess() {
  digitalWrite(ledGreen, HIGH);
  digitalWrite(relayPin, HIGH);
  tone(buzzerPin, 1500, 200);
  Serial.println("ACCESS GRANTED");
  delay(3000);
  digitalWrite(ledGreen, LOW);
  digitalWrite(relayPin, LOW);
}

void denyAccess() {
  digitalWrite(ledRed, HIGH);
  tone(buzzerPin, 300, 400);
  Serial.println("ACCESS DENIED");
  delay(1000);
  digitalWrite(ledRed, LOW);
}

void loop() {
  if (!cardVerified) {
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      if (uidMatches()) {
        Serial.println("Card OK- enter PIN");
        cardVerified = true;
        cardTime = millis();
        enteredPIN = "";
      } else {
        denyAccess();
      }
      rfid.PICC_HaltA();
    }
} else {
  if (millis() - cardTime > 10000) {
    Serial.println("PIN timeout");
    cardVerified = false;
    denyAccess();
  }
  char k = keypad.getKey();
  if (k) {
    if (k == '#') {
      if (enteredPIN == correctPIN){ 
        grantAccess();
      } 
      else{
        denyAccess();
      }
      cardVerified = false;
      enteredPIN = "";
    } else if (k == '*') {
    enteredPIN = "";
    } else {
    enteredPIN += k;
    }
  }
  }
}
