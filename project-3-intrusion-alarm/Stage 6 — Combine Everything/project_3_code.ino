const int pirPin = 2, tiltPin = 3, buttonPin = 4;
const int ledR = 5, ledG = 6, ledB = 9;
const int buzzerPin = 7;

enum State {DISARMED, ARMED, ALARM};
State state = DISARMED;
bool lastButton = HIGH;

void setColor(bool r, bool g, bool b){
  digitalWrite(ledR, r); digitalWrite(ledG, g); digitalWrite(ledB, b); 
}

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(tiltPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledR, OUTPUT); pinMode(ledG, OUTPUT); pinMode(ledB, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR warming up (10s)...");
  delay(10000);
  Serial.println("Ready.");
}

void loop() {
  bool btn = digitalRead(buttonPin);

  if(btn == LOW && lastButton == HIGH){
    if(state == DISARMED){
      state = ARMED;
      Serial.println("ARMED");
    }
    else{
      state = DISARMED;
      Serial.println("DISARMED");
    }
    delay(300);
  }
  lastButton = btn;

  if(state == ARMED){
    setColor(0, 1, 0);
    if(digitalRead(pirPin) == HIGH){
      state = ALARM;
      Serial.println("MOTION ALARM!");
    }
    if(digitalRead(tiltPin) == HIGH){
      state = ALARM;
      Serial.println("TAMPER ALARM!");
    }
  }else if(state == DISARMED){
    setColor(0, 0, 0);
    digitalWrite(buzzerPin, LOW);
  }else if(state == ALARM){
    setColor(1, 0, 0);
    digitalWrite(buzzerPin, (millis() / 300) % 2);
  }
}

