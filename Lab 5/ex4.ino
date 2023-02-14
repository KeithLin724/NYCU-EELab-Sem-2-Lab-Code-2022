/*
Here is a code of EELab Lab 05 exp4 
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
// id number
const int id_number[] = { 1,0,9,5,1,1,2,7,6 };
volatile int state_number = 8;

volatile bool open_run = false;

void count() {
    if (open_run) {
        state_number++;
        if (state_number > 8) {
            state_number = 0;
        }
    }
    else {
        state_i++;
        if (state_i > 5) {
            state_i = 0;
        }
    }
}

void setup() {
    pinMode(Button, INPUT);
    Timer1.initialize(500000);
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
            open_run = true;
        }

    }
    else if (currentState == LOW && open_run == true) {
        open_run = false;
        state_number = 0;
    }

    // save the the last state
    lastState = currentState;
    if (open_run) {
        seg.setNumber(id_number[state_number]);
    }
    else {
        display_seg_pos(state_i);
    }

}
