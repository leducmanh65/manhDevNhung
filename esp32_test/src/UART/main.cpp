#include <Arduino.h>

#define LED 2

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  Serial.println("1. Bat LED");
  Serial.println("2. Tat LED");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch (c) {
      case '1':
        digitalWrite(LED, HIGH);
        Serial.println("LED da bat");
        break;
      case '2':
        digitalWrite(LED, LOW);
        Serial.println("LED da tat");
        break;
      default:
        Serial.println("Lenh khong hop le");
        break;
    }
  }
}
