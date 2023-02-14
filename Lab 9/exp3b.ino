/*
This is a code for NYCU EELab 09 exp3b code
Written by Keith Lin (KYLiN)
Date : 2022/3/1 
*/
#include <Wire.h>
// resive
void setup() {
    Wire.begin(8);                // join i2c bus with address #8
    Wire.onReceive(receiveEvent); // register event
    Serial.begin(9600);           // start serial for output
}

void loop() {
    delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
    while (Wire.available() > 0)
    { // loop through all but the last
        char c = Wire.read(); // receive byte as a character
        Serial.print(c);         // print the character
    }

}
