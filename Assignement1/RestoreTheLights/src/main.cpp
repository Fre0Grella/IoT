#include <Arduino.h>
#include "common.h"
#include "gameCore.h"
#include "sleeping.h"
#include "idle.h"

int *diff;

State *s;

void setup()
{
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

  *diff = 1;
  *s = idle;
}

void loop()
{
  switch (*s)
  {
  case idle:
  Serial.println(*s);
    pulse(s, diff);
    break;
  case play:
    gameState(s, diff);
    break;
  case sleep:
    sleepMode(s);
    break;
  }
  delay(20);
}
