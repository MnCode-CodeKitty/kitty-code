#include "pitches.h"

// Declare variables needed for Code Kitty hardware

// Set the kitty speed to a sensible default
int kittySpeed = 150;

// MOTORS - don't change these
int AIN1 = 4;
int AIN2 = 5;
int PWMA = 6;
int BIN1 = 7;
int BIN2 = 8;
int PWMB = 9;

// ###################################################################################################
// EDIT YOUR CODE BELOW HERE
// ###################################################################################################


// THESE CAN BE CHANGED TO WHATEVER PIN YOU CONNECTED THEM TO!
int TAIL = 12;
int SOUND = 10;


// PUT CODE HERE TO HAVE IT RUN ONCE
void setup ()
{
  kittyTailBlink(1);
  kittyForward(500);
  kittyBeep();
  kittyNote(NOTE_E5);
  kittyRisingBeep();
  kittyMelody();
}

// PUT CODE HERE TO HAVE IT RUN REPEATEDLY
void loop () 
{
}

// ###################################################################################################
// DO NOT EDIT BELOW THIS LINE
// ###################################################################################################

// ---------- MOTOR CONTROL --------
// Drive Forward
void kittyForward( int mvDelay ){
  
  // Motor A Forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(PWMA, kittySpeed);
      
  // Motor B Forward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(PWMB, kittySpeed);

  delay(mvDelay);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(mvDelay);
}

// Drive Right
void kittyRight( int mvDelay ){
  
  // Motor A Forward
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(PWMA, kittySpeed);

  delay(mvDelay);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(mvDelay);
}

// Drive Left
void kittyLeft( int mvDelay ){
      
  // Motor B Forward 
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  digitalWrite(PWMB, kittySpeed);

  delay(mvDelay);

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);

  delay(mvDelay);
}

// Stop
void kittyStop(){
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

// LED “on” function
void kittyLEDon(){
  digitalWrite(TAIL, HIGH);
}

// ---------- TAIL LED -------- 
// Tail LED “on” function
void kittyTailOn(){
  digitalWrite(TAIL, HIGH);
}

// LED “off” function
void kittyTailOff(){
  digitalWrite(TAIL, HIGH);
}

// LED “blink” function
void kittyTailBlink( int blinkTimes ){
   for (int i=0; i <= blinkTimes; i++){
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
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

// Beep!
void kittyBeep() {
  tone(SOUND, NOTE_A4, 250);
  delay(1000);
  noTone(SOUND);
}

void kittyNote( int OneNote ) {
  tone(SOUND, OneNote, 250);
  delay(1000);
  noTone(SOUND);
}

// Rising Beep
void kittyRisingBeep() {
  tone(SOUND, NOTE_C4, 1000);
  delay(750);
  tone(SOUND, NOTE_G4, 1000);
  delay(750);
  tone(SOUND, NOTE_E5, 1000);
  delay(750);
  noTone(SOUND);
}

// Play a little melody
void kittyMelody() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

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

