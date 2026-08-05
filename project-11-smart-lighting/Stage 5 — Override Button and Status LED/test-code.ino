void setup() { pinMode(6, INPUT_PULLUP); pinMode(7, OUTPUT); }
void loop() {
digitalWrite(7, digitalRead(6) == LOW);
}
