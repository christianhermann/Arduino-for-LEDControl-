
uint32_t MaxWaitTime = 100000;

uint16_t analogInput14[1000];   //max Leuchten 30ms in FRET
uint16_t analogInput15[1000];   //max Leuchten 30ms in FRET
// unsigned long analogTime[700];   //max Leuchten 25ms in FRET



unsigned long startTime;
uint8_t incomingMessage[11];
uint8_t standIncomingBytes;

void setup() {


  Serial.begin(500000);           //  setup serial
  ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits
  ADCSRA |= bit (ADPS2);                               //  prescale Value 16


  pinMode(4, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);
  PORTL = PORTL | B00000101;
  PORTB = PORTB | B00000101;
  Serial.println("Ready");
  standIncomingBytes = 11;

}


void loop() {


  // put your main code here, to run repeatedly:
  scanForInput(standIncomingBytes);
  serial_flush();

  switch (incomingMessage[0]){
   case 1: {
    unsigned long tOn = 0;
    tOn += ((unsigned long) incomingMessage[6] << 24);
    tOn += ((unsigned long) incomingMessage[5] << 16);
    tOn += ((unsigned long) incomingMessage[4] << 8);
    tOn += ((unsigned long) incomingMessage[3]);

    unsigned long tPause = 0;
    tPause += ((unsigned long) incomingMessage[10] << 24);
    tPause += ((unsigned long) incomingMessage[9] << 16);
    tPause += ((unsigned long) incomingMessage[8] << 8);
    tPause += ((unsigned long) incomingMessage[7]);
    Serial.println(F("Data Received, Starting FRET"));
    FRET(incomingMessage[1], incomingMessage[2], tOn, tPause);
                  break;

  }

  case 2: {
     Serial.println(F("Data Received, Starting Light"));
     Light(incomingMessage[1], incomingMessage[2]);
              break;
  }
  case 3: {
    unsigned long tOn = 0;
    tOn += ((unsigned long) incomingMessage[6] << 24);
    tOn += ((unsigned long) incomingMessage[5] << 16);
    tOn += ((unsigned long) incomingMessage[4] << 8);
    tOn += ((unsigned long) incomingMessage[3]);

    unsigned long tPause = 0;
    tPause += ((unsigned long) incomingMessage[10] << 24);
    tPause += ((unsigned long) incomingMessage[9] << 16);
    tPause += ((unsigned long) incomingMessage[8] << 8);
    tPause += ((unsigned long) incomingMessage[7]);
    Serial.println(F("Data Received, Starting Pulsed Light"));
    LightPulse(incomingMessage[1], incomingMessage[2], tOn, tPause);
                  break;

  }
  case 4: {
    uint8_t numLEDs;
    uint8_t LED1 = incomingMessage[1];
    uint8_t PWM1 = incomingMessage[2];

    unsigned long tOn1 = 0;
    tOn1 += ((unsigned long) incomingMessage[6] << 24);
    tOn1 += ((unsigned long) incomingMessage[5] << 16);
    tOn1 += ((unsigned long) incomingMessage[4] << 8);
    tOn1 += ((unsigned long) incomingMessage[3]);

    unsigned long tPause1 = 0;
    tPause1 += ((unsigned long) incomingMessage[10] << 24);
    tPause1 += ((unsigned long) incomingMessage[9] << 16);
    tPause1 += ((unsigned long) incomingMessage[8] << 8);
    tPause1 += ((unsigned long) incomingMessage[7]);
    Serial.println(F("Data Block 1 received, Chained LED"));

    scanForInput(standIncomingBytes);

    uint8_t LED2 = incomingMessage[1];
    uint8_t PWM2 = incomingMessage[2];

    unsigned long tOn2 = 0;
    tOn2 += ((unsigned long) incomingMessage[6] << 24);
    tOn2 += ((unsigned long) incomingMessage[5] << 16);
    tOn2 += ((unsigned long) incomingMessage[4] << 8);
    tOn2 += ((unsigned long) incomingMessage[3]);

    unsigned long tPause2 = 0;
    tPause2 += ((unsigned long) incomingMessage[10] << 24);
    tPause2 += ((unsigned long) incomingMessage[9] << 16);
    tPause2 += ((unsigned long) incomingMessage[8] << 8);
    tPause2 += ((unsigned long) incomingMessage[7]);
    Serial.println(F("Data Block 2 received, Chained LED"));

    scanForInput(standIncomingBytes);

    uint8_t LED3 = incomingMessage[1];
    uint8_t PWM3 = incomingMessage[2];

    unsigned long tOn3 = 0;
    tOn3 += ((unsigned long) incomingMessage[6] << 24);
    tOn3 += ((unsigned long) incomingMessage[5] << 16);
    tOn3 += ((unsigned long) incomingMessage[4] << 8);
    tOn3 += ((unsigned long) incomingMessage[3]);

    unsigned long tPause3 = 0;
    tPause3 += ((unsigned long) incomingMessage[10] << 24);
    tPause3 += ((unsigned long) incomingMessage[9] << 16);
    tPause3 += ((unsigned long) incomingMessage[8] << 8);
    tPause3 += ((unsigned long) incomingMessage[7]);
    Serial.println(F("Data Block 3 received, Chained LED"));
    scanForInput(1);
    numLEDs = incomingMessage[0]; 

    Serial.println(F("Data Received, Chained LED"));
    ChainedLED(numLEDs, LED1, PWM1, tOn1, tPause1, LED2, PWM2, tOn2, tPause2, LED3, PWM3, tOn3, tPause3);
                  break;
  }
  default: Serial.println(F("You shouldnt be able to read this main menu"));
  }  
}


void scanForInput(uint8_t incomingBytes) {
  memset(incomingMessage, 0, sizeof(incomingMessage));

  startTime = millis();

  while (Serial.available() < incomingBytes  && ((millis() - startTime) < MaxWaitTime))
  {
    // hang in this loop until we either get "incomingBytes" bytes of data or MaxWaitTime second
    // has gone by
  }

  if (Serial.available() < incomingBytes )
  {
    // the data didn  't come in - handle that problem here
    Serial.println(F("ERROR - Didn't get all bytes of data!"));
  }
  else
  {
    for (int n = 0; n < incomingBytes; n++) {
      incomingMessage[n] = Serial.read(); // Then: Get them.
     // Serial.println(incomingMessage[n]);
    }
  }
}

void serial_flush() {
  while (true) {
    delay(20);  // give data a chance to arrive
    if (Serial.available()) {
      // we received something, get all of it and discard it
      while (Serial.available())
        Serial.read();
      continue;  // stay in the main loop
    } 
    else
      break;  // nothing arrived for 20 ms
  }
}
