void FRET(uint8_t LED, uint8_t pwmVal, unsigned long tOn, unsigned long tPause) {

  unsigned long tAfterStop;
  unsigned long tBefDelay;
  unsigned long tBefStop;
  unsigned long tAfterOn;
  uint16_t analogReads;


  switch (LED) {
    case 1:
      {
        Serial.println(F("LED1 selected!"));

        analogWrite(4, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          analogReads = 0;
          tAfterOn = micros();
          tBefStop = micros();
          PORTA |= B00000010;  //Pin 23 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTA &= B11111101;  // Pin 23 LOW

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(4, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 2:
      {
        analogWrite(5, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTA |= B00001000;  //Pin 25 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTA &= B11110111;  // Pin 25 LOW
          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }


          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(5, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 3:
      {
        analogWrite(6, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTA |= B00100000;  //Pin 27 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTA &= B11011111;  // Pin 23 LOW

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(6, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 4:
      {
        analogWrite(7, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTA |= B10000000;  //Pin 29 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTA &= B01111111;

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(7, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 5:
      {
        analogWrite(8, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTC |= B01000000;  //Pin 31 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTC &= B11101111;

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(8, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 6:
      {
        analogWrite(9, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTC |= B00010000;  //Pin 33 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTC &= B11101111;

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(9, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 7:
      {
        analogWrite(10, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTC |= B00000100;  //Pin 35 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTC &= B11111011;  // Pin 23 LOW

          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(10, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    case 8:
      {
        analogWrite(11, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          tAfterOn = micros();
          tBefStop = micros();
          PORTC |= B00000001;  //Pin 37 High

          while (tBefStop - tAfterOn < tOn) {
            //analogTime[analogReads] = micros();
            analogInput15[analogReads] = analogRead(15);
            //  delayMicroseconds(10);
            analogInput14[analogReads] = analogRead(14);
            //  delayMicroseconds(10);
            analogReads++;
            tBefStop = micros();
          }

          tAfterStop = micros();
          PORTC &= B11111110;
          // Serial.println("AfterOn!");
          // Serial.println(tAfterOn);
          Serial.write((uint8_t*)&tAfterOn, 4);
          // Serial.println("AfterStop!");
          // Serial.println(tAfterStop);
          Serial.write((uint8_t*)&tAfterStop, 4);
          // Serial.println("analogReads!");
          // Serial.println(analogReads);
          Serial.write((uint8_t*)&analogReads, 2);

          //Serial.write(0);


          // for (int k = 0; k < analogReads; k++) {
          // Serial.write((uint8_t*)&analogTime[k], 4);
          // }
          for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput15[k]));
            Serial.write(lowByte(analogInput15[k]));
          }

          for (int k = 0; k < analogReads; k++) {

            Serial.write(highByte(analogInput14[k]));
            Serial.write(lowByte(analogInput14[k]));
          }

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(11, pwmVal);
          }

          tBefDelay = micros();
          while (tBefDelay - tAfterStop < tPause) tBefDelay = micros();

          //  delayMicroseconds(tPause - (tBefDelay - tAfterStop));
          //          delay(500);
        }
      }
    default: Serial.println(F("You shouldnt be able to read this"));
  }

exit_loop:;

  PORTA &= B01010101;
  PORTC &= B01010101;

  memset(incomingMessage, 0, sizeof incomingMessage);
 // delay(2000);
  Serial.println(F("Leaving FRET!"));
}
