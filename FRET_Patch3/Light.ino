void Light(uint8_t LED, uint8_t pwmVal) {


  switch (LED) {
    case 1:
      {
        analogWrite(4, pwmVal);
        //analogWrite(LED_1_PWM, 255);
        while (true) {
          PORTA |= B00000010;  //Pin 23 High

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(4, pwmVal);
          }
        }
      }
    case 2:
      {
        analogWrite(5, pwmVal);
        //analogWrite(LED_1_PWM, 255);
        while (true) {
          PORTA |= B00001000;  //Pin 25 High
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(5, pwmVal);
          }
        }
      }
    case 3:
      {
        analogWrite(6, pwmVal);
        //analogWrite(LED_1_PWM, 255);
        while (true) {

          PORTA |= B00100000;  //Pin 27 High
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(6, pwmVal);
          }
        }
      }
    case 4:
      {
        analogWrite(7, pwmVal);

        while (true) {

          PORTA |= B10000000;  //Pin 29 High

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(7, pwmVal);
          }
        }
      }
    case 5:
      {
        analogWrite(8, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          PORTC |= B01000000;  //Pin 31 High
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(8, pwmVal);
          }
        }
      }
    case 6:
      {
        analogWrite(9, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          PORTC |= B00010000;  //Pin 33 High
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(9, pwmVal);
          }
        }
      }
    case 7:
      {
        analogWrite(10, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          PORTC |= B00000100;  //Pin 35 High

          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(10, pwmVal);
          }
        }
      }
    case 8:
      {
        analogWrite(11, pwmVal);
        //analogWrite(LED_1_PWM, 255);

        while (true) {
          PORTC |= B00000001;  //Pin 37 High
          if (Serial.available() > 0) {
            pwmVal = Serial.read();
            if (pwmVal == 0) goto exit_loop;
            analogWrite(11, pwmVal);
          }
        }
      }
    default: Serial.println(F("You shouldnt be able to read this"));
  }

exit_loop:;

  PORTA &= B01010101;
  PORTC &= B01010101;

//  memset(incomingMessage, 0, sizeof incomingMessage);
 
// delay(2000);

  Serial.println(F("Leaving Light!"));
}