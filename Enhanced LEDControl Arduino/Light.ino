 void Light(uint8_t LEDnumber, LEDpins LED[], uint8_t pwmVal[]) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[LEDnumber];
  uint8_t mask[LEDnumber];


  //Setup ports and masks for fast on and off switching; Also set PWMs and Lights on
  for (int i = 0; i < LEDnumber; i++) {
    if (LED[i].LEDPin < 30) {
      port[i] = &PORTA;
      mask[i] = 1 << LED[i].LEDPin - 22;
    } else if (LED[i].LEDPin < 38) {
      port[i] = &PORTC;
      mask[i] = 1 << (38 -  LED[i].LEDPin);
    }
    analogWrite(LED[i].PWMPin, pwmVal[i]);
    *port[i] |= mask[i];  //Pin  High
  }
  while (whileFlag = true) {
      changePWM(LED);
 }

  PORTA &= B01010101;
  PORTC &= B01010101;
  delay(2000);
  Serial.println(F("Leaving Light!"));
 }



 
 