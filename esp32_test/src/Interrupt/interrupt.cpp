
#include <Arduino.h>
 
const int led = 17;
const int button = 16;
bool ledstates = 0;
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
 
void IRAM_ATTR buttonPush() {
  portENTER_CRITICAL_ISR(&mux);
  Serial.println("Button Pushed!!!");
  digitalWrite(led, ~ledstates);
  portEXIT_CRITICAL_ISR(&mux);
}
void setup(){
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), buttonPush, FALLING);
  pinMode(led, OUTPUT);
  digitalWrite(led, ledstates);
}
void loop() {
}