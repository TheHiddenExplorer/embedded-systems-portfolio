#include <Servo.h>
Servo barrier;
void setup() { barrier.attach(11); }
void loop() {
barrier.write(0); delay(1000);
barrier.write(90); delay(1000);
}
