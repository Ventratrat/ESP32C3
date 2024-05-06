#include <driver/gpio.h>
#include <esp32/rom/ets_sys.h>
#include <esp_timer.h>

#define BUTTON_PIN 9
volatile int buttonState = 0;

void IRAM_ATTR button_isr() {
  buttonState = (buttonState + 1) % 3;
}

void setup() {
  pinMode(RGB_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), button_isr, RISING);
}

void loop() {
  #ifdef RGB_BUILTIN
  static unsigned long lastBlinkTime = 0;
  bool isBlinkOn = false;

  switch (buttonState) {
    case 0: // LED off
      neopixelWrite(RGB_BUILTIN, 0, 0, 0);
      break;
    case 1: // LED red
      neopixelWrite(RGB_BUILTIN, 255, 0, 0);
      break;
    case 2: // LED blink blue
    neopixelWrite(RGB_BUILTIN, 0, 0, 255);
    delay(57);
    neopixelWrite(RGB_BUILTIN, 0, 0, 0);
    delay(943);
     
  }
  delay(1); // Small delay to prevent debouncing issues
  #endif
}
