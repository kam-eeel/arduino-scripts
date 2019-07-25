/*
  prox-display.ino
  Created by Kameel Ahamed on 23.07.2019
  
  https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor
  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerial
  https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
  Follow circuit diagram provided in links above
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // digital pins

const int pingPin = 7; // trig pin - digital
const int echoPin = 6; // echo pin - digital

const int tempPin = 0; // temperature sensor ! must be analog A0

const int fanPin = 8; // digital

void proximity();
float temperature();
void display(float, char);
void fanControlTemp();

void setup(){
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tempPin, INPUT);
  lcd.begin(16, 2); 
}

void loop() {
  // proximity();
  // temperature();
  // fanControlTemp();
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
  float cmF = cm;
  char m[3] = "cm";
  display(cmF, m[3]);
}

float temperature(){
  int read = analogRead(tempPin);
  float voltage = read * 5.0;
  voltage /= 1024.0;
  float temp = (voltage - 0.5) * 100;
  char c[10] = "degrees C";
  display(temp, c);
  return temp;
}

void display(float value, char unit){
  lcd.write(value);
  lcd.write(" ", unit);
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