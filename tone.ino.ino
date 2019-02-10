#include "pitches.h"


// notes to play, corresponding to the 4 sensors:
int notes[] = {
  NOTE_A4, NOTE_B4, NOTE_C3, NOTE_D4
};
static int list[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static int listLength = 0;
static int lastButton = 0;
const int buttonPinOne = 2;
const int buttonPinTwo = 3;
const int buttonPinThree = 4;
const int buttonPinFour = 5;
const int buttonPinPlay = 6;
const int buttonPinReset = 7;
const int speakerPin = 8;
const int ledOnePin = 9;
const int ledTwoPin = 10;
const int ledThreePin = 11;
const int ledFourPin = 12;
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
 pinMode(ledOnePin,OUTPUT);
 pinMode(ledTwoPin, OUTPUT);
 pinMode(ledThreePin, OUTPUT);
 pinMode(ledFourPin, OUTPUT);
}

void loop() {
  buttonStateOne = digitalRead(buttonPinOne);
  buttonStateTwo = digitalRead(buttonPinTwo);
  buttonStateThree = digitalRead(buttonPinThree);
  buttonStateFour = digitalRead(buttonPinFour);
  buttonStatePlay = digitalRead(buttonPinPlay);
  buttonStateReset = digitalRead(buttonPinReset);
  if(buttonStateOne == HIGH && lastButton != 1){
    tone(speakerPin,notes[0],100);
    digitalWrite(ledOnePin, HIGH);
    delay(100);
    digitalWrite(ledOnePin, LOW);
    list[listLength] = NOTE_A4;
    listLength++;
    delay(25);
    lastButton = 1;
  } else if(buttonStateTwo == HIGH && lastButton != 2){
    tone(speakerPin,notes[1],100);
    digitalWrite(ledTwoPin, HIGH);
    delay(100);
    digitalWrite(ledTwoPin, LOW);
    list[listLength] = NOTE_B4;
    listLength++;
    delay(25);
    lastButton = 2;
  } else if(buttonStateThree == HIGH && lastButton != 3){
    tone(speakerPin,notes[2],100);
    digitalWrite(ledThreePin, HIGH);
    delay(100);
    digitalWrite(ledThreePin, LOW);
    list[listLength] = NOTE_C3;
    listLength++;
    delay(25);
    lastButton = 3;
  } else if(buttonStateFour == HIGH && lastButton != 4){
    tone(speakerPin,notes[3],100);
    digitalWrite(ledFourPin, HIGH);
    delay(100);
    digitalWrite(ledFourPin, LOW);
    list[listLength] = NOTE_D4;
    listLength++;
    delay(25);
    lastButton = 4;
  } else if(buttonStatePlay == HIGH){
    for(int i = 0; i < 25; i++){
      if(list[i] != 0){
        tone(speakerPin,list[i],100);
        if(list[i] == NOTE_A4){
          digitalWrite(ledOnePin, HIGH);
          delay(100);
          digitalWrite(ledOnePin, LOW);
        } else if(list[i] == NOTE_B4){
          digitalWrite(ledTwoPin, HIGH);
          delay(100);
          digitalWrite(ledTwoPin, LOW);
        } else if(list[i] == NOTE_C3){
          digitalWrite(ledThreePin, HIGH);
          delay(100);
          digitalWrite(ledThreePin, LOW);
        } else if(list[i] == NOTE_D4){
          digitalWrite(ledFourPin, HIGH);
          delay(100);
          digitalWrite(ledFourPin, LOW);
        }
        delay(500);
      }
      lastButton = 0;
    }
  }else if(buttonStateReset == HIGH){
    for(int i = 0; i < 25; i++){
      list[i] = 0;
    }
    listLength = 0;
    lastButton = 0;
  }else{
    delay(100);
    lastButton = 0;
  }
}
