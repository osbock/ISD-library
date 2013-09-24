/*----------------------------------------------------------
  example program for ISD sound recorder library
    take Serial commands to record and playback sounds
 -----------------------------------------------------------*/
#include <ISD.h>

ISD isd = ISD();

void setup() {
  Serial.begin(115200);
  Serial.println("enter a message number to play or record or r/p");
}

// globals
int msg =0;

void loop() {
  if (Serial.available() != 0)
  {
    char c = Serial.read();
    if (c >= '0' && c <='8')
    {
      msg = (int)(c- '0');

      Serial.print("msg selected: ");
      Serial.println(msg);
    }
    else if (c == 'r')
    {
      isd.record(msg);
    }
     else if (c == 'p')
       isd.play(msg);
  }
}

