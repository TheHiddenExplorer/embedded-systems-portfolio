void setup() { Serial.begin(9600); }
void loop() {
Serial.print("Threshold pot: "); Serial.println(analogRead(A3));
delay(300);
}
