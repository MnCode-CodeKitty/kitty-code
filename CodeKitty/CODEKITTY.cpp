#include "CODEKITTY.h"

#define LSERVO 9
#define RSERVO 10
#define TAIL 6
#define SOUND 3

const int lSpeed = 3000;
const int rSpeed = 0;
const int kittyStop = 1500;

//<<constructor>> setup the servos, speaker, and LED.  set pins to Output
CODEKITTY::CODEKITTY(){
  Servo leftServo, rightServo;
  pinMode(TAIL, OUTPUT);
  pinMode(SOUND, OUTPUT);
  leftServo.attach(LSERVO);
  rightServo.attach(RSERVO);
}

//<<destructor>>
CODEKITTY::~CODEKITTY()

// ---------- MOTOR CONTROL FUNCTIONS  ----------
//Drive Forward
void CODEKITTY::forward(int mvDelay){
  rightServo.writeMicroseconds(rspeed);
  leftServo.writeMicroseconds(lspeed);
  delay(mvDelay);
  CODEKITTY::stop();
}

// Drive Backwards
void CODEKITTY:reverse(int mvDelay){
  rightServo.writeMicroseconds(lspeed);
  leftServo.writeMicroseconds(rspeed);
  delay(mvDelay);
  CODEKITTY::stop();
}

// Drive Right
void CODEKITTY::right(int mvDelay){
  // Motor A Forward
  rightServo.writeMicroseconds(rspeed);
  delay(mvDelay);
  CODEKITTY::stop();
}

// Drive Left
void CODEKITTY::left(int mvDelay){
  leftServo.writeMicroseconds(lspeed);
  delay(mvDelay);
  CODEKITTY::stop();
}

// Stop
void CODEKITTY::stop(){
  rightServo.writeMicroseconds(kittyStop);
  leftServo.writeMicroseconds(kittyStop);
}

// ---------- TAIL LED FUNCTIONS--------
// Tail LED “on” function
void CODEKITTY::tailOn(){
  digitalWrite(TAIL, HIGH);
}

// LED “off” function
void CODEKITTY::tailOff(){
  digitalWrite(TAIL, LOW);
}

// LED “blink” function
void CODEKITTY::tailBlink(int blinkTimes){
  for (int i = 0; i <= blinkTimes; i++)
  {
    digitalWrite(TAIL, HIGH);
    delay(1000);
    digitalWrite(TAIL, LOW);
    delay(1000);
  }
}

// --------- SOUND FUNCTIONS ---------

// notes in the melody:
const int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
const int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

// Beep!
void CODEKITTY::beep(){
  tone(SOUND, NOTE_A4, 250);
  delay(1000);
  noTone(SOUND);
}

void CODEKITTY::note(int OneNote){
  tone(SOUND, OneNote, 250);
  delay(1000);
  noTone(SOUND);
}

// Rising Beep
void CODEKITTY::risingBeep(){
  tone(SOUND, NOTE_C4, 1000);
  delay(750);
  tone(SOUND, NOTE_G4, 1000);
  delay(750);
  tone(SOUND, NOTE_E5, 1000);
  delay(750);
  noTone(SOUND);
}

// Play a little melody
void CODEKITTY::kittyMelody(){
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

