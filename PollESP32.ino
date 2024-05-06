#include <Arduino.h>

#define BUTTON_PIN 9
int buttonState = 0;         // Variable to hold the current button state
int lastButtonState = 0;     // Variable to hold the last button state
unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
unsigned long debounceDelay = 50;    // The debounce time in milliseconds
int ledState = 0;            // Variable to keep track of the LED state
unsigned long lastBlinkTime = 0; // Last time the LED was toggled for blinking


void setup() {
  pinMode(RGB_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
 int reading = digitalRead(BUTTON_PIN); // Read the state of the button

  // Check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed
    if (reading != buttonState) {
      buttonState = reading;

      // Only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState++;
        if (ledState > 2) ledState = 0; // Reset ledState after the third press
        

  #ifdef RGB_BUILTIN
  static unsigned long lastBlinkTime = 0;
  bool isBlinkOn = false;
  switch (ledState) {
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
      break;
  }
  delay(1); // Small delay to prevent debouncing issues
  #endif
}
    }
  }
}
