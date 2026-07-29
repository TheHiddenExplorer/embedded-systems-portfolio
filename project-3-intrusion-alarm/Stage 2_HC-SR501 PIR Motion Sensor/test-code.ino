void setup() {
pinMode(2, INPUT);
Serial.begin(9600);
Serial.println("Warming up PIR (10s)...");
delay(10000); 
Serial.println("Ready.");
}
void loop() {
if (digitalRead(2) == HIGH) Serial.println("Motion detected!");
delay(200);
}
