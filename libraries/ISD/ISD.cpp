/* -------------------------------------------------------------------
 Arduino Library to control ISD1932 breakout board or similar.
  https://www.sparkfun.com/products/10653

 Initial version implements direct control (8 fixed length messages)

 Written by Kevin Osborn /http://baldwisdom.com

 -------------------------------------------------------------------*/
#include <ISD.h>

int ISD::messages[] = {S0,S1,S2,S3,E0,E1,E2,E3};

  // Constructor. perhaps have an argument for direct or address mode.
  
ISD::ISD(){
    //initialize record/play and message selector pins
    pinMode(RP,OUTPUT);
    digitalWrite(RP,HIGH);
    for(int i = 0; i < sizeof(messages)/sizeof(int); i ++)
    {
      pinMode(messages[i],OUTPUT);
      digitalWrite(messages[i],HIGH);
    }
  }
  void ISD::record(int msg)
  {
    int msgpin;
    if (msg > sizeof(messages)/sizeof(int)-1)
    {
      Serial.println("pin not defined");
      return;
    }
    msgpin = messages[msg];
     Serial.print("Recording Message: ");
    Serial.println(msg);
    for (int i = 1 ;i < 4; i++){
      Serial.println(i);
      delay (1000);
    }
    // assert record
    digitalWrite(RP,LOW); // ground is record mode
    delay(100);
    //assert message
    digitalWrite(msgpin,LOW);
    delay(3500);
    digitalWrite(RP,HIGH);
    digitalWrite(msgpin,HIGH);
  }

  void ISD::play(int msg)
  {
    int msgpin;
      if (msg > sizeof(messages)/sizeof(int)-1)
    {
      Serial.println("pin not defined");
      return;
    }
    msgpin = messages[msg];
    Serial.print("playing Message: ");
    Serial.println(msg);
    digitalWrite(RP,HIGH); // make sure we are playing
    digitalWrite(msgpin,LOW);
    delay(200);
    digitalWrite(msgpin,HIGH);
  }
  


