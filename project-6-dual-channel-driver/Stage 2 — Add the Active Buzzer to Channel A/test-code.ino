const int enA=9, in1=8, in2=7;
void setup() { pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT); }
void loop() {
digitalWrite(in1, HIGH); digitalWrite(in2, LOW); digitalWrite(enA, HIGH);
delay(500);
digitalWrite(enA, LOW);
delay(500);
}
