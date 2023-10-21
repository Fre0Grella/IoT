#include <Arduino.h>
#include "common.h"
#include "gameCore.h"
#include "sleeping.h"
#include "idle.h"

#include <EnableInterrupt.h>

int *diff;

State *s;

void setup()
{
  //TODO AGGIUNGERE TUTTE LE PIN MODE E LE ENABLE INTERRUPT
  pinMode(PIN, INPUT_PULLUP);
  //RICORDA FUNC è UNA FUNZIONE DA ASSOCIARE AD OGNI BOTTONE (FUNZIONA DI LETTURA INPUT)
  //OGNI BOTTONE HA UNA FUNZIONE SEPARATA
  enableInterrupt(PIN, func, CHANGE);

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
