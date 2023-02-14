/*
Here is a code of EELab Lab 05 exp2
Written  BY Keith Lin (KYLiN)
Date : 2022 / 3 /22 
*/

int pushButton = 2;
int LED = 13;
boolean state = true;

void setup() {
    Serial.begin(9600);
    pinMode(pushButton, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    auto buttonState = digitalRead(pushButton);
    if (!buttonState) {
        digitalWrite(LED, LOW);
        delay(1000);
        digitalWrite(LED, HIGH);
        delay(1000);
        Serial.println(buttonState);
    }
    else {
        digitalWrite(LED, LOW);
        Serial.println(buttonState);
    }

}
