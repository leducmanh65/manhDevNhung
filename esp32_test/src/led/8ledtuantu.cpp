#include <Arduino.h>
const int LED[8]= {16,17,18,19,20,21,22,23};

void setup(){
    for(int i= 0; i < 8; i++){
        pinMode(LED[i], OUTPUT );
    }
}

void loop(){
    for(int i = 0; i<8; i++){
        digitalWrite(LED[i], HIGH);
        delay(500);
        digitalWrite(LED[i], LOW);
        delay(500);
    }

    for(int i=7; i>=0; i --){
        digitalWrite(LED[i], HIGH);
        delay(200);
        digitalWrite(LED[i], HIGH);
        delay(200);
    }
}
