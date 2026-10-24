#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
void setup() { lcd.begin(16, 2); lcd.print("Logger Ready"); }
void loop() {}
