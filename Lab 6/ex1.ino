/*
This is a code for NYCU sem 2 EElab 06 exp 1
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/
#define MAX_SIZE 100
int data[MAX_SIZE] = {};
void setup() {
    Serial.begin(9600);

}

//for count the data read 
static int cnt = 0;
void loop() {

    // only if cnt < MAX_SIZE can run 
    if (cnt < MAX_SIZE) {

        // get data
        for (cnt = 0; cnt < MAX_SIZE; cnt++) {
            data[cnt] = analogRead(A0);
        }

        // print data 
        for (auto& i : data) {
            Serial.println(i);
        }

        // end prog 
        Serial.println("finish!!!");
    }
}
