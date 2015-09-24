// This #include statement was automatically added by the Particle IDE.
#include "clickButton.h"
#include "pitches.h"
#include "rocky.h"
// see https://github.com/pkourany/clickButton
// for further info
// author: Fabian "fabiantheblind" Morón Zirfas
// License: ISC
//

int rocky(String command);
const int piezopin = D0;
const int buttonpin = D6;
const int outpin = D7;
const int potipin = A0;
const int notes_intro = 34; // how many notes in intro
const int notes_verse = 30; // how many notes in verse

int buttonresults = 0;
int potiresult = 0;
bool toggleAnalog = false;
ClickButton button(buttonpin, LOW, CLICKBTN_PULLUP);

void setup() {
  Particle.publish("dgtf-MCP");
  Particle.function("dgtf-rocky",rocky);
  Particle.variable("dgtf-poti", &potiresult, INT);
  pinMode(buttonpin, INPUT_PULLUP);
  Serial.begin(9600);
  button.debounceTime = 20;
  button.multiclickTime = 250;
  button.longClickTime = 1000;
  // read the value once on setup
  // so we don't get a jump in loop
  potiresult = analogRead(potipin);
}

int rocky (String command){
  if(command == "play"){
    play_intro();
    play_verse();
    return 1;
  }else{
    return -1;
  }
}



// this is the intro
// TODO make pauses like in the verse
void play_intro(){

  for (int thisNote = 0; thisNote < notes_intro; thisNote++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations_intro[thisNote];
    // play the according note with the according duration
    tone(piezopin, melody_intro[thisNote],noteDuration);
    // The time between each tone defined herein.
    // The time is variable, we use the original note value.
    // If you want to it to go slower so multiply up.
    // For example, note the duration * 1.30 is 30% slower:

    int pauseBetweenNotes = noteDuration * 3;

    delay(pauseBetweenNotes);
  }
  noTone(piezopin); // stop the music
}


// this is the same as the intro
// but we have better control over the pauses between notes
void play_verse(){
  for (int i = 0; i < notes_verse; i++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations_verse[i];

    tone(piezopin, melody_verse[i], noteDuration);

    // The time between each tone defined in an array.
    int pause = pause_between_notes_verse[i];
    delay(pause);
  }
  noTone(piezopin); // stop the music
}


void loop() {
  potiresult = analogRead(potipin);
  if(toggleAnalog == true){
  Serial.print("Analog Value is: ");
  Serial.println(potiresult);
  }

  button.Update();
  // Save click codes in buttonresults, as click codes are reset at next
  // Update()
  if (button.clicks != 0) {
    buttonresults = button.clicks;
  }

  if (button.clicks == 1) {
    // if we had a click publish the result
    Serial.println("SINGLE click");
    bool published = Particle.publish("dgtf-MCP-button-click", "1");
    if (published == false) {
      Serial.println("dgtf-MCP-button-click failded to publish");
    }
  }

  if(button.clicks == -1){
    Serial.println("SINGLE long click");
    // a single long click toggles the analog output
    // to the Serial
    toggleAnalog = !toggleAnalog;
  }
  buttonresults = 0;
  delay(5);
}
