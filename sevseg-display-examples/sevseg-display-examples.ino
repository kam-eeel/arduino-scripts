/*
    sevseg-display-examples.ino
    Created by Kameel Ahamed on 26.07.2019

    http://www.circuitbasics.com/arduino-7-segment-display-tutorial/
 */

#include <SevSeg.h>
SevSeg sevseg;

// for single digit displays

void countUpTimer();
void countUpTimer(){
    for (int i = 0; i < 10; i++)
    {
        sevseg.setNumber(i, i % 2);
        delay(1000);
        sevseg.refreshDisplay();
    }
}

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    countUpTimer();
}

void countUpTimer(){
    for (int i = 0; i < 10; i++){
        sevseg.setNumber(i, i % 2);
        delay(1000);
        sevseg.refreshDisplay();
    }
}

// for four digit displays

void setup(){
    byte numDigits = 4;
    byte digitPins[] = {10, 11, 12, 13};
    byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

    bool resistorsOnSegments = true;
    bool updateWithDelaysIn = true;
    byte hardwareConfig = COMMON_CATHODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    countUpTimer();
}