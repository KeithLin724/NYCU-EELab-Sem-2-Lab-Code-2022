/*
This is a code for NYCU sem 2 EElab 06 exp 3
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/


// setup 
const int MAX_SIZE = 200;
int data[MAX_SIZE];

void setup() {
    Serial.begin(9600);
    // in ex3-3 put this 
    //analogReference(EXTERNAL);
}

static int cnt = 0;
void loop() {
    if (cnt < MAX_SIZE) {
        // save data 
        for (cnt = 0; cnt < MAX_SIZE; cnt++) {
            data[cnt] = analogRead(A0);
        }

        for (auto& i : data) {
            Serial.println(i);
        }
        // end prog
        Serial.println("Finish!!!");
    }

}