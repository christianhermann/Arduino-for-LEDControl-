uint16_t measureLED(uint8_t LEDNum, unsigned long tOnInner,  volatile uint8_t *port, uint8_t mask, unsigned long  *tAfterOnOut, unsigned long *tAfterStopOut) {
  uint16_t analogReadsInner = 0;

  *port |= mask;  //Pin  High
   unsigned long tAfterOnInner = micros();
   unsigned long tBefStopInner = micros();
  while (tBefStopInner - tAfterOnInner < tOnInner) {
    //Read photodiode inputs
    analogInput[LEDNum][analogReadsInner].input15 = analogRead(15);
    analogInput[LEDNum][analogReadsInner].input14 = analogRead(14);
    analogReadsInner++;
    tBefStopInner = micros();
  }
  *port &= ~mask;  // Pin  LOW
  unsigned long tAfterStopInner = micros();

  *tAfterOnOut = tAfterOnInner;
  *tAfterStopOut = tAfterStopInner;

  return (analogReadsInner);
}

void switchLED(uint8_t LEDNum, unsigned long tOnInner,  volatile uint8_t *port, uint8_t mask) {

  *port |= mask;  //Pin  High
  //Set Trigger
   PORTK |= (1 << 7);  // set PK7 high
   PORTK &= ~(1 << 7);  // set PK7 low
   unsigned long tAfterOnInner = micros();
   unsigned long tBefStopInner = micros();
  while (tBefStopInner - tAfterOnInner < tOnInner) {
    tBefStopInner = micros();
  }
  // Set Trigger
  *port &= ~mask;  // Pin  LOW
}


void sendData(uint8_t LEDnumber, unsigned long tAfterStopInner[], unsigned long tAfterOnInner[], uint16_t analogReadsInner[]) {

  for (int i = 0; i < LEDnumber; i++) {
  Serial.write((uint8_t *)&tAfterOnInner[i], 4);
  Serial.write((uint8_t *)&tAfterStopInner[i], 4);
  Serial.write((uint8_t *)&analogReadsInner[i], 2);

  for (int k = 0; k < analogReadsInner[i]; k++) {
    Serial.write(highByte(analogInput[i][k].input15));
    Serial.write(lowByte(analogInput[i][k].input15));
  }

  for (int k = 0; k < analogReadsInner[i]; k++) {
    Serial.write(highByte(analogInput[i][k].input14));
    Serial.write(lowByte(analogInput[i][k].input14));
  }

    }
}

void changePWM(LEDpins LED[]) {
  if (Serial.available() > 1) {
    uint8_t pin = Serial.read();
    uint8_t pwmVal = Serial.read();
    if (pwmVal == 0) whileFlag = false;
    analogWrite(LED[pin].PWMPin, pwmVal);
  }
  else whileFlag = true;
}

uint8_t readSerialDataInt8() {
    while (true) {
  if (Serial.available() > 0) {
    // Read data from serial connection
    int data = Serial.read();
    return(data);
  }
    }
} 

unsigned long readSerialDataLong() {
      while (true) {

    if (Serial.available() >= 4) {
    uint8_t data[4];  // Array to store 4 bytes of data
    // Read 4 bytes of data from serial connection
    int bytesRead = Serial.readBytes(data, 4);
    if (bytesRead == 4) {
      // Convert 4 bytes of data to unsigned long integer
      uint32_t value;
      memcpy(&value, data, 4);
      return value;
    }
  }
      }
} 

