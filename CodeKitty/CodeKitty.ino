#include <Servo.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pitches.h"

#define LSERVO 9
#define RSERVO 10
#define TAIL 6
#define SOUND 3

// Declare variables needed for Code Kitty hardware

// Set the kitty speed to a sensible default
// This number will tell the servo how many microseconds to be ON out of 2000
int KITTYLSPEED = 3000;
int KITTYRSPEED = 0;
int KITTYSTOP = 1500;

// HARDWARE PINS - don't change these

// ###################################################################################################
// EDIT YOUR CODE BELOW HERE
// ###################################################################################################

Servo leftServo, rightServo;

// PUT CODE HERE TO HAVE IT RUN ONCE
void setup()
{
  pinMode(TAIL, OUTPUT);
  pinMode(SOUND, OUTPUT);
  leftServo.attach(LSERVO);
  rightServo.attach(RSERVO);

  kittyRisingBeep();
}

// PUT CODE HERE TO HAVE IT RUN REPEATEDLY
void loop()
{

}

// ###################################################################################################
// DO NOT EDIT BELOW THIS LINE
// ###################################################################################################

// ---------- MOTOR CONTROL --------
// Drive Forward
void kittyForward(int mvDelay)
{
  rightServo.writeMicroseconds(KITTYRSPEED);
  leftServo.writeMicroseconds(KITTYLSPEED);
  delay(mvDelay);
  kittyStop();
}

// Drive Backwards
void kittyReverse(int mvDelay)
{
  rightServo.writeMicroseconds(KITTYLSPEED);
  leftServo.writeMicroseconds(KITTYRSPEED);
  delay(mvDelay);
  kittyStop();
}

// Drive Right
void kittyRight(int mvDelay)
{
  // Motor A Forward
  rightServo.writeMicroseconds(KITTYRSPEED);
  delay(mvDelay);
  kittyStop();
}

// Drive Left
void kittyLeft(int mvDelay)
{
  leftServo.writeMicroseconds(KITTYLSPEED);
  delay(mvDelay);
  kittyStop();
}

// Stop
void kittyStop()
{
  rightServo.writeMicroseconds(KITTYSTOP);
  leftServo.writeMicroseconds(KITTYSTOP);
}

// LED “on” function
void kittyLEDon()
{
  digitalWrite(TAIL, HIGH);
}

// ---------- TAIL LED --------
// Tail LED “on” function
void kittyTailOn()
{
  digitalWrite(TAIL, HIGH);
}

// LED “off” function
void kittyTailOff()
{
  digitalWrite(TAIL, LOW);
}

// LED “blink” function
void kittyTailBlink(int blinkTimes)
{
  for (int i = 0; i <= blinkTimes; i++)
  {
    digitalWrite(TAIL, HIGH);
    delay(1000);
    digitalWrite(TAIL, LOW);
    delay(1000);
  }
}

// --------- SOUND FUNCTIONS ---------
//tone

// notes in the melody:
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

// Beep!
void kittyBeep()
{
  tone(SOUND, NOTE_A4, 250);
  delay(1000);
  noTone(SOUND);
}

void kittyNote(int OneNote)
{
  tone(SOUND, OneNote, 250);
  delay(1000);
  noTone(SOUND);
}

// Rising Beep
void kittyRisingBeep()
{
  tone(SOUND, NOTE_C4, 1000);
  delay(750);
  tone(SOUND, NOTE_G4, 1000);
  delay(750);
  tone(SOUND, NOTE_E5, 1000);
  delay(750);
  noTone(SOUND);
}

// Play a little melody
void kittyMelody()
{
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(SOUND, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(SOUND);
  }
}
