/*
This is a code for NYCU sem 2 EElab 06 exp 5
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/

#include <ArduinoSTL.h>
#define Read_t A0 // set the read pin
// set change Constant 
#define Con (5/1024.0)*100 
float tmp = 0;

void setup() {
    Serial.begin(9600);

}

void loop() {
    tmp = analogRead(Read_t);
    tmp *= Con;
    std::cout << "Temperature:  " << tmp << " degree celsius" << std::endl;
    delay(1000);
}
