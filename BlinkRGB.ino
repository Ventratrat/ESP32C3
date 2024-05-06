
void setup() {
  
}


void loop() {
#ifdef RGB_BUILTIN

  neopixelWrite(RGB_BUILTIN,255,0,255);
  delay(3000);
  neopixelWrite(RGB_BUILTIN,0,0,0);
  delay(2000);
  neopixelWrite(RGB_BUILTIN,255,0,0);
  delay(3000);
  neopixelWrite(RGB_BUILTIN,0,0,0); 
  delay(4000);
#endif
}
