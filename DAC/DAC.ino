#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "clsPCA9555.h"
#include "Wire.h"

#include <SPI.h>
#include <DAC7565.h>

#define S1 13 
#define S2 15 
#define S3 12 
#define S4 14 
#define S5 11 
#define S6 6 
#define S7 2 
#define S8 5 
#define S9 1 
#define S10 4 
#define S11 0 
#define S12 3 

#define S13 29 //13+16
#define S14 31 //15+16
#define S15 28 //12+16
#define S16 30 //14+16
#define S17 27 //11+16
#define S18 22 //6+16
#define S19 18 //2+16
#define S20 21 //5+16
#define S21 17 //1+16
#define S22 20 //4+16
#define S23 16 //0+16
#define S24 19 //3+16

DAC dac(-1, 10, -1, 11, 13);

PCA9555 ioport(0x23);
PCA9555 ioport2(0x22);
PCA9555 ioport3(0x21);

void setup() 
{
  // Initialize the DAC
  dac.init();
  
  // Set DAC reference to be powered up, VREF = 2.5V
  // this mean that vout will be able to go from 0V to 2.5V (full scale)
  dac.setReference(DAC_REFERENCE_ALWAYS_POWERED_UP);

  // Set all outputs to 1V
  dac.writeChannel(DAC_CHANNEL_ALL, 39158);

  ioport.begin();

  ioport.setClock(400000);

  ioport2.begin();

  ioport2.setClock(400000);

  ioport3.begin();

  ioport3.setClock(400000);


  for (uint8_t i = 0; i < 15; i++){
    ioport.pinMode(i, OUTPUT);
  }

  for (uint8_t i = 0; i < 15; i++){
    ioport2.pinMode(i, INPUT);
  }

  for (uint8_t i = 0; i < 15; i++){
    ioport3.pinMode(i, INPUT);
  }
  
  pinMode(6, OUTPUT); 
  
}


void loop() {

  unsigned long IO = ((((unsigned long)ioport2.digitalReadWord() | 1920)<<16) | (ioport3.digitalReadWord() | 1152)); //Bitmask for unused inputs on IO extenders

  switch(IO){

    case(~(1UL<<S1)):
    
      oscWrite(0); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S2)):
    
      oscWrite(1); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
          
    case(~(1UL<<S3)):

      oscWrite(2); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S4)):

      oscWrite(3); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S5)):

      oscWrite(4); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S6)):

      oscWrite(5); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S7)):

      oscWrite(6);
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW); 
      break;
      
    case(~(1UL<<S8)):

      oscWrite(7); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S9)):

      oscWrite(8); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
           
    case(~(1UL<<S10)):
    
      oscWrite(9);  
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S11)):
    
      oscWrite(10); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S12)):
    
      oscWrite(11); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S13)):
    
      oscWrite(12); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S14)):
    
      oscWrite(13); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S15)):
    
      oscWrite(14); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;
      
    case(~(1UL<<S16)):

      oscWrite(15); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S17)):

      oscWrite(16); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S18)):

      oscWrite(17); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S19)):

      oscWrite(18); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S20)):

      oscWrite(19); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S21)):

      oscWrite(20); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S22)):

      oscWrite(21); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S23)):

      oscWrite(22); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    case(~(1UL<<S24)):

      oscWrite(23); 
      digitalWrite(6,HIGH);
      ioport.digitalWrite(8, LOW);
      break;

    default:

      digitalWrite(6,LOW);
      ioport.digitalWrite(8, HIGH);
      break;
    
  }
}

void oscWrite(int note){
 
  dac.writeChannel(DAC_CHANNEL_B, 39158 - (note * 30));
  dac.writeChannel(DAC_CHANNEL_A, 39158 - (note * 30));
  dac.writeChannel(DAC_CHANNEL_C, 39158 - (note * 30));
      
}
