void FRETwPulse(uint8_t LEDnumber, uint8_t selectedLEDs[], LEDpins LED[], uint8_t pwmVal[], unsigned long tOn[], 
unsigned long tPause, unsigned long tPulseDur, unsigned long tPulseTime, uint8_t selectedPulseLED, uint8_t pulseLEDpwm) {
  // Determine the port and mask for the specified pin
  volatile uint8_t *port[LEDnumber];
  uint8_t mask[LEDnumber];

  unsigned long tAfterStop[LEDnumber];
  unsigned long tBefDelay;
  unsigned long tBefStop[LEDnumber];
  unsigned long tAfterOn[LEDnumber];
  uint16_t analogReads[LEDnumber];

  
  // Serial.println(tPulseDur);
  // Serial.println(tPulseTime);
  // Serial.println(selectedPulseLED);
  // Serial.println(pulseLEDpwm);


  //Setup ports and masks for fast on and off switching; Also set PWMs
  for (int i = 0; i < LEDnumber; i++) {
    uint8_t selLED = selectedLEDs[i];
    if (LED[selLED].LEDPin < 30) {
      port[i] = &PORTA;
      mask[i] = 1 << LED[selLED].LEDPin - 22;
    } else if (LED[selLED].LEDPin < 38) {
      port[i] = &PORTC;
      mask[i] = 1 << (38 - LED[selLED].LEDPin);
    }
    analogWrite(LED[selLED].PWMPin, pwmVal[i]);
  }
  //Setup for Pulse LED
    volatile uint8_t *portPulse;
  uint8_t maskPulse;

    if (LED[selectedPulseLED].LEDPin < 30) {
      portPulse = &PORTA;
      maskPulse = 1 << LED[selectedPulseLED].LEDPin - 22;
    } else if (LED[selectedPulseLED].LEDPin < 38) {
      portPulse = &PORTC;
      maskPulse = 1 << (38 - LED[selectedPulseLED].LEDPin);
    }
    analogWrite(LED[selectedPulseLED].PWMPin, pulseLEDpwm);



  
unsigned long startTime = millis(); // Record the start time

while (whileFlag && (millis() - startTime < tPulseTime)) {
  // Your existing loop code here
  for (int i = 0; i < LEDnumber; i++) {
    analogReads[i] = 0;
    analogReads[i] = measureLED(i, tOn[i], port[i], mask[i], &tAfterOn[i], &tAfterStop[i]);
  }
  sendData(LEDnumber, tAfterStop, tAfterOn, analogReads);
  changePWM(LED);
  tBefDelay = micros();
  while (tBefDelay - tAfterStop[LEDnumber - 1] < tPause) tBefDelay = micros();
}

// Code executed after the initial loop
startTime = millis();
*portPulse |= maskPulse;   //Pin  High
while (whileFlag && (millis() - startTime < tPulseDur)) {
} *portPulse &= ~maskPulse;  // Pin  LOW


while (whileFlag) {
  // Loop code running indefinitely or until whileFlag is set to false
  for (int i = 0; i < LEDnumber; i++) {
    analogReads[i] = 0;
    analogReads[i] = measureLED(i, tOn[i], port[i], mask[i], &tAfterOn[i], &tAfterStop[i]);
  }
  sendData(LEDnumber, tAfterStop, tAfterOn, analogReads);
  changePWM(LED);

  tBefDelay = micros();
  while (tBefDelay - tAfterStop[LEDnumber - 1] < tPause) tBefDelay = micros();
}


  PORTA &= B01010101;
  PORTC &= B01010101;
  delay(2000);
  whileFlag = true;
  Serial.println(F("Leaving FRET!"));
  Serial.flush();
}

