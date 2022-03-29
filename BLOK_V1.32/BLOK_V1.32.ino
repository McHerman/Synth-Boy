#include <TCA9555.h>
#include "Wire.h"

TCA9555 TCA(0x25);
//TCA9555 TCA2(0x23);

void setup() {

  
  
  Wire.begin();
  Wire.setClock(100000);
  
  //TCA.begin();
  TCA.begin();
  
  TCA.pinMode(1, INPUT);
  
  pinMode(6, OUTPUT); 
 
  
}

void loop() {

  /*
  bool penis = false; 
  
  //digitalWrite(6,LOW);

  for(int pin = 0; pin < 16; pin++){
    if(TCA.digitalRead(pin)){
      pin = 15; 
      //digitalWrite(6,HIGH);
      TCA2.digitalWrite(10, 1); 
      penis = true;
    }
    delay(250);
  }

  if(!penis){
    TCA2.digitalWrite(10, 0); 
  }

  delay(250);

  */

  if(TCA.digitalRead(1)){
    digitalWrite(6,HIGH);
  } else {
    digitalWrite(6, LOW);
  }
}
