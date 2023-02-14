/*
This is a code for NYCU EELab 09 bonus2 code
Written by Keith Lin (KYLiN)
Date : 2022/2/28 
*/

#include <TimerOne.h>
#include <SegmentDisplay.h>

// constants won't change. They're used here to set pin numbers:
const int BUTTON_PIN = 2; // the number of the pushbutton pin
const int SHORT_PRESS_TIME = 1000; // 1000 milliseconds
const int LONG_PRESS_TIME = 5000; // 5000 milliseconds

// Variables will change:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin
unsigned long pressedTime = 0;
unsigned long releasedTime = 0;
/////////
int time_c = 0;
bool run_time = true;


////////seven segment display 
SegmentDisplay seg(6, 7, 8, 9, 10, 11, 12, 13);
//////// Display data 
int pin_dis[] = { 5,4 };
///////////////////

void passive_pin(boolean f_s) {
    digitalWrite(pin_dis[0], f_s);
    digitalWrite(pin_dis[1], !f_s);
}

void clr_dis() {
    digitalWrite(pin_dis[0], LOW);
    digitalWrite(pin_dis[1], LOW);
}

void count_time() {
    if (run_time == true) {
        // count time 
        time_c++;
        if (time_c > 59) { // reset to zero 
            time_c = 0;
        }
    }
}

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP); // button 
    // switch 
    pinMode(pin_dis[0], OUTPUT);
    pinMode(pin_dis[1], OUTPUT);

    Timer1.initialize(); // 1000000 us 
    Timer1.attachInterrupt(count_time); // Therad for count time 
    Serial.println("test >>>"); // debug
}

void display_ss_time() { // display time 
    int F_S[] = { time_c / 10 , time_c % 10 };
    boolean state = LOW;
    for (int i = 0; i < 2; i++) {
        clr_dis();
        seg.displayHex(F_S[i], false);
        state = !state;
        passive_pin(state);
        delay(10);
    }
}

void loop() {
    // read the state of the switch/button:
    currentState = digitalRead(BUTTON_PIN);

    if (lastState == HIGH && currentState == LOW) { // button is pressed
        pressedTime = millis();
    }
    else if (lastState == LOW && currentState == HIGH) { // button is released
        releasedTime = millis();

        long pressDuration = releasedTime - pressedTime;

        if (pressDuration < SHORT_PRESS_TIME) {
            run_time = !run_time;
            Serial.println("A short press is detected");
        }

        if (pressDuration > LONG_PRESS_TIME) {
            time_c = 0;
            Serial.println("A long press is detected");
        }
    }

    // save the the last state
    lastState = currentState;

    display_ss_time();
}

