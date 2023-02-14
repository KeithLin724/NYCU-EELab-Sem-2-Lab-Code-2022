/*
This is a code for NYCU EELab 09 exp2 code
Written by Keith Lin (KYLiN)
Date : 2022/3/1 
*/

#include <SPI.h> // ather comulation

void setup() {
    Serial.begin(115200);
    
    digitalWrite(SS, HIGH);
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV128);
}

void loop() {
    char c;
    digitalWrite(SS, LOW);
    // send the test string 
    String str("kw");

    for (auto& i : str) {
        SPI.transfer(i);
        Serial.print(i);
    }

    digitalWrite(SS, HIGH);
    delay(2000);

}
