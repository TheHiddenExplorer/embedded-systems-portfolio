void setup() { pinMode(5, OUTPUT); pinMode(6, OUTPUT); pinMode(9, OUTPUT); }
void loop() {
digitalWrite(5, HIGH); digitalWrite(6, LOW); digitalWrite(9, LOW); delay(500); // red
digitalWrite(5, LOW); digitalWrite(6, HIGH); digitalWrite(9, LOW); delay(500); // green
digitalWrite(5, LOW); digitalWrite(6, LOW); digitalWrite(9, HIGH); delay(500); // blue
}
