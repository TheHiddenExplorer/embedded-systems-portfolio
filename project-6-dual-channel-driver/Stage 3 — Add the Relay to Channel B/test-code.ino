const int enB=6, in3=5, in4=4;
void setup() { pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT); }
void loop() {
digitalWrite(in3, HIGH); digitalWrite(in4, LOW); digitalWrite(enB, HIGH);
delay(700);
digitalWrite(enB, LOW);
delay(700);
}
