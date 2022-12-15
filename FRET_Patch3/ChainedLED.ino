void ChainedLED(uint8_t numLEDs, uint8_t LED1, uint8_t pwmVal1, unsigned long tOn1, unsigned long tPause1, uint8_t LED2, uint8_t pwmVal2, unsigned long tOn2, unsigned long tPause2, uint8_t LED3, uint8_t pwmVal3, unsigned long tOn3, unsigned long tPause3) {

  unsigned long tAfterStop;
  unsigned long tBefDelay;
  unsigned long tBefStop;
  unsigned long tAfterOn;

  switch (numLEDs) {
    case 2:
      {
        analogWrite(LED1 + 3, pwmVal1);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          switch (LED1) {
            case 1:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00000010;  //Pin 23 High

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11111101;  // Pin 23 LOW

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(4, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }
            case 2:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00001000;
                ;

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11110111;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(5, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }
            case 3:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00100000;
                ;

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11011111;
                ;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(6, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }

            default: Serial.println(F("You shouldnt be able to read this LED1"));
          }
          switch (LED2) {
            case 1:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00000010;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11111101;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(4, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            case 2:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00001000;
                ;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11110111;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(5, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            case 3:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00100000;
                ;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11011111;
                ;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(6, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            default: Serial.println(F("You shouldnt be able to read this LED2"));
          }
        }
        break;
      }
    case 3:
      {
        analogWrite(LED1 + 3, pwmVal1);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          switch (LED1) {
            case 1:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00000010;  //Pin 23 High

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11111101;  // Pin 23 LOW

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(4, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }
            case 2:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00001000;
                ;

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11110111;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(5, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }
            case 3:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00100000;
                ;

                while (tBefStop - tAfterOn < tOn1) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11011111;
                ;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(6, pwmVal1);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause1) tBefDelay = micros();
                break;
              }

            default: Serial.println(F("You shouldnt be able to read this LED1"));
          }
          switch (LED2) {
            case 1:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00000010;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11111101;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(4, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            case 2:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00001000;
                ;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11110111;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(5, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            case 3:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00100000;
                ;

                while (tBefStop - tAfterOn < tOn2) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11011111;
                ;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(6, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause2) tBefDelay = micros();
                break;
              }
            default: Serial.println(F("You shouldnt be able to read this LED2"));
          }
          switch (LED3) {
            case 1:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00000010;

                while (tBefStop - tAfterOn < tOn3) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11111101;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(4, pwmVal2);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause3) tBefDelay = micros();
                break;
              }
            case 2:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00001000;
                ;

                while (tBefStop - tAfterOn < tOn3) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11110111;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(5, pwmVal3);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause3) tBefDelay = micros();
                break;
              }
            case 3:
              {
                tAfterOn = micros();
                tBefStop = micros();
                PORTA |= B00100000;
                ;

                while (tBefStop - tAfterOn < tOn3) tBefStop = micros();

                tAfterStop = micros();
                PORTA &= B11011111;
                ;

                if (Serial.available() > 0) {
                  pwmVal1 = Serial.read();
                  if (pwmVal1 == 0) goto exit_loop;
                  analogWrite(6, pwmVal3);
                }

                tBefDelay = micros();
                while (tBefDelay - tAfterStop < tPause3) tBefDelay = micros();
                break;
              }
            default: Serial.println(F("You shouldnt be able to read this LED3"));
          }
        }
      }

    default: Serial.println(F("You shouldnt be able to read this"));
  }

exit_loop:;

  PORTA &= B01010101;
  PORTC &= B01010101;

  memset(incomingMessage, 0, sizeof incomingMessage);
  //delay(2000);
  Serial.println(F("Leaving Chained Light!"));
}
