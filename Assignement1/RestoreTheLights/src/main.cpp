#include <Arduino.h>
#include "common.h"
#include "gameCore.h"
#include "sleeping.h"
#include "idle.h"

#include <EnableInterrupt.h>

int diff;
State s;

void setup()
{
  for (int but : butPin) {
    pinMode(but, INPUT);
    enableInterrupt(but, []() {}, CHANGE);
  }
  
  Serial.begin(9600);

  pinMode(GOLED, OUTPUT);

  pinMode(LEDONE, OUTPUT);
  pinMode(LEDTWO, OUTPUT);
  pinMode(LEDTHREE, OUTPUT);
  pinMode(LEDFOUR, OUTPUT);

    //TODO CANCELLARE
  /*pinMode(BUTONE, INPUT);
  pinMode(BUTTWO, INPUT);
  pinMode(BUTTHREE, INPUT);
  pinMode(BUTFOUR, INPUT);*/

  diff = 1;
  s = idle;
}

void loop()
{
  switch (s)
  {
  case idle:
    pulse();
    break;
  case play:
    gameState();
    break;
  case sleep:
    goSleep();
    //sleepMode(s);
    break;
  }
}
