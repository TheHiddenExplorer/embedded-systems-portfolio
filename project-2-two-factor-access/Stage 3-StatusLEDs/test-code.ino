void setup() { pinMode(A1, OUTPUT); pinMode(A2, OUTPUT); }
void loop() {
digitalWrite(A1, HIGH); delay(500); digitalWrite(A1, LOW);
digitalWrite(A2, HIGH); delay(500); digitalWrite(A2, LOW);
}
