#include <arduino.h>
#include <stdio.h>
#include "idle.h"

#include "common.h"

void setDifficulty() {
    int raw = analogRead(DPOT);
    diff = (raw/256) + 1;
}

void waitPlayer() {
    long now = millis();
    long delay = now - pastTimeWait;
    if (delay >= 15) {
      analogWrite(GOLED, currIntensity);
      currIntensity = currIntensity + fadeAmount;
      if (currIntensity == 0 || currIntensity == 255) {
        fadeAmount = -fadeAmount ;
      }
      pastTimeWait = now;
    }
    int buttonState = digitalRead(BUTONE);
    if (buttonState == HIGH) {
      setDifficulty();
      digitalWrite(GOLED, LOW);
      e = setUpIdle;
      s = play;
    }
    if (now - pastTimeIdle >= 10000) {
      digitalWrite(GOLED, LOW);
      e = setUpIdle;
      s = sleep;
    }
}

void setTimer() {
  Serial.println("Welcome to the Restore the Light Game.");
  Serial.println("Press Key B1 to Start");
  pastTimeIdle = millis();
  pastTimeWait = millis();
  e = fadeInOut;
}

void pulse() {
  switch(e)
  {
    case setUpIdle: 
    	setTimer(); 
    	break;
    case fadeInOut:
    	waitPlayer();
    	break;
  }
}