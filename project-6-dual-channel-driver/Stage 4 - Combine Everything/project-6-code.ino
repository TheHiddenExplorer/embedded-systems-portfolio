const int enA = 9, in1 = 8, in2 = 7; 
const int enB = 6, in3 = 5, in4 = 4;

void alarmOn(){ 
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW); 
  digitalWrite(enA, HIGH); 
}

void alarmOff(){ 
  digitalWrite(enA, LOW); 
}

void indicatorOn(){ 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW); 
  digitalWrite(enB, HIGH); 
}

void indicatorOff(){
  digitalWrite(enB, LOW); 
}

void setup(){
  pinMode(enA, OUTPUT); 
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Alarm only");
  alarmOn(); 
  indicatorOff(); 
  delay(2000);

  Serial.println("Indicator only");
  alarmOff(); 
  indicatorOn(); 
  delay(2000);

  Serial.println("Both ON");
  alarmOn(); 
  indicatorOn(); 
  delay(2000);

  Serial.println("Both OFF");
  alarmOff(); 
  indicatorOff(); 
  delay(2000);
}
