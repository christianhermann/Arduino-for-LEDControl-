uint32_t MaxWaitTime = 100000;
unsigned long startTime;
uint8_t incomingMessage[11];
uint8_t incomingBytes = 11;
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


void scanForInput() {

  startTime = millis();

  while (Serial.available() < incomingBytes  && ((millis() - startTime) < MaxWaitTime))
  {
    // hang in this loop until we either get "incomingBytes" bytes of data or MaxWaitTime second
    // has gone by
  }

  if (Serial.available() < incomingBytes )
  {
    // the data didn't come in - handle that problem here
    Serial.println(F("ERROR - Didn't get all bytes of data!"));
  }
  else
  {
    for (int n = 0; n < incomingBytes; n++) {
      incomingMessage[n] = Serial.read(); // Then: Get them.
    }
  }
}
