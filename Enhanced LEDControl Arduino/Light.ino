 void Light(uint8_t LEDnumber, uint8_t selectedLEDs[], LEDpins LED[], uint8_t pwmVal[]) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[LEDnumber];
  uint8_t mask[LEDnumber];


  //Setup ports and masks for fast on and off switching; Also set PWMs and Lights on
  for (int i = 0; i < LEDnumber; i++) {
    uint8_t selLED = selectedLEDs[i];


    if (LED[selLED].LEDPin < 30) {
      port[i] = &PORTA;
      mask[i] = 1 << LED[selLED].LEDPin - 22;
    } else if (LED[selLED].LEDPin < 38) {
      port[i] = &PORTC;
      mask[i] = 1 << (38 -  LED[selLED].LEDPin);
    }
    analogWrite(LED[selLED].PWMPin, pwmVal[i]);
    *port[i] |= mask[i];  //Pin  High
  }
  while (whileFlag == true) {
      changePWM(LED);
 }

  PORTA &= B01010101;
  PORTC &= B01010101;
  whileFlag = true;
  Serial.println(F("Leaving Light!"));
  Serial.flush();
 }



 
 