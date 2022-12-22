uint32_t MaxWaitTime = 100000;
unsigned long startTime;
bool whileFlag = true;
//Create analogInputpairs
struct analogInputs {
  uint16_t input15;
  uint16_t input14;
};
struct analogInputs analogInput[4][250];

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




  Serial.begin(500000);           //  setup serial
  ADCSRA &= ~(bit (ADPS0) | bit (ADPS1) | bit (ADPS2)); // clear prescaler bits
  ADCSRA |= bit (ADPS2);                               //  prescale Value 16

  //Set Pins to Output
  DDRG = B00100000;  //Set PWM to output DP4
  DDRE = B00001000;  // Set PWM to output DP5
  DDRH = B01111000;  // Set PWM to output DP6,7,8,9
  DDRB = B00110101;  //Set LTC Powerports to Output and PWM to output DP10,11,51,53
  DDRA = B10101010;  // Set LED Pins to output DP 23,25,27,29
  DDRC = B00010101;  // Set LED Pins to output DP 31,33,35,37
  DDRL = B00000101;  // Set LTC Pins to output DP 47,49
  DDRK &=B11111100; 
  // Clear bits 0 and 1 of the DDRK register (Analog Inputs 14 and 15 to read)
  Serial.println("Ready");


}


void loop() {

}


uint8_t waitForProgrammInfo() {
    uint8_t incomingBytes = 1;
    uint8_t programNumber;
    while (!Serial.available())
    {
     // wait for seriel communication
    }

     programNumber = Serial.read();
}

void readProgramDataAndStart(uint8_t programNumber){
  switch (programNumber) {
  case 1: 
    uint8_t LEDnumber = Serial.read();
    unsigned long tOn[LEDnumber];
    unsigned long tPause[LEDnumber];
    uint8_t pwmVal[LEDnumber];
    for (int i = 0; i < LEDnumber; i++) {
      pwmVal[i] = Serial.read();
      tOn[i] =  Serial.parseInt();
      tPause[i] =  Serial.parseInt();
    }
  FRET(LEDnumber,  LEDs, pwmVal,  tOn, tPause);

    break;
  
  case 2:
    // code to execute if expression is 2
    break;
  case 3:
    // code to execute if expression is 3
    break;
  default:
    Serial.println(F("ERROR - Program not found!"));
    break;
}
}
  