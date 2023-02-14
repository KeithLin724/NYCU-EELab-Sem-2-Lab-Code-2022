/*
This is a code for NYCU EELab 09 bonus1_update code
Written by Keith Lin (KYLiN)
Date : 2022/4/30
*/

#include <TimerOne.h>
#include <SegmentDisplay.h>

#define Pin 2 // for Interrupt 

SegmentDisplay seg(6, 7, 8, 9, 10, 11, 12, 13); // 2, 3, 4, 5, 6, 7, 8, 9

volatile int time_c = 0;
int pin_dis[] = { 5,4 };
volatile boolean UP_DOWN = true;

void count_time() { // count time 
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
    static uint64_t last_interrupt_time = 0;
    uint64_t interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 200) { //debouncing function 
        UP_DOWN = !UP_DOWN;
    }
    last_interrupt_time = interrupt_time;
}

void setup() {
    pinMode(pin_dis[0], OUTPUT);
    pinMode(pin_dis[1], OUTPUT);
    pinMode(Pin, INPUT_PULLUP); // using input pull up in pin 2 

    Timer1.initialize();// 1000000 us // like Theard
    Timer1.attachInterrupt(count_time);
    attachInterrupt(digitalPinToInterrupt(Pin), button_p, FALLING);
}

void passive_pin(boolean f_s) {
    digitalWrite(pin_dis[0], f_s);
    digitalWrite(pin_dis[1], !f_s);
}

void clr_dis() { //clear ss display 
    digitalWrite(pin_dis[0], LOW);
    digitalWrite(pin_dis[1], LOW);
}

void dis_ss() { // display function 
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
    dis_ss();
}