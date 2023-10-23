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

  Serial.begin(9600);

  pinMode(GOLED, OUTPUT);

  pinMode(LEDONE, OUTPUT);
  pinMode(LEDTWO, OUTPUT);
  pinMode(LEDTHREE, OUTPUT);
  pinMode(LEDFOUR, OUTPUT);

  for (int but : butPin)
  {
    pinMode(but, INPUT);
    enableInterrupt(
        but, []() {}, CHANGE);
  }

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
    break;
  }
}
