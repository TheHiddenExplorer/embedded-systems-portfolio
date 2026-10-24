#include <Keypad.h>
const byteROWS = 4, COLS = 4;
char keys[ROWS][COLS] = {
{'1','2','3','A'}, {'4','5','6','B'},
{'7','8','9','C'}, {'*','0','#','D'}
};
byterowPins[ROWS] = {2, 3, 4, 5};
bytecolPins[COLS] = {6, 7, 8, A0};
Keypadkeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() { Serial.begin(9600); }
void loop() {
char k = keypad.getKey();
if (k) { Serial.print("Keypressed:"); Serial.println(k); }
}
