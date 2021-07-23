//*************************************************************************************************
// IR-Closet-Lights
//
// By: Dillon Nichols
// https://tinkerer.us
//
// Created in Arduino v1.8.2
//
// Description:
// Using Arduino Leonardo to switch lights using IR with door as trigger
//
// This work is licensed under a Creative Commons Attribution 3.0 Unported License.
// https://creativecommons.org/licenses/by/3.0/
//*************************************************************************************************
// include IR libraries for using NEC protocol
// https://github.com/cyborg5/IRLib2
#include <IRLibSendBase.h>
#include <IRLib_P01_NEC.h>
#include <IRLibCombo.h>

// For debouncing the door switch
// Search for "button tiny simple" in the Arduino Library Manager
// to find the correct library by Michael Adams
//#include <Button.h>

// switch attached to door on pin 12
//Button door(12);

// All on or off
#define ON      0xFF00FF
#define OFF     0xFF807F
// Increase or decrease brightness by 10%
#define INCR    0xFF40BF
#define DECR    0xFFC03F
// Set brightness to these percentages
#define PCT_10  0xFF20DF
#define PCT_40  0xFFA05F
#define PCT_80  0xFF906F
#define PCT_100 0xFFE01F
// Set timer and turn off after this many minutes
#define TIM_10  0xFF10EF
#define TIM_30  0xFF609F
#define TIM_60  0xFF50AF
#define TIM_120 0xFFD02F

// used to fade lights when switching
#define DELAY_ON 200
#define DELAY_OFF 350

IRsend mySender;

void setup() {
  // Nothing to do here...
}

void loop() {
  // Turn on lights
  // Just keep sending until they turn on...
  
  // defaults to 80% on power on
  mySender.send(NEC, ON, 0);
  // increase to 100%
  delay(DELAY_ON);
  mySender.send(NEC, PCT_100, 0);
}
