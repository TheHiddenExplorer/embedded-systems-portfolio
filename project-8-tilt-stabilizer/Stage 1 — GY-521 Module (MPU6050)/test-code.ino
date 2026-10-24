#include <Wire.h>
#include <MPU6050.h>
MPU6050mpu;
void setup() {
Serial.begin(9600);
Wire.begin();
mpu.initialize();
Serial.println(mpu.testConnection() ? "MPU6050connected" : "MPU6050NOTfound");
}
void loop() {
int16_t ax, ay, az, gx, gy, gz;
mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
Serial.print("AX:"); Serial.print(ax);
Serial.print("AY:"); Serial.print(ay);
Serial.print("AZ:"); Serial.println(az);
delay(200);
}
