void FRET(uint8_t LED, uint8_t pwmVal, unsigned long tOn, unsigned long tPause) {

  unsigned long tOn_delayed = tOn ;          // 0.125us is the time it takes to set the port low again (Might need to write a function which is more precise than intergers)
  unsigned long tPause_delayed = tPause - 2;  // 0.125us is the time it takes to set the port high again // ~2us is the time it takes to check the serial port



  switch (LED) {
    case 1:
      {
        Serial.println(F("LED1 selected!"));

        analogWrite(4, pwmVal);

        while (true) {
          PORTA |= B00000010;  //Pin 23 High
          delayMicroseconds(tOn_delayed);
          PORTA &= B11111101;  // Pin 23 LOW

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(4, pwmVal);
          }
          delayMicroseconds(tPause_delayed);
        }
      }
      
    case 2:
      {
        Serial.println(F("LED2 selected!"));

        analogWrite(5, pwmVal);

        while (true) {
          PORTA |= B00001000;  //Pin 25 High
          delayMicroseconds(tOn_delayed);
          PORTA &= B11110111;  // Pin 25 LOW

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(5, pwmVal);
          }

          delayMicroseconds(tPause_delayed);
        }
      }
    case 3:
      {
        Serial.println(F("LED3 selected!"));

        analogWrite(6, pwmVal);

        while (true) {
          PORTA |= B00100000;  //Pin 27 High
          delayMicroseconds(tOn_delayed);
          PORTA &= B11011111;  // Pin 27 LOW

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(6, pwmVal);
          }

          delayMicroseconds(tPause_delayed);
        }
      }

       case 4:
      {
        Serial.println(F("LED4 selected!"));

        analogWrite(7, pwmVal);

        while (true) {
          PORTA |= B10000000;  //Pin 29 High
          Serial.println(tOn_delayed);
          delayMicroseconds(tOn_delayed);
          PORTA &= B01111111;  // Pin 29 LOW

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(7, pwmVal);
          }
          Serial.println(tPause_delayed);

          delayMicroseconds(tPause_delayed);
        }
      }
  }
exit_loop:;

  PORTA &= B01010101;  //Set all LEDs to off
  PORTC &= B01010101;  // Set all LEDs to off

  memset(incomingMessage, 0, sizeof incomingMessage);
  delay(2000);
  Serial.println(F("Leaving FRET!"));
}
