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
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  Serial.println(F("Every time you press a key is a serial monitor we will send."));
}

void loop() {
  if (Serial.read() != -1) {
    // send a code every time a character is received from the 
    // serial port. You could modify this sketch to send when you
    // push a button connected to an digital input pin.
    // Substitute values and protocols in the following statement
    // for device you have available.
    mySender.send(NEC,ON,0);  // turn on
    Serial.println(F("Sent signal."));
  }
}

