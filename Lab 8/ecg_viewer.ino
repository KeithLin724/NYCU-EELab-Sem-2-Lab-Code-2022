/*
This is a code for EELab sem 2 Lab 08 code 
Written by Keith Lin 
Date : 2022 / 4 /27 
*/

const int MAX_SIZE = 1000;
// the setup routine runs once when you press reset:
void setup() {
    unsigned long t1, t2;
    // initialize serial communication at 115200 bits per second:
    Serial.begin(115200);
    // use external reference voltate as maximum voltage of analog input
    //analogReference(EXTERNAL);
    Serial.println("**DATA**");
    // Get t1: start time
    t1 = micros();
    for (int index = 0;index < MAX_SIZE;index++) {
        // read the input on analog pin 0
        print_with_leading_zero(analogRead(A0));
    }
    // Get t2: end time
    t2 = micros();
    // print informations
    Serial.print("\r\n");
    Serial.println("**START**");
    Serial.print("Sampling rate = ");
    //Calculate sampling rate
    Serial.print(MAX_SIZE * 1e6 / (t2 - t1));
    Serial.print("\r\n");
    Serial.println("**END**");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
    //Data acquisition
    while (1) {
        print_with_leading_zero(analogRead(A0));
    }
}

void print_with_leading_zero(int data) {
    if (data >= 100) {
        Serial.println(data);
    }
    else if (data >= 10) {
        Serial.print("0");
        Serial.println(data);
    }
    else {
        Serial.print("00");
        Serial.println(data);
    }
}
void loop() {
}