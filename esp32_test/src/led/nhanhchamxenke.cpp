#include <Arduino.h>

#define LED 16
void setup(){
    pinMode(LED, OUTPUT);
}

void loop(){
    digitalWrite(LED, HIGH);
    delay(700);
    digitalWrite(LED, LOW);
    delay(300);
}