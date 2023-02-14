/*
This is a code for NYCU EElab sem 2 Lab 06 bonus 2
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/

#define LED 13
boolean state = HIGH;
//ref :-> https://www.youtube.com/watch?v=DH_h28XHz8U
void setup() { // set the LED pin mode 
    pinMode(LED, OUTPUT);
}

// for loop setup
int a = 0;
float step = 0.01, b = 0;

void loop() {

    // let the period do two time 
    for (a; a < 1; a++) {
        digitalWrite(LED, HIGH);
        delayMicroseconds(b * 1000.0);
        digitalWrite(LED, LOW);
        delayMicroseconds(1000.0 * (10 - b));

    }
    // change the step and init the a value 
    a = 0;
    b += step;

    // over up MAX or lower MIN then change the step 
    if (b > 10 || b < 0) {
        step = -step;
    }
}
