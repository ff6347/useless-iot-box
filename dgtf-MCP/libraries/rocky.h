
int melody_intro [] = {

  NOTE_C4,NOTE_C4,NOTE_C4,
  NOTE_C4,NOTE_C4,NOTE_C4,
  NOTE_C4,NOTE_C4,NOTE_E4,
  NOTE_C4,NOTE_C4,NOTE_C4,

  NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_E4,NOTE_E4,
  NOTE_E4,NOTE_E4,NOTE_G4,
  NOTE_E4,NOTE_E4,NOTE_E4,

  NOTE_D4,NOTE_D4,NOTE_D4,
  NOTE_D4,NOTE_D4,NOTE_D4,
  NOTE_D4,NOTE_D4,
  NOTE_F3,NOTE_E3
};

int noteDurations_intro [] = {
  16,16,8,
  16,16,8,
  16,16,8,
  16,16,8,

  16,16,8,
  16,16,8,
  16,16,8,
  16,16,8,

  18,8,16,
  8,16,8,
  16,8,
  4, 1

};

// the notes in the verse
int melody_verse [] = {

  NOTE_E4,NOTE_G4,NOTE_A4,
  NOTE_A4,NOTE_B4,NOTE_E4,
  NOTE_E4,NOTE_G4,NOTE_A4,
  NOTE_A4,NOTE_B4,NOTE_E4,

  NOTE_D4,NOTE_C4,NOTE_D4,
  NOTE_D4,NOTE_C4,NOTE_D4,
  NOTE_C4,NOTE_D4,NOTE_E4,

  NOTE_C4,NOTE_C4,NOTE_B3,
  NOTE_B3,NOTE_A3,NOTE_A3,
  NOTE_G3,NOTE_B3,NOTE_E5
};


// the duration of the notes in the verse
int noteDurations_verse [] = {
  16,8,1,
  16,8,1,
  16,8,1,
  16,8,1,

  16,16,8,
  16,16,6,
  16,16,4,

  16,16,8,
  16,8,18,
  2,1,1
};

// this is nicer than the intro
// we have definite control over the pauses between notes
// before the pauses where based in the note duration
int pause_between_notes_verse [] = {
  187, 375, 1500,
  187, 375, 1500,
  187, 375, 1500,
  187, 375, 1500,

  187,187,375,
  187,187,450,
  187,187,750,

  187,187,375,
  187,375,200,
  1000,1500,3000
};
