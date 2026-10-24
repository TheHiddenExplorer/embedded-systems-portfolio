#include <IRremote.hpp>
void setup() { Serial.begin(9600); IrReceiver.begin(11); }
void loop() {
if (IrReceiver.decode()) {
Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
IrReceiver.resume();
}
}
