
uint32_t MaxWaitTime = 100000;

uint16_t analogInput1_1[250];   //max Leuchten 12ms in FRET
uint16_t analogInput1_2[250];   //max Leuchten 12ms in FRET
uint16_t analogInput2_1[250];   //max Leuchten 12ms in FRET
uint16_t analogInput2_2[250];   //max Leuchten 12ms in FRET
uint16_t analogInput3_1[250];   //max Leuchten 12ms in FRET
uint16_t analogInput3_2[250];   //max Leuchten 12ms in FRET
uint16_t analogInput4_1[250];   //max Leuchten 12ms in FRET
uint16_t analogInput4_2[250];   //max Leuchten 12ms in FRET


int16_t analogReads = 0;

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

 while (true) {

            //analogTime[analogReads] = micros();
            analogInput1_1[analogReads] = analogRead(15);
            analogInput1_2[analogReads] = analogRead(15);
            analogInput2_1[analogReads] = analogRead(15);
            analogInput2_2[analogReads] = analogRead(15);
            analogInput3_1[analogReads] = analogRead(15);
            analogInput3_2[analogReads] = analogRead(15);
            analogInput4_1[analogReads] = analogRead(15);
            analogInput4_2[analogReads] = analogRead(15);

            //  delayMicroseconds(10);
            analogReads++;
             if (analogReads ==  1000) break;
          }

            for (int k = 0; k < analogReads; k++) {
            Serial.write(highByte(analogInput1_1[k]));
            Serial.write(highByte(analogInput1_2[k]));
            Serial.write(highByte(analogInput2_1[k]));
            Serial.write(highByte(analogInput2_2[k]));            
            Serial.write(highByte(analogInput3_1[k]));            
            Serial.write(highByte(analogInput3_2[k]));
            Serial.write(highByte(analogInput4_1[k]));
            Serial.write(highByte(analogInput4_2[k]));
          }
}
