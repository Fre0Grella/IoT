#include <arduino.h>
#include <stdlib.h>
#include "game.h"

#include "common.h"


void gameState() {
  
  switch(g)
  {
    case settingDiff:
    	Serial.println("Go!");
    	gameDiff = diff;
    	increaseDiff();
    	g = setUpArray;
    	break;
    case setUpArray:
    	resetArray();
    	break;
    case generatePattern: 
    	patternCreation(); 
    	break;
    case settingUpGame: 
    	setLedOn();
    	break;
    case turnOffLights:
    	lightsOff();
       	break;
    case turnOnLights:
    	lightsOn();
    	break;
    case gameOver:
    	gameRestarts();
    	break;
  }  
}

void increaseDiff() {
  T2 *= (F - (gameDiff * 0.05));
  T3 *= (F - (gameDiff * 0.05));
}

void resetArray() {
  for (int i=0; i < numLeds; i++) {
    pattern[i] = -1;
    corPatt[i] = -1;
  }
  index = 1;
  g = generatePattern;
}

void patternCreation() {
  int a = 0;
  int i = 0;
  srand((int) millis());
  do {
    a = rand() % numLeds;
    bool isPresent = false;
    for (int k : pattern) {
      if (k == a) {
        isPresent = true;
      }
    }
    if (!isPresent) {
      pattern[i] = a;
      i++;
    }
  } while (i < numLeds);
  pastTimeOn = millis();
  g = settingUpGame;
}

void setLedOn() {
  long now = millis();
  long delay = now - pastTimeOn;
  for (int i : ledPin) {
    digitalWrite(i, HIGH);
  }
  
  if (delay > T1) {
    pastTimeOff = millis();
   	g = turnOffLights;
  }
}

void lightsOff() {
  
  long now = millis();
  long delay = now - pastTimeOff;
  digitalWrite(pattern[delay / (T2 / numLeds)] + LEDONE, LOW);

  if (delay > T2) {
    pastTimePlay = millis();
    g = turnOnLights;
  }
}

void readInput() {
    long now = millis();
    long delay = now - buttonPastTime;
    int i = 0;
    if (delay >= 20) {
        while (i < numLeds) {
            if (digitalRead(butPin[i]) == HIGH) {
              bool isPresent = false;
              for (int a : corPatt) {
                if (a == i) {
                  isPresent = true;
                }
              }
              if(!isPresent) {
                corPatt[numLeds - index] = i;
                index++;
                i = numLeds;
              }
            }
          	i++;
        }
        buttonPastTime = now;
    }
        
}

bool checkInput() {
    bool check = true;

    for (int i = 0; i < numLeds; i++) {
        if (pattern[i] != corPatt[i]) {
            check = false;
        }
    }
    return check;
}

void incScore() {
  score++;
  increaseDiff();
  Serial.print("New Point! Score: ");
  Serial.println(score);
}

void gameLostMessage() {
  analogWrite(GOLED, HIGH);
  pastTimeOver = millis();
  Serial.print("Game Over. Final Score: ");
  Serial.println(score);
  g = gameOver;
}

void lightsOn() {
  
  long now = millis();
  long delay = now - pastTimePlay;
  
  if (index < numLeds + 1) {
    readInput();
  } else {
    if (checkInput()) {
      incScore();
      g = setUpArray;
    } else {
      gameLostMessage();
    }
  }
  
  if (delay > T3) {
    gameLostMessage();
  }
}

void gameRestarts() {

  long now = millis();
  long delay = now - pastTimeOver;
  
  if (delay > 1000) {
  	analogWrite(GOLED, LOW);
  }
  
  if (delay > 10000) {
    T1 = 2000;
  	T2 = 4000;
  	T3 = 8000;
    score = 0;
    s = idle;
    g = settingDiff;
  }
}