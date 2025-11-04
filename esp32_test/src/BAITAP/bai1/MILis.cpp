#include <Arduino.h>

#define LED1 17
#define LED2 18
#define BUTTON 16

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

int chuki1 = 500;   // chu kỳ nhấp nháy LED1 (ms)
int chuki2 = 1000;  // chu kỳ nhấp nháy LED2 (ms)

bool ttled1 = false;
bool ttled2 = false;

volatile bool tinhieu = false; 

// hàm xử lý ngătxs
void IRAM_ATTR handleButton() {
  tinhieu = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON), handleButton, FALLING);

  Serial.println("Chuong trinh bat dau!");
}

void loop() {
  unsigned long currentMillis = millis();

// khi nào thì trạng thái led 1
  if (currentMillis - previousMillis1 >= chuki1) {
    previousMillis1 = currentMillis;
    ttled1 = !ttled1;
    digitalWrite(LED1, ttled1);
  }
// khi nào thì đổi trạng tahsi led 2
  if (currentMillis - previousMillis2 >= chuki2) {
    previousMillis2 = currentMillis;
    ttled2 = !ttled2;
    digitalWrite(LED2, ttled2);
  }

// nutys nhấn thì hoán đổi chu kì
  if (tinhieu) {
    tinhieu = false;

    int temp = chuki1;
    chuki1 = chuki2;
    chuki2 = temp;

    Serial.println("Da hoan doi chu ky LED!");
    Serial.print("chuki1 = "); Serial.print(chuki1);
    Serial.print(", chuki2 = "); Serial.println(chuki2);
  }
}
