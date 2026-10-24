#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int thermPin = A0;
const int ldrPin = A1;
const int waterPin = A2;
const int potPin = A3;
const int ledGreen = 6, ledYellow = 8, ledRed = 9;
const int buzzerPin = 10;
const int relayPin = 13;

void setup() {
Serial.begin(9600);
dht.begin();
lcd.begin(16, 2);
pinMode(ledGreen, OUTPUT);
pinMode(ledYellow, OUTPUT);
pinMode(ledRed, OUTPUT);
pinMode(buzzerPin, OUTPUT);
pinMode(relayPin, OUTPUT);
}

void loop() {
float temp = dht.readTemperature();
float hum = dht.readHumidity();
int light = analogRead(ldrPin); 
int water = analogRead(waterPin); 
int threshold = map(analogRead(potPin), 0, 1023, 100, 800);

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("T: "); lcd.print(temp, 1); lcd.print("CH: "); lcd.print(hum, 0); lcd.print("%");
lcd.setCursor(0, 1);
lcd.print("Light: "); lcd.print(light); lcd.print("Wtr: "); lcd.print(water);

bool lowWater = water < 150; 
bool needsWater = light > threshold && !lowWater;

digitalWrite(ledRed, lowWater);
digitalWrite(ledYellow, needsWater && !lowWater);
digitalWrite(ledGreen, !needsWater && !lowWater);
digitalWrite(buzzerPin, lowWater);
digitalWrite(relayPin, needsWater);

if (lowWater) Serial.println("ALERT: Low reservoir water-pump disabled.");
if (needsWater) Serial.println("Pump activated: dry + low light condition.");

delay(2000);
}
