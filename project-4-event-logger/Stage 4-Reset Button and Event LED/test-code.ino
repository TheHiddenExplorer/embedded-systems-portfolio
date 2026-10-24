void setup() { pinMode(9, INPUT_PULLUP); pinMode(10, OUTPUT); }
void loop() {
digitalWrite(10, digitalRead(9) == LOW);
}
