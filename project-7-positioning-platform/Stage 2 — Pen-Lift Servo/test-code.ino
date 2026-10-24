#include <Servo.h>
Servo penServo;
void setup() { penServo.attach(12); }
void loop() {
penServo.write(0); delay(1000);
penServo.write(45); delay(1000);
}
