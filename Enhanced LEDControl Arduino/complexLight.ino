void complexLight(uint8_t LEDnumber, LEDpins LED[], uint8_t pwmVal[], unsigned long tOn[], unsigned long tPause[], uint8_t repeats) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[LEDnumber];
  uint8_t mask[LEDnumber];
  unsigned long tAfterStop;
  unsigned long tBefDelay;
  unsigned long tBefStop;
  unsigned long tAfterOn;

  //Setup ports and masks for fast on and off switching; Also set PWMs
  for (int i = 0; i < LEDnumber; i++) {
    if (LED[i].LEDPin < 30) {
      port[i] = &PORTA;
      mask[i] = 1 << LED[i].LEDPin - 22;
    } else if (LED[i].LEDPin < 38) {
      port[i] = &PORTC;
      mask[i] = 1 << (38 -  LED[i].LEDPin);
    }
    analogWrite(LED[i].PWMPin, pwmVal[i]);
  }

uint8_t repeat = 0;
while ( (repeat < repeats || repeats == 0) && whileFlag == true)  {
 for (int i = 0; i < LEDnumber; i++) {
      tAfterOn = micros();
      tBefStop = micros();
      *port[i] |= mask[i];  //Pin  High
      while (tBefStop - tAfterOn < tOn[i])  tBefStop = micros();
      tAfterStop = micros();
      *port[i] &= ~mask[i];  // Pin  LOW
      while (tBefDelay - tAfterStop < tPause[i]) tBefDelay = micros();
 }
 changePWM(LED);
 repeat++;
}
  PORTA &= B01010101;
  PORTC &= B01010101;
  delay(2000);
  Serial.println(F("Leaving complex Light!"));
}

