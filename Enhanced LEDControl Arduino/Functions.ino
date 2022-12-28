uint16_t measureLED(uint8_t LEDNum, unsigned long tOnInner, unsigned long tAfterOnInner, unsigned long tBefStopInner) {
  uint8_t analogReadsInner;
  while (tBefStopInner - tAfterOnInner < tOnInner) {
    //Read photodiode inputs
    analogInput[LEDNum][analogReadsInner].input15 = analogRead(15);
    analogInput[LEDNum][analogReadsInner].input14 = analogRead(14);
    analogReadsInner++;
    tBefStopInner = micros();
  }
  return (analogReadsInner);
}

void sendData(uint8_t LEDNum, unsigned long tAfterStopInner, unsigned long tAfterOnInner, uint16_t analogReadsInner) {
  Serial.write((uint8_t *)&tAfterOnInner, 4);
  Serial.write((uint8_t *)&tAfterStopInner, 4);
  Serial.write((uint8_t *)&analogReadsInner, 2);

  for (int k = 0; k < analogReadsInner; k++) {
    Serial.write(highByte(analogInput[LEDNum][k].input15));
    Serial.write(lowByte(analogInput[LEDNum][k].input15));
  }

  for (int k = 0; k < analogReadsInner; k++) {
    Serial.write(highByte(analogInput[LEDNum][k].input14));
    Serial.write(lowByte(analogInput[LEDNum][k].input14));
  }
}

void changePWM(LEDpins LED[]) {
  while (Serial.available() > 1) {
    uint8_t pin = Serial.read();
    uint8_t pwmVal = Serial.read();
    if (pwmVal == 0) whileFlag = false;
    analogWrite(LED[pin].PWMPin, pwmVal);
  }
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

  if (Serial.available() > 3) {
    // Read data from serial connection
    unsigned long data = Serial.parseInt();
    return(data);
  }
      }
} 