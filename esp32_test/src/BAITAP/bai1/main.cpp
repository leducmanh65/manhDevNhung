#include <Arduino.h>

#define Led1  17
#define Led2  18
#define BUTTON  16

bool ttLed1 = false;
bool ttLed2 = false;

volatile int tgian1 = 500;
volatile int tgian2 = 1000; 

hw_timer_t *timer1 = NULL;
hw_timer_t *timer2 = NULL; 

portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;

void IRAM_ATTR onTimer1() { // cpu gọi isr ngay khi bị ngắt
  ttLed1 = !ttLed1;
  digitalWrite(Led1, ttLed1);
}

void IRAM_ATTR onTimer2() {
  ttLed2 = !ttLed2;
  digitalWrite(Led2, ttLed2);
}

void IRAM_ATTR handleButton() {
  portENTER_CRITICAL_ISR(&mux);
  int temp = tgian1;
  tgian1 = tgian2;
  tgian2 = temp;
  timerAlarmWrite(timer1, tgian1 * 1000, true);
  timerAlarmWrite(timer2, tgian2 * 1000, true);
  portEXIT_CRITICAL_ISR(&mux);
}

void setup() {
  Serial.begin(115200);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), handleButton, FALLING);
  timer1 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer1, &onTimer1, true);
  timerAlarmWrite(timer1, tgian1 * 1000, true);
  timerAlarmEnable(timer1);
  timer2 = timerBegin(1, 80, true);
  timerAttachInterrupt(timer2, &onTimer2, true);
  timerAlarmWrite(timer2, tgian2 * 1000, true);
  timerAlarmEnable(timer2);
}

void loop() {
}
