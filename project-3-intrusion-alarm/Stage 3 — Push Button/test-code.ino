void setup() { pinMode(4, INPUT_PULLUP); Serial.begin(9600); }
void loop() {
Serial.println(digitalRead(4) == LOW ? "Pressed" : "Released");
delay(150);
}
