int lastClk;
long counter = 0;
void setup() {
pinMode(2, INPUT); pinMode(3, INPUT); pinMode(4, INPUT_PULLUP);
Serial.begin(9600);
lastClk = digitalRead(2);
}
void loop() {
int currentClk = digitalRead(2);
if (currentClk != lastClk) {
if (digitalRead(3) != currentClk) counter++; else counter--;
Serial.println(counter);
}
lastClk = currentClk;
if (digitalRead(4) == LOW) Serial.println("Encoderbuttonpressed");
}
