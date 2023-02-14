/*
This is a code for NYCU EELab 09 bonus1 code
Written by Keith Lin (KYLiN)
Date : 2022/2/28 
*/

#include <TimerOne.h>
#include <SegmentDisplay.h>

SegmentDisplay seg(6, 7, 8, 9, 10, 11, 12, 13); // segment display setup

//timer setup
volatile int time_c = 0; // counter number
volatile boolean UP_DOWN = true; // up_down counter 
//connect pin 
int pin_dis[] = { 5,4 };

void count_time() {
    if (UP_DOWN) { // upper count
        time_c++;
        if (time_c > 59) {
            time_c = 0;
        }
    }
    else { // down count
        time_c--;
        if (time_c < 0) {
            time_c = 59;
        }
    }
}

void button_p() {
    UP_DOWN = !UP_DOWN;
}

void setup() { // main setup function
    pinMode(pin_dis[0], OUTPUT);
    pinMode(pin_dis[1], OUTPUT);
    pinMode(2, INPUT);

    Timer1.initialize();// 1000000 us // Theard
    Timer1.attachInterrupt(count_time);
    attachInterrupt(0, button_p, RISING);
}

void passive_pin(boolean f_s) {
    digitalWrite(pin_dis[0], f_s);
    digitalWrite(pin_dis[1], !f_s);
}

void clr_dis() { // clear display function 
    digitalWrite(pin_dis[0], LOW);
    digitalWrite(pin_dis[1], LOW);
}

void dis_ss() { // display Loop
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

void loop() { // main loop
    dis_ss();
}