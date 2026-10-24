void setup() { Serial.begin(9600); }
void loop() {
Serial.print("Water level: "); Serial.println(analogRead(A2));
delay(500);
}
