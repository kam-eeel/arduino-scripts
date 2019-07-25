/*
  prox-display.ino
  Created by Kameel Ahamed on 23.07.2019
  
  https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor
  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerial
  https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
  https://learn.adafruit.com/dht/using-a-dhtxx-sensor
  https://learn.adafruit.com/dht
  http://www.circuitbasics.com/how-to-set-up-the-dht11-humidity-sensor-on-an-arduino/
  Follow circuit diagram provided in links above
*/

#include <LiquidCrystal.h>
#include "DHT.h"

//#define aref_voltage 3.3
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // digital pins

const int pingPin = 7; // trig pin - digital
const int echoPin = 6; // echo pin - digital

const int tempPin = 8; // temperature sensor ! must be analog A0

const int fanPin = 9; // digital

void proximity();
float temperature();
void display(float, int);
void fanControlTemp();

DHT dht(tempPin, DHTTYPE);

void setup(){
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16, 2); 
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  proximity();
  // temperature();
  // fanControlTemp();
  // digitalWrite(fanPin, HIGH);
}

void proximity(){
  long duration, cm;
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 29 / 2;
  float cmF = cm + 0.0;
  display(cmF, 1);
}

float temperature(){
  float temp = dht.readTemperature();
  float h = dht.readHumidity();
  float hic = dht.computeHeatIndex(temp, h, false);
  display(temp, 2);
  return temp;
  // int read = analogRead(tempPin);
  // float voltage = read * 5.0;
  // voltage /= 1024.0;
  // float temp = (voltage - 0.5) * 100.0;
  // display(temp, 2);
  // return temp;
}

void display(float value, int b){
  char t[10] = "degrees C";
  char c[3] = "cm";
  lcd.print(value);
  lcd.setCursor(0, 1);
  if(b == 1){
    lcd.print(c);
  } else if(b == 2){
    lcd.print(t);
  }
  delay(600);
  lcd.clear();
}

void fanControlTemp(){
  if(temperature() > 20.0){
    digitalWrite(fanPin, HIGH);
  } else if(temperature() <= 20.0){
    digitalWrite(fanPin, LOW);
  }
}
