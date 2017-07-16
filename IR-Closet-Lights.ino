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
#include <IRLibSendBase.h>
#include <IRLib_P01_NEC.h> 
#include <IRLibCombo.h>

// switch attached to door is on pin 12
#define DOOR    12

// states for button on door
#define OPEN     0
#define CLOSED   1

// All on or off
#define ON      0xFF00FF
#define OFF     0xFF807F
// Increase or decrease brightness by 10%
#define INCR    0xFF40BF
#define DECR    0xFFC03F
// Set brightness to these percentages
#define PCT_10  0xFF20DF
#define PCT_40  0xFFA05F
#define PCT_80  0XFF906F
#define PCT_100 0XFFE01F
// Set timer and turn off after this many minutes
#define TIM_10  0XFF10EF
#define TIM_30  0XFF609F
#define TIM_60  0XFF50AF
#define TIM_120 0XFFD02F

IRsend mySender;

void setup() {
  // switch is pulled up
  pinMode(DOOR, INPUT_PULLUP);
}

void loop() {
  // start by turning on
  mySender.send(NEC, ON, 0);
  // loop until door is closed
  while (digitalRead(DOOR) == OPEN);

  // turn off lights
  mySender.send(NEC, OFF, 0);
  // loop until door is opened again
  while (digitalRead(DOOR) == CLOSED);
}

