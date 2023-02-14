/*
This is a code for NYCU sem 2 EElab 06 exp 6
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/

#define LED 9
// set the state for change up or down count 
short int state = 0;
// set count step 
short int step = 10;
void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    analogWrite(LED, state);
    state += step;

    // when state at 100 or 0 inv the step 
    if (state == 100 || state == 0) {
        step = -step;
    }
    delay(50);
}
