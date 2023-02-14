/*
This is a code for NYCU sem 2 EElab 06 exp 2
Written By Keith Lin (KYLiN)
Date : 2022 / 3 / 30
*/

const int MAX_SIZE = 400; // ex2 
int data[MAX_SIZE] = {};
void setup() {
    Serial.begin(9600);
    // if in ex2 -4 open this 
    // connect pin 3 to ARF
    analogReference(EXTERNAL);//配置用于模拟输入的参考电压
    // ref -> : https://www.w3cschool.cn/arduino/arduino_advanced_io_function.html
}

static int cnt = 0, fnt = 0;
void loop() {

    // only if cnt < MAX_SIZE can run
    if (cnt < MAX_SIZE) {
        for (cnt = 0; cnt < MAX_SIZE; cnt++) { // get data
            data[cnt] = analogRead(A0);
        }

        for (auto& i : data) { // print data 
            Serial.println(i);
        }
        Serial.println("finish!!!"); // end prog 

    }
}
