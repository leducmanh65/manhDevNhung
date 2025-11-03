#include <Arduino.h>

#define LED 16

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println("'1' bat led, '2 ' tat led");
}

void loop() {
  if (Serial.available()) {       
    char c = Serial.read();       
    if (c == '1') {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    } else if (c == '0') {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    } else {
      Serial.println("sai lenh");
    }
  }
}
