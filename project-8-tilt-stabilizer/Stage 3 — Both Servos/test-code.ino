#include <Servo.h>
Servos1, s2;
void setup() { s1.attach(9); s2.attach(10); }
void loop() {
s1.write(45); s2.write(45); delay(1000);
s1.write(135); s2.write(135); delay(1000);
}
