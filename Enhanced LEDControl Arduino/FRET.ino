void FRET(uint8_t LEDnumber,   LEDpins LED[], uint8_t pwmVal[], unsigned long tOn[], unsigned long tPause[]) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[4];
  uint8_t mask[4];

  unsigned long tAfterStop;
  unsigned long tBefDelay;
  unsigned long tBefStop;
  unsigned long tAfterOn;
  uint16_t analogReads;

//Setup ports and masks for fast on and off switching; Also set PWMs
  for (int i = 0; i < LEDnumber; i++) {  
    if (LED[i].LEDPin < 8) {
     port[i] = &PORTD;
     mask[i] = 1 << LED[i].LEDPin;
    } else if (LED[i].LEDPin < 14) {
     port[i] = &PORTB;
     mask[i] = 1 << (LED[i].LEDPin - 8);
    } else {
      port[i] = &PORTC;
      mask[i] = 1 << (LED[i].LEDPin - 14);
   }
   analogWrite(LED[i].PWMPin, pwmVal[i]);
  }

  for (int i = 0; i < LEDnumber; i++) {  
          analogReads = 0;
          tAfterOn = micros();
          tBefStop = micros();
          *port[i] |= mask[i];  //Pin 23 High
          analogReads = measureLED(i, tOn, tAfterOn, tBefStop);
          tAfterStop = micros();  
          *port[i] &= ~mask[i];   // Pin 23 LOW

}
}

uint16_t measureLED(uint8_t LED,  unsigned long tOn, unsigned long tAfterOn, unsigned long tBefStop) {
          uint8_t analogReads;
          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput[LED][analogReads].input15 = analogRead(15);
          //  delayMicroseconds(10);
            analogInput[LED][analogReads].input14 = analogRead(14);
          //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }
      return(analogReads);
}