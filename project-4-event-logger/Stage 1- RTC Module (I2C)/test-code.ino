#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;
void setup() {
Serial.begin(9600);
rtc.begin();
rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // run ONCE
}
void loop() {
DateTime now = rtc.now();
Serial.print(now.hour()); Serial.print(":"); Serial.print(now.minute()); Serial.print(":"); Serial
delay(1000);
}
