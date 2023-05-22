/*
  Melanin by Sauti Sol
  Arduino tribute to the legendary song

  circuit:
  - 8 ohm speaker on digital pin 8

  created 22 May 2023
  
  by Kubai Allan

 

 My GitHub Profile:
 https://github.com/Techwhizz47/Music.git

#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,0,
  NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3, NOTE_B3,0,
  NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3, NOTE_FS3,0,
  NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G3,0,
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  3, 8, 8, 8, 3, 8, 8, 8, 3, 6,
  3, 8, 8, 8, 3, 8, 8, 8, 3, 6,
  3, 8, 8, 8, 3, 8, 8, 8, 3, 6,
  3, 8, 8, 8, 3, 8, 8, 8, 3, 6
};

void setup() {
}

void loop() {
// iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 40; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(10);
  }
};
