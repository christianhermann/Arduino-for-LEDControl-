
uint8_t messageBytes = 10;
uint8_t startByte = 1;
/*
Byte 1 = Amount of LEDs
Byte 2 = LED
Byte 3 = PWM / LED Intensity
Byte 4-7 = LED on time
Byte 8-11 = LED off time
*/
const uint16_t MaxWaitTime = 100000;
unsigned long startTime;
uint8_t incomingMessage[31];
typedef decltype(&PORTB) PortPointer;


class LED {

  //Class variables
  uint8_t LEDpin;  //used pin
  uint8_t PWMpin;  //used PWM pin
  uint8_t LEDpinBitHigh;
  uint8_t LEDpinBitLow;
  uint8_t pwmVal;        //used intensity
  unsigned long tOn;     //microseconds time on
  unsigned long tPause;  //microseconds time off
  PortPointer port;
  bool currentState;  //true = high; false = low;
  unsigned long lastSwichTime;

public:

  LED(uint8_t used_LEDpin, uint8_t pwmValue, unsigned long timeOn, unsigned long timeOff) {
    tOn = timeOn;
    tPause = timeOff;
    currentState = false;
    switch (used_LEDpin) {
      case 1:
        {
          LEDpin = 23;
          PWMpin = 4;
          LEDpinBitHigh = B00000010;
          LEDpinBitLow = B11111101;
          port = &PORTA;
          Serial.println(F("LED1 selected!"));
        }
        break;
              case 3:
        {
          LEDpin = 27;
          PWMpin = 6;
          port = &PORTA;
          LEDpinBitHigh = B00100000;
          LEDpinBitLow = B11011111;
          Serial.println(F("LED3 selected!"));
        }
        break;
      case 4:
        {
          LEDpin = 29;
          PWMpin = 7;
          port = &PORTA;
          LEDpinBitHigh = B10000000;
          LEDpinBitLow = B01111111;
          Serial.println(F("LED4 selected!"));
        }
        break;
      case 5:
        {
          LEDpin = 31;
          PWMpin = 8;
          port = &PORTC;
          LEDpinBitHigh = B01000000;
          LEDpinBitLow = B10111111;
          Serial.println(F("LED5 selected!"));
        }
        break;
    }
    analogWrite(PWMpin, pwmValue);
  }

  void Update() {
    unsigned long currentTime = micros();

    if ((currentState) && (currentTime - lastSwichTime >= tOn)) {
      currentState = false;
      lastSwichTime = currentTime;
      *port &= LEDpinBitLow;
    } else if ((!currentState) && (currentTime - lastSwichTime >= tPause)) {
      currentState = true;
      lastSwichTime = currentTime;
      *port |= LEDpinBitHigh;
    }
  }
};








void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //  setup serial

  DDRG = B00100000;  //Set PWM to output DP4
  DDRE = B00001000;  // Set PWM to output DP5
  DDRH = B01111000;  // Set PWM to output DP6,7,8,9
  DDRB = B00110101;  //Set LTC Powerports to Output and PWM to output DP10,11,51,53
  DDRA = B10101010;  // Set LED Pins to output DP 23,25,27,29
  DDRC = B00010101;  // Set LED Pins to output DP 31,33,35,37
  DDRL = B00000101;  // Set LTC Pins to output DP 47,49


  PORTL = PORTL | B00000101;  //Power LTC Ports
  PORTB = PORTB | B00000101;  // Power LTC Ports
  Serial.println("Ready");
}

void loop() {


  // put your main code here, to run repeatedly:
  scanForInput();
      Serial.println("Loading Programm");

  if (incomingMessage[0] == 1) {
        Serial.println(F("Programm 1"));

    unsigned long tOn = 0;
    tOn += ((unsigned long)incomingMessage[6] << 24);
    tOn += ((unsigned long)incomingMessage[5] << 16);
    tOn += ((unsigned long)incomingMessage[4] << 8);
    tOn += ((unsigned long)incomingMessage[3]);

    unsigned long tPause = 0;
    tPause += ((unsigned long)incomingMessage[10] << 24);
    tPause += ((unsigned long)incomingMessage[9] << 16);
    tPause += ((unsigned long)incomingMessage[8] << 8);
    tPause += ((unsigned long)incomingMessage[7]);

    LED FRET1(incomingMessage[1], incomingMessage[2], tOn, tPause);

    Serial.println(F("Data Received, Starting FRET"));



    while (true) {
      FRET1.Update();
    }
  }

  if (incomingMessage[0] == 2) {
        Serial.println(F("Programm 2"));

     unsigned long tOn = 0;
    tOn += ((unsigned long)incomingMessage[6] << 24);
    tOn += ((unsigned long)incomingMessage[5] << 16);
    tOn += ((unsigned long)incomingMessage[4] << 8);
    tOn += ((unsigned long)incomingMessage[3]);

    unsigned long tPause = 0;
    tPause += ((unsigned long)incomingMessage[10] << 24);
    tPause += ((unsigned long)incomingMessage[9] << 16);
    tPause += ((unsigned long)incomingMessage[8] << 8);
    tPause += ((unsigned long)incomingMessage[7]);

    LED FRET1(incomingMessage[1], incomingMessage[2], tOn, tPause);

    tOn = 0;
    tOn += ((unsigned long)incomingMessage[16] << 24);
    tOn += ((unsigned long)incomingMessage[15] << 16);
    tOn += ((unsigned long)incomingMessage[14] << 8);
    tOn += ((unsigned long)incomingMessage[13]);

    tPause = 0;
    tPause += ((unsigned long)incomingMessage[20] << 24);
    tPause += ((unsigned long)incomingMessage[19] << 16);
    tPause += ((unsigned long)incomingMessage[18] << 8);
    tPause += ((unsigned long)incomingMessage[17]);


    LED FRET2(incomingMessage[11], incomingMessage[12], tOn, tPause);

    Serial.println(F("Data Received, Starting FRET"));

    while (true) {
      FRET1.Update();
      FRET2.Update();
    }
  }

  if (incomingMessage[0] == 3) {
        Serial.println(F("Programm 3"));

     unsigned long tOn = 0;
    tOn += ((unsigned long)incomingMessage[6] << 24);
    tOn += ((unsigned long)incomingMessage[5] << 16);
    tOn += ((unsigned long)incomingMessage[4] << 8);
    tOn += ((unsigned long)incomingMessage[3]);

    unsigned long tPause = 0;
    tPause += ((unsigned long)incomingMessage[10] << 24);
    tPause += ((unsigned long)incomingMessage[9] << 16);
    tPause += ((unsigned long)incomingMessage[8] << 8);
    tPause += ((unsigned long)incomingMessage[7]);

    LED FRET1(incomingMessage[1], incomingMessage[2], tOn, tPause);

    tOn = 0;
    tOn += ((unsigned long)incomingMessage[16] << 24);
    tOn += ((unsigned long)incomingMessage[15] << 16);
    tOn += ((unsigned long)incomingMessage[14] << 8);
    tOn += ((unsigned long)incomingMessage[13]);

    tPause = 0;
    tPause += ((unsigned long)incomingMessage[20] << 24);
    tPause += ((unsigned long)incomingMessage[19] << 16);
    tPause += ((unsigned long)incomingMessage[18] << 8);
    tPause += ((unsigned long)incomingMessage[17]);


    LED FRET2(incomingMessage[11], incomingMessage[12], tOn, tPause);

    tOn = 0;
    tOn += ((unsigned long)incomingMessage[26] << 24);
    tOn += ((unsigned long)incomingMessage[25] << 16);
    tOn += ((unsigned long)incomingMessage[24] << 8);
    tOn += ((unsigned long)incomingMessage[23]);

    tPause = 0;
    tPause += ((unsigned long)incomingMessage[30] << 24);
    tPause += ((unsigned long)incomingMessage[29] << 16);
    tPause += ((unsigned long)incomingMessage[28] << 8);
    tPause += ((unsigned long)incomingMessage[27]);


    LED FRET3(incomingMessage[21], incomingMessage[22], tOn, tPause);


    
    Serial.println(F("Data Received, Starting FRET"));

    while (true) {
      FRET1.Update();
      FRET2.Update();
      FRET3.Update();
    }
  }
}





void scanForInput() {

  startTime = millis();


while (Serial.available() < startByte && ((millis() - startTime) < MaxWaitTime)) {
    // hang in this loop until we either get "messageBytes" bytes of data or MaxWaitTime second
    // has gone by
  }

  incomingMessage[0] = Serial.read();
  messageBytes = messageBytes * incomingMessage[0] ;

  while (Serial.available() < messageBytes && ((millis() - startTime) < MaxWaitTime)) {
    // hang in this loop until we either get "messageBytes" bytes of data or MaxWaitTime second
    // has gone by
  }

  if (Serial.available() < messageBytes) {
    // the data didn't come in - handle that problem here
    Serial.println(F("ERROR - Didn't get all bytes of data!"));
  } else {
    for (int n = 1; n < messageBytes; n++) {
      incomingMessage[n] = Serial.read();  // Then: Get them.
    }
  }
}