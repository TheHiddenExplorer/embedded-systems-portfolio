void setup() { Serial.begin(9600); }
void loop() {
Serial.print("Light level: "); Serial.println(analogRead(A1));
delay(500);
}
