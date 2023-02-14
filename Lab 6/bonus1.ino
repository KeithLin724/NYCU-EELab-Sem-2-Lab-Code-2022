/*
This is a code for NYCU sem 02 Lab 06 Bonus 1
Written By Keith Lin (KYLiN)
Date : 2022 /3 /30
*/

#include <ArduinoSTL.h>//make Arduino like C++ , can use STL libary 
using namespace std;

#define MAX_SIZE 200
// setup
vector<int> data;

void setup() {
    Serial.begin(9600);
    data.clear();
}

void loop() {
    static int cnt = 0, fcnt = 0; // fcnt :-> tran ex2  
    if (cnt < MAX_SIZE) {

        // Read and save data 
        for (cnt = 0; cnt < MAX_SIZE; cnt++) {
            data.push_back(analogRead(A0));
        }

        delay(100);

        int tmp = 0, p = 0;
        for (p = 0; p < 2; p++) {
            Serial.println(data[p]);
        }
        //filter the data and then output the clean data 
        for (fcnt = 2; fcnt < (MAX_SIZE - 2); fcnt++) {
            tmp = data[fcnt - 2] + data[fcnt - 1] + data[fcnt] +
                data[fcnt + 1] + data[fcnt + 2];

            tmp /= 5;

            Serial.print(tmp + String('\t'));

            Serial.println(data[p++]);
        }

        for (; p < data.size(); p++) {
            Serial.println(data[p]);
        }
    }
}
