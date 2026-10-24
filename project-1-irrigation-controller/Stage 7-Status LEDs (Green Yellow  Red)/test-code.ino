const int g = 6, y = 8, r = 9;
void setup() { pinMode(g, OUTPUT); pinMode(y, OUTPUT); pinMode(r, OUTPUT); }
void loop() {
digitalWrite(g, HIGH); delay(300); digitalWrite(g, LOW);
digitalWrite(y, HIGH); delay(300); digitalWrite(y, LOW);
digitalWrite(r, HIGH); delay(300); digitalWrite(r, LOW);
}
