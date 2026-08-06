#include <Servo.h>
const int trigPin= 9, echoPin= 10;
const int ledGreen= 5, ledYellow= 6, ledRed= 7, buzzerPin=8;

Servo barrier;

unsigned long lastBeep = 0;
unsigned long parkedSince = 0;
bool inParkRange = false;
bool barrierOpen = false;

long getDistanceCm(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 3000);
  return duration*0.0343 / 2;
}
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledGreen, OUTPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledRed, OUTPUT);
pinMode(buzzerPin,OUTPUT);
barrier.attach(11);
barrier.write(0);
Serial.begin(9600);  

}

void loop() {
  long d = getDistanceCm();
  Serial.print("Distance ");
  Serial.println(d);

  digitalWrite(ledGreen, d > 30);
  digitalWrite(ledYellow, d <= 30 && d > 15);
  digitalWrite(ledRed, d <= 15);

  if (d <= 30 && d > 0){
    int beepInterval = map(constrain(d, 5, 30), 5, 30, 80, 500);
    if(millis() - lastBeep > beepInterval){
      lastBeep = millis();
      tone(buzzerPin, 1000, 50);
    }
  }
bool nowInRange = (d > 8 && d <= 15);
if (nowInRange && !inParkRange) parkedSince = millis();
inParkRange = nowInRange;

if (inParkRange && millis() - parkedSince > 3000 && !barrierOpen){
  barrier.write(90);
  barrierOpen = true;
}
else if (!inParkRange && barrierOpen){
  barrier.write(0);
  barrierOpen = false;
}
delay(100);
}
