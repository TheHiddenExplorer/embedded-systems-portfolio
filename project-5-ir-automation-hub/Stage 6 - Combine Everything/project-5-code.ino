#include <IRremote.hpp>
#include <Servo.h>

const int irPin = 11;
const int relayPin = 8;
const int buzzerPin = 10;
const int ledR = 5;
const int ledG = 6;
const int ledB = 3;

Servo blindServo;

#define CMD_POWER 0x45
#define CMD_OPEN  0x0C
#define CMD_CLOSE 0x16
#define CMD_MOOD  0x19

bool applianceOn = false;

void beep() {
    digitalWrite(buzzerPin, HIGH);
    delay(80);
    digitalWrite(buzzerPin, LOW);
}

void setup() {
  Serial.begin(9600);

  IrReceiver.begin(irPin, ENABLE_LED_FEEDBACK);

  pinMode(relayPin, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  blindServo.attach(9);
  blindServo.write(0);
}

void loop() {

  if (IrReceiver.decode()) {
    uint8_t command = IrReceiver.decodedIRData.command;

  switch (command) {

  case CMD_POWER:
    applianceOn = !applianceOn;
    digitalWrite(relayPin, applianceOn ? HIGH : LOW);
    beep();
    Serial.println("POWER");
  break;

  case CMD_OPEN:
    blindServo.write(90);
    beep();
    Serial.println("OPEN");
  break;

  case CMD_CLOSE:
    blindServo.write(0);
    beep();
    Serial.println("CLOSE");
  break;

  case CMD_MOOD:
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG, LOW);
    digitalWrite(ledB, HIGH);
    beep();
    Serial.println("MOOD");
  break;
}

    IrReceiver.resume();
  }
}
