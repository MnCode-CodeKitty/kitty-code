#ifndef CODEKITTY_H
#define CODEKITTY_H

#include <Servo.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pitches.h"

#define LSERVO 9
#define RSERVO 10
#define TAIL 6
#define SOUND 3

class CODEKITTY{
  public:
      CODEKITTY();
      ~CODEKITTY();
      void forward(int mvDelay);
      void right(int mvDelay);
      void left(int mvDelay);
      void stop();
      void reverse(int mvDelay);
      void tailOn();
      void tailOff();
      void tailBlink(int blinkTimes);
      void beep();
      void note(int OneNote);
      void risingBeep();
      void song(int song[]);
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      
}

