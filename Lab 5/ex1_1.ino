/*
Here is a code of EELab Lab 05 exp1
Written  BY Keith Lin (KYLiN)
Date : 2022 / 3 /22 
*/

int LED = 13;
boolean state = true;

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
    digitalWrite(LED, state);
    delay(1000);
    state = !state;
}
