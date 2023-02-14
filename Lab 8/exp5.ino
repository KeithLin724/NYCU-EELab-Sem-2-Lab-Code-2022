/*
This is a code for EELab sem 2 Lab 08 code 
Written by Keith Lin 
Date : 2022 / 4 /27 
*/

#include <Melody.h>
#include <Musician.h>

//set the define about the output pin
#define PIN_BUZZER 12

Musician musician(PIN_BUZZER);

// set the melody for play 
Melody melody("f g a f c* a g c* g f");
Melody melody2("d a f e e d e f");
Melody melody3("g c f g a b  a g f g");

int melodyIndex = 0;

void setup() {
    musician.setBreath(1); //milliseconds of silence at the end of notes
    musician.setLoudnessLimit(0, 16); //Depending on your hardware
}

void loop() {
    musician.refresh();

    if (!musician.isPlaying()) {
        delay(500);
        switch (melodyIndex) {
        case 0:
            musician.setMelody(&melody);
            break;
        case 1:
            musician.setMelody(&melody2);
            break;
        case 2:
            musician.setMelody(&melody3);
            break;
        }
        musician.play();
        melodyIndex = (melodyIndex + 1) % 3;
    }
}
