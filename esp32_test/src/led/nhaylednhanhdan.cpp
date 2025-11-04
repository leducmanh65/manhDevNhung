// bài này em sẽ cho một vòng lặp về delay//

#include <Arduino.h>

#define LED 16

void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    for(int d = 500; d>=50; d-=50){
        digitalWrite(LED, HIGH);
        delay(d);
        digitalWrite(LED, LOW);
        delay(d);
    }
}