#include "pitches.h"


// notes to play, corresponding to the 4 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3, NOTE_D4
};
int list[25];
int listLength = 0;
const int buttonPinOne = 2;
const int buttonPinTwo = 3;
const int buttonPinThree = 4;
const int buttonPinFour = 5;
const int buttonPinPlay = 6;
const int buttonPinReset = 7;
const int speakerPin = 8;
int buttonStateOne = 0;
int buttonStateTwo = 0;
int buttonStateThree = 0;
int buttonStateFour = 0;
int buttonStatePlay = 0;
int buttonStateReset = 0;

void setup() {
 pinMode(buttonPinOne,INPUT);
 pinMode(buttonPinTwo,INPUT);
 pinMode(buttonPinThree,INPUT);
 pinMode(buttonPinFour,INPUT);
 pinMode(buttonPinPlay,INPUT);
 pinMode(buttonPinReset,INPUT);
 pinMode(speakerPin,OUTPUT);
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  buttonStateThree = digitalRead(buttonPinThree);
  buttonStateFour = digitalRead(buttonPinFour);
  buttonStatePlay = digitalRead(buttonPinPlay);
  buttonStateReset = digitalRead(buttonPinReset);
  if(buttonStateOne == HIGH){
    tone(speakerPin,notes[0],20);
    list[listLength] = notes[0];
    listLength++;
  } else if(buttonStateTwo == HIGH){
    tone(speakerPin,notes[1],20);
    list[listLength] = notes[1];
    listLength++;
  } else if(buttonStateThree == HIGH){
    tone(speakerPin,notes[2],20);
    list[listLength] = notes[2];
    listLength++;
  } else if(buttonStateFour == HIGH){
    tone(speakerPin,notes[3],20);
    list[listLength] = notes[3];
    listLength++;
  } else if(buttonStatePlay == HIGH){
    for(int i = 0; i < 25; i++){
      if(list[i] != 0){
        tone(speakerPin,list[i],20);
      }
    }
  }else if(buttonStateReset == HIGH){
    for(int i = 0; i < 25; i++){
      list[i] = 0;
    }
    listLength = 0;
  }else{
    return;
  }
}
