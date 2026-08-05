const int soundPin = 2, ldrPin = A0, potPin = A1;
const int relayPin = 5, buttonPin = 6, ledPin = 7;

bool lightOn = false;
unsigned long lastClap = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(ldrPin);
  int threshold = map(analogRead(potPin), 0, 1023, 200, 900);
  bool isDark = lightLevel < threshold;

  bool clap = digitalRead(soundPin) == LOW;
  if(clap && millis() - lastClap > 500){
    lastClap = millis();

    if(isDark){
      lightOn = !lightOn;
      Serial.println(lightOn ? "Light ON (dark + clap)" : "Light OFF (dark + clap)");
    }else{
      Serial.println("Ignored clap - daytime");
    }
  }

  bool btn = digitalRead(buttonPin);
  if(btn == LOW && lastButton == HIGH){
    lightOn = !lightOn;
    Serial.println("Manual override toggled");
    delay(200);
  }
  lastButton = btn;

  digitalWrite(relayPin, lightOn);
  digitalWrite(ledPin, lightOn);
}
