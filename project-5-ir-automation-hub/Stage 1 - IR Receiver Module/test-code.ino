#include <IRremote.hpp>
void setup() {
Serial.begin(9600);
IrReceiver.begin(11);
Serial.println("IRreceiverready.");
}
void loop() {
if (IrReceiver.decode()) {
Serial.println("Signalreceived(moduleis working)");
IrReceiver.resume();
}
}
