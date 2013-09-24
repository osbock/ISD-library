
/***********************************************************************
 *    Arduino Library fo ISD1932 voice recorder chip/breakout
 *         Kevin Osborn
 *
 *  Initial version will focus on Direct mode
 *   (8 addressable fixed length recordings)
 ************************************************************************/
 //Pin definition constants (may be overridden
 //pin defines for message selector/address
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

// you can redefine these by defining them above #include <ISD.h>
#ifndef S0
#define S0 6
#endif
#ifndef S1
#define S1 7
#endif
#ifndef S2
#define S2 8
#endif
#ifndef S3
#define S3 9
#endif
#ifndef E0
#define E0 2
#endif
#ifndef E1
#define E1 3
#endif
#ifndef E2
#define E2 4
#endif
#ifndef E3
#define E3 5
#endif
//pin define for record/playback pin

#ifndef RP
#define RP 12
#endif

class ISD{
   
public:
   ISD();
   void
     record(int msg),
     play(int msg);

private:
  // mapping of message numbers to pins
   static int messages[];
};
