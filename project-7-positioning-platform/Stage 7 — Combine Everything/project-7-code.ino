#include <Stepper.h>
#include <Servo.h>
#include <LiquidCrystal.h>

const int stepsPerRev = 2048;

Stepper myStepper(stepsPerRev, 8, 10, 9, 11);
Servo penServo;

LiquidCrystal lcd(6, 7, 13, A2, A3, A4);

const int encClk = 2, encDt = 3, encSw = 4;
const int joyX = A0, joyY = A1, joySw = 5;
const int speedPot = A5;
long position = 0;
int lastClk;
bool penDown = false;

void setup() {
  pinMode(encClk, INPUT); 
  pinMode(encDt, INPUT); 
  pinMode(encSw, INPUT_PULLUP);
  pinMode(joySw, INPUT_PULLUP);
  lastClk = digitalRead(encClk);
  penServo.attach(12);
  penServo.write(0);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
int spd = map(analogRead(speedPot), 0, 1023, 2, 15);
myStepper.setSpeed(spd);

int currentClk = digitalRead(encClk);

if (currentClk != lastClk) {
if (digitalRead(encDt) != currentClk) { myStepper.step(5); position += 5; }
else { myStepper.step(-5); position-= 5; }
}
lastClk = currentClk;

int xVal = analogRead(joyX);
if (xVal > 700) { myStepper.step(10); position += 10; }
else if (xVal < 300) { myStepper.step(-10); position-= 10; }

static bool lastEncSw = HIGH;
bool encSwNow = digitalRead(encSw);
if (encSwNow == LOW && lastEncSw == HIGH) {
penDown = !penDown;
penServo.write(penDown ? 45 : 0);
delay(200);
}
lastEncSw = encSwNow;

if (digitalRead(joySw) == LOW) {
myStepper.step(-position);
position = 0;
delay(300);
}

lcd.setCursor(0, 0);
lcd.print("Pos:"); lcd.print(position); lcd.print(" ");
lcd.setCursor(0, 1);
lcd.print("Pen:"); lcd.print(penDown ? "DOWN" : "UP ");
}
