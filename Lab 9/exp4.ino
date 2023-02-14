/*
This is a code for NYCU EELab 09 exp4 code
Written by Keith Lin (KYLiN)
Date : 2022/3/1 
*/

#include <SegmentDisplay.h>

SegmentDisplay seg(6, 7, 8, 9, 10, 11, 12, 13); // 2, 3, 4, 5, 6, 7, 8, 9

int pin_dis[] = { 5,4 };
void setup() {
    Serial.begin(9600);
    Serial.println("Hello world");
    pinMode(pin_dis[0], OUTPUT);
    pinMode(pin_dis[1], OUTPUT);
}
// print 20 

void passive_pin(boolean f_s) {
    digitalWrite(pin_dis[0], f_s);
    digitalWrite(pin_dis[1], !f_s);
}

void clr_dis() {
    digitalWrite(pin_dis[0], LOW);
    digitalWrite(pin_dis[1], LOW);
}

boolean state = LOW;
void loop() {

    clr_dis();
    seg.displayHex(2, false);
    state = !state;
    passive_pin(state);
    delay(10);

    clr_dis();
    seg.displayHex(0, false);
    state = !state;
    passive_pin(state);
    delay(10);
}