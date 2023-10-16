#include "lib.h"
#include "gameState.h"
#include "gameOverState.h"
#include "common.h"



void setup() {
  buttonPastTime = millis();
  pastTime = millis();
  Serial.begin(9600);
  
  pinMode(GOLED, OUTPUT);
  
  pinMode(LEDONE, OUTPUT);
  pinMode(LEDTWO, OUTPUT);
  pinMode(LEDTHREE, OUTPUT);
  pinMode(LEDFOUR, OUTPUT);
  
  pinMode(BUTONE, INPUT);
  pinMode(BUTTWO, INPUT);
  pinMode(BUTTHREE, INPUT);
  pinMode(BUTFOUR, INPUT);
  
}

void loop() {
  switch(s)
  {
    case idle: 
    	fading();
      if(start()) {
        s = play;
      } 
    	break;
    case play:
    	gameState();
    	break;
    case sleep:
    	break;
  }
}
