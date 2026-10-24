void setup() { Serial.begin(9600); }
void loop() {
int reading = analogRead(A0);
Serial.print("Thermistor raw value: "); Serial.println(reading);
delay(500);
}
