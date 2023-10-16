#include "gameState.h"
#include "common.h"
#include <stdlib.h>
#include <arduino.h>

void gameState() {
  
  switch(g)
  {
    case settingUpLeds: 
    	turnOnSetup();
        g = generatePattern;
    	break;
    case generatePattern: 
    	randSequence();
        g = turnOffLights;
    	break;
    case turnOffLights:
    	turnOffSequence(genSeq);
        g = turnOnLights;
       	break;
    case turnOnLights:
         pastTime = millis();
         if (index < 4) {
            readInput(genSeq);
            }
         else {
            long now = millis();
            long delay = now - pastTime;

            if (delay < t3 && checkInput()) {
                pastTime = now;
                incScore();
                g = turnOffLights;
            } else {
                g = gameOver;
            }
         }
    	break;
    case gameOver:
        //TODO
        break;
  }
  
}

// Turn on all the led in t1 time.
void turnOnSetup() {
    for (int i = 0; i < NUM_LED; i++) {
        digitalWrite(ledPin[i],HIGH);
        delay(t1/4);
    }
}

void randSequence() {
    srand((int) pastTime);
    int a = 0;
    int i = 1;
    genSeq[0] = rand() % 4;
    do {
        a = rand() % 4;
        bool isPresent = false;
        for (int k : genSeq) {
            if (k == a) {
            isPresent = true;
            }
        }
        if (!isPresent) {
            genSeq[i] = a;
            i++;
        }
    } while (i <= NUM_LED-1);
}

void turnOffSequence(int* seq) {
    for (int i = NUM_LED-1; i >= 0; i--) {
        digitalWrite(ledPin[seq[i]],HIGH);
        delay(t2/NUM_LED);
    }
}

void readInput(int* correctSeq) {
    long now = millis();
    long delay = now - buttonPastTime;
    int bState;
    int i = 0;
    if (delay >= 20) {
        while (i < 4) {
            bState = digitalRead(butPin[i]);
            if (bState == HIGH) {
                currSeq[index] = i;
                index++;
                i = 4;
            }
        }
        buttonPastTime = now;
    }
    return index;
        
}

bool checkInput() {
    bool check = true;

    for (int i = 0; i < NUM_LED; i++) {
        if (genSeq[i] != currSeq[i]) {
            check = false;
        }
    }
    return check;
}

void incScore() {
    score++;
    //TODO increment difficulty
}

