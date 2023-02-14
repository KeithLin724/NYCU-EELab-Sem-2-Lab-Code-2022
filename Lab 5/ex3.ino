/*
Here is a code of EELab Lab 05 exp3
Written  BY Keith Lin (KYLiN)
Date : 2022 / 3 /22 
*/

#include <AdvancedSevenSegment.h>
#include <TimerOne.h>
//setup
AdvanceSevenSegment seg(4, 5, 8, 9, 10, 6, 7, 13); // seven segment

#define Button 2
const int SHORT_PRESS_TIME = 500; // 500 milliseconds
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;

volatile int state_i = 5;
bool open_zero = false;

void count() {
    state_i++;
    if (state_i > 5) {
        state_i = 0;
    }
}

void display_seg_pos(int pos) {
    switch (pos) {
    case 0:
        seg.print(0, 1, 0, 0, 0, 0, 0);
        break;
    case 1:
        seg.print(0, 0, 1, 0, 0, 0, 0);
        break;
    case 2:
        seg.print(0, 0, 0, 1, 0, 0, 0);
        break;
    case 3:
        seg.print(0, 0, 0, 0, 1, 0, 0);
        break;
    case 4:
        seg.print(0, 0, 0, 0, 0, 1, 0);
        break;
    case 5:
        seg.print(1, 0, 0, 0, 0, 0, 0);
        break;
    default:
        break;
    }

}


void setup() {
    pinMode(Button, INPUT);
    Timer1.initialize(500000); // 0.5s
    Timer1.attachInterrupt(count);

}

void loop() {
    // read the state of the switch/button:
    currentState = digitalRead(Button);

    if (lastState == HIGH && currentState == LOW) {// button is pressed
        pressedTime = millis();

    }
    else if (lastState == LOW && currentState == HIGH) { // button is released
        releasedTime = millis();

        long pressDuration = releasedTime - pressedTime;

        if (pressDuration > SHORT_PRESS_TIME) {
            open_zero = true;
        }
    }
    else if (currentState == LOW && open_zero == true) {
        open_zero = false;
    }

    // save the the last state
    lastState = currentState;
    if (open_zero) {
        seg.setNumber(0);
        delay(500);

    }
    else {

        display_seg_pos(state_i);
    }
}
