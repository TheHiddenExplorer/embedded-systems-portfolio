void setup() { pinMode(2, INPUT); Serial.begin(9600); }
void loop() {
if (digitalRead(2) == LOW) Serial.println("Clap detected");
delay(50);
}
