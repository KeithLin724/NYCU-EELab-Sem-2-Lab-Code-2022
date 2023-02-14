/*
This is a code for NYCU sem 2 EElab 06 exp 4.2
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/

const int MAX_SIZE = 200;
int data[MAX_SIZE] = {};
int out[MAX_SIZE] = {};


void setup() {
    Serial.begin(9600);
}

void loop() {
    //read data 
    for (static int cnt = 1; cnt <= MAX_SIZE; cnt++) {
        data[cnt] = analogRead(A0);
    }

    //filter and save data 
    for (static int fcnt = 1; fcnt <= MAX_SIZE; fcnt++) {
        // get range and save data 
        if (3 <= fcnt <= (MAX_SIZE - 2)) {
            out[fcnt] = data[fcnt - 2] + data[fcnt - 1] + data[fcnt]
                + data[fcnt + 1] + data[fcnt + 2];
            out[fcnt] /= 5;

        }
    }

    // print data 
    for (static int fcnt = 3; fcnt <= (MAX_SIZE - 2); fcnt++) {
        Serial.println(out[fcnt]);
    }
}
