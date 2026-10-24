const int enA=9, in1=8, in2=7, enB=6, in3=5, in4=4;
void setup() {
pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
pinMode(enB, OUTPUT); pinMode(in3, OUTPUT); pinMode(in4, OUTPUT);
}
void loop() {
digitalWrite(in1, HIGH); digitalWrite(in2, LOW); digitalWrite(enA, HIGH);
digitalWrite(in3, HIGH); digitalWrite(in4, LOW); digitalWrite(enB, HIGH);
delay(1000);
digitalWrite(enA, LOW); digitalWrite(enB, LOW);
delay(1000);
}
