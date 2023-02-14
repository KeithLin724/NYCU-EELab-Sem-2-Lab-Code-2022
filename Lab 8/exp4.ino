/*
This is a code for EELab sem 2 Lab 08 code 
Written by Keith Lin 
Date : 2022 / 4 /27 
*/

#include <HCSR04.h>

#define tri 13
#define echo 12
#define Pin 2

UltraSonicDistanceSensor dis_ser(tri, echo);

void output_serial() {

    static uint64_t last_interrupt_time = 0;
    uint64_t interrupt_time = millis();

    if (interrupt_time - last_interrupt_time > 200) {
        auto dis_get = dis_ser.measureDistanceCm();
        Serial.println("Distance: " + String(dis_get) + " cm");
    }
    last_interrupt_time = interrupt_time;

}

void setup() {

    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(Pin), output_serial, RISING);
    pinMode(Pin, INPUT_PULLUP);
    
}

void loop() {

}
