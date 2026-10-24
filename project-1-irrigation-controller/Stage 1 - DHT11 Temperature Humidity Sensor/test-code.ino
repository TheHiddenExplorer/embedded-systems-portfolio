#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
Serial.begin(9600);
dht.begin();
}
void loop() {
float t = dht.readTemperature();
float h = dht.readHumidity();
Serial.print("Temp: "); Serial.print(t);
Serial.print(" C Humidity: "); Serial.print(h); Serial.println(" %");
delay(1000);
}
