#include <Servo.h>
ServoblindServo;
void setup() { blindServo.attach(9); }
void loop() {
blindServo.write(0); delay(1000);
blindServo.write(90); delay(1000);
}
