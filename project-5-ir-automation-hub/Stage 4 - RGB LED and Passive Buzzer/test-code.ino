void setup() { pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(3, OUTPUT); }
void loop() {
digitalWrite(5, HIGH); digitalWrite(6, LOW); digitalWrite(3, HIGH); //purple moodlight
tone(10, 1000); delay(300); noTone(10); delay(700);
}
