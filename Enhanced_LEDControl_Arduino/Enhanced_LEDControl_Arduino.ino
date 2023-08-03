//Some global variables
uint32_t MaxWaitTime = 100000;
unsigned long startTime;
bool whileFlag = true;
uint8_t LEDnumber;

//Create analogInputpairs
struct analogInputs {
  uint16_t input15;
  uint16_t input14;
};
struct analogInputs analogInput[4][250]; //7.5ms max 

//Create Structs for LED and pwm pairs
struct LEDpins {
  uint8_t LEDPin;
  uint8_t PWMPin;
};

struct LEDpins LEDs[8];

void setup() {
  //Create LED on/off and pwm pairs
  LEDs[0].LEDPin = 23;
  LEDs[0].PWMPin = 4;
  LEDs[1].LEDPin = 25;
  LEDs[1].PWMPin = 5;
  LEDs[2].LEDPin = 27;
  LEDs[2].PWMPin = 6;
  LEDs[3].LEDPin = 29;
  LEDs[3].PWMPin = 7;
  LEDs[4].LEDPin = 31;
  LEDs[4].PWMPin = 8;
  LEDs[5].LEDPin = 33;
  LEDs[5].PWMPin = 9;
  LEDs[6].LEDPin = 35;
  LEDs[6].PWMPin = 10;
  LEDs[7].LEDPin = 37;
  LEDs[7].PWMPin = 11;


  Serial.begin(500000);                               //  setup serial


  //Set Pins to Output
  DDRG = B00100000;  //Set PWM to output DP4
  DDRE = B00001000;  // Set PWM to output DP5
  DDRH = B01111000;  // Set PWM to output DP6,7,8,9
  DDRB = B00110101;  //Set LTC Powerports to Output and PWM to output DP10,11,51,53
  DDRA = B10101010;  // Set LED Pins to output DP 23,25,27,29
  DDRC = B00010101;  // Set LED Pins to output DP 31,33,35,37
  DDRL = B00000101;  // Set LTC Pins to output DP 47,49
  DDRK &= B11111100;
  PORTL = PORTL | B00000101;
  PORTB = PORTB | B00000101;
  // Clear bits 0 and 1 of the DDRK register (Analog Inputs 14 and 15 to read)
  ADCSRA &= ~(bit(ADPS0) | bit(ADPS1) | bit(ADPS2));  // clear prescaler bits
  ADCSRA |= (1 << ADPS2) | (1 << ADPS0);    // 32 prescaler for 38.5 KHz
//  ADCSRA |= (1 << ADPS2);                     // 16 prescaler for 76.9 KHz
  //ADCSRA |= (1 << ADPS1) | (1 << ADPS0);    // 8 prescaler for 153.8 KHz
  Serial.println("Ready");
}


void loop() {
  Serial.println(F("Waiting for program Info..."));
  delay(1000);
  uint8_t programNumber = waitForProgramInfo();
  readProgramDataAndStart(programNumber);
}


uint8_t waitForProgramInfo() {
  // uint8_t incomingBytes = 1;
  uint8_t programNumber;
  programNumber = readSerialDataInt8();
  return (programNumber);
}

void readProgramDataAndStart(uint8_t programNumber) {
  unsigned long *tOn;
  unsigned long tPause;
  uint8_t *pwmVal;
  uint8_t *selectedLEDs;

  switch (programNumber) {
    case 1: { //FRET
      Serial.println(F("Program 1: FRET selected. Waiting for data..."));
      LEDnumber = readSerialDataInt8();

      tOn = new unsigned long[LEDnumber];
      pwmVal = new uint8_t[LEDnumber];
      selectedLEDs = new uint8_t[LEDnumber];

      for (int i = 0; i < LEDnumber; i++) {
        selectedLEDs[i] = readSerialDataInt8();
        pwmVal[i] = readSerialDataInt8();
        tOn[i] = readSerialDataLong();
        delay(100);
      }
      
      tPause = readSerialDataLong();
      
      Serial.println(F("Data Received, Starting FRET"));
      FRET(LEDnumber, selectedLEDs, LEDs, pwmVal, tOn, tPause);
      break;
    }
    case 2: { //Light
          Serial.println(F("Program 1: Light selected. Waiting for data..."));
      LEDnumber = readSerialDataInt8();
      selectedLEDs = new uint8_t[LEDnumber];
      pwmVal = new uint8_t[LEDnumber];
      for (int i = 0; i < LEDnumber; i++) {
        selectedLEDs[i] = readSerialDataInt8();
        pwmVal[i] = readSerialDataInt8();
      }
      Serial.println(F("Data Received, Starting Light"));
      Light(LEDnumber, selectedLEDs, LEDs, pwmVal);

      break;}
    case 3:  {//complexLight
      Serial.println(F("Program 3: complexLight selected. Waiting for data..."));
      LEDnumber = readSerialDataInt8();
      tOn = new unsigned long[LEDnumber];
      pwmVal = new uint8_t[LEDnumber];
      selectedLEDs = new uint8_t[LEDnumber];
      unsigned long tPause[LEDnumber];
      unsigned long tPauseAll;
  for (int i = 0; i < LEDnumber; i++) {
        selectedLEDs[i] = readSerialDataInt8();
        pwmVal[i] = readSerialDataInt8();
        tOn[i] = readSerialDataLong();
        tPause[i] = readSerialDataLong();
  delay(100);
      }
      tPauseAll =  readSerialDataLong();
      uint8_t repeats = readSerialDataInt8();
      Serial.println(F("Data Received, Starting complexLight"));
      complexLight(LEDnumber, selectedLEDs, LEDs, pwmVal, tOn, tPause,tPauseAll, repeats);
      break;
    }
    case 4: {//FRETwPulse
Serial.println(F("Program 4: FRETwPulse selected. Waiting for data..."));
      LEDnumber = readSerialDataInt8();

      tOn = new unsigned long[LEDnumber];
      pwmVal = new uint8_t[LEDnumber];
      selectedLEDs = new uint8_t[LEDnumber];

      for (int i = 0; i < LEDnumber; i++) {
        selectedLEDs[i] = readSerialDataInt8();
        pwmVal[i] = readSerialDataInt8();
        tOn[i] = readSerialDataLong();
        delay(100);
      }
      
      tPause = readSerialDataLong();
      

      uint8_t selectedPulseLED = readSerialDataInt8();
      uint8_t pulseLEDpwm = readSerialDataInt8();
      unsigned long tPulseDur = readSerialDataLong();
      unsigned long tPulseTime = readSerialDataLong();

  // Serial.println(tPulseDur);
  // Serial.println(tPulseTime);
  // Serial.println(selectedPulseLED);
  // Serial.println(pulseLEDpwm);

  
      Serial.println(F("Data Received, Starting FRETwPulse"));
      FRETwPulse(LEDnumber, selectedLEDs, LEDs, pwmVal, tOn, tPause, tPulseDur, tPulseTime, selectedPulseLED, pulseLEDpwm);
      break;
    }
    default:
      Serial.println(F("ERROR - Program not found!- Restarting now"));
Serial.flush();
      break;
  }
}
