#include <Stepper.h>
const int stepsPerRev = 2048;
Stepper myStepper(stepsPerRev, 8, 10, 9, 11); // note the IN1,IN3,IN2,IN4 order the library expects
void setup() { myStepper.setSpeed(10); }
void loop() {
myStepper.step(stepsPerRev / 4); delay(1000); // quarter turn forward
myStepper.step(-stepsPerRev / 4); delay(1000); // quarter turn back
}
