/*
  prox-display.ino
  Created by Kameel Ahamed on 23.07.2019
  
  https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor
  http://www.arduino.cc/en/Tutorial/LiquidCrystalSerial
  Follow circuit diagram provided in links above
*/

#include <LiquidCrystal.h>

// define lcd pins for library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pingPin = 7; // trig pin
const int echoPin = 6; // echo pin

long duration, inches, cm;

void setup(){
  // setup pins, start display
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16, 2); 
}

void loop() {
   // scan
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   // calculate distance
   duration = pulseIn(echoPin, HIGH);
   inches = duration / 74 / 2;
   cm = duration / 29 / 2;
   // print
   lcd.print(inches);
   lcd.print("in, ");
   lcd.print(cm);
   lcd.print("cm");
   delay(600);
   // clear display for new input
   lcd.clear();
}
