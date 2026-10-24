#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>
#include <LiquidCrystal.h>

MPU6050 mpu;
Servo servo1;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int calibPin = A0;

float offset = 0;

void setup() {
  Wire.begin();
  mpu.initialize();
  servo1.attach(9);
  lcd.begin(16, 2);
  Serial.begin(9600);
  offset = map(analogRead(calibPin), 0, 1023, -20, 20); // one-time calibration read
}

void loop() {
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float angle = atan2((float)ay, (float)az) * 180.0 / PI;
  angle -= offset;

  static float smoothed = 0;
  smoothed = smoothed * 0.8 + angle * 0.2; // simple smoothing filter

  int servoAngle = constrain(90 - smoothed, 0, 180);
  servo1.write(servoAngle);

  lcd.setCursor(0, 0);
  lcd.print("Tilt: "); lcd.print(smoothed, 1); lcd.print(" deg   ");
  lcd.setCursor(0, 1);
  lcd.print("Servo: "); lcd.print(servoAngle); lcd.print(" deg   ");

  delay(100);
}
