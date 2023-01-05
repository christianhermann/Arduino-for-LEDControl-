void FRET(uint8_t LEDnumber, uint8_t selectedLEDs[], LEDpins LED[], uint8_t pwmVal[], unsigned long tOn[], unsigned long tPause) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[LEDnumber];
  uint8_t mask[LEDnumber];

  unsigned long tAfterStop[LEDnumber];
  unsigned long tBefDelay;
  unsigned long tBefStop[LEDnumber];
  unsigned long tAfterOn[LEDnumber];
  uint16_t analogReads[LEDnumber];

  

  //Setup ports and masks for fast on and off switching; Also set PWMs
  for (int i = 0; i < LEDnumber; i++) {
    uint8_t selLED = selectedLEDs[i];
    if (LED[selLED].LEDPin < 30) {
      port[i] = &PORTA;
      mask[i] = 1 << LED[selLED].LEDPin - 22;
    } else if (LED[selLED].LEDPin < 38) {
      port[i] = &PORTC;
      mask[i] = 1 << (38 -  LED[selLED].LEDPin);
    }
    analogWrite(LED[i].PWMPin, pwmVal[i]);
  }

  while (whileFlag == true) {
    for (int i = 0; i < LEDnumber; i++) {
      analogReads[i] = 0;
//      tAfterOn[i] = micros();
//      tBefStop[i] = micros();
//     *port[i] |= mask[i];  //Pin  High
      analogReads[i] = measureLED(i, tOn[i], *port[i], mask[i],  &tAfterOn[i], &tAfterStop[i]);
//      tAfterStop[i] = micros();
//      *port[i] &= ~mask[i];  // Pin  LOW
    }
      sendData(LEDnumber, tAfterStop, tAfterOn, analogReads);
    
    changePWM(LED);
    tBefDelay = micros();
    while (tBefDelay - tAfterStop[LEDnumber] < tPause) tBefDelay = micros();
  }


  PORTA &= B01010101;
  PORTC &= B01010101;
  delay(2000);
  whileFlag = true;
  Serial.println(F("Leaving FRET!"));
}

