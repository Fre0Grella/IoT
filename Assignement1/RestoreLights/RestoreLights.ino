#include <arduino.h>

#include "common.h"
#include "idle.h"
#include "game.h"
#include "sleep.h"

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

}

void loop()
{
  switch(s)
  {
    case idle: 
    	pulse(); 
    	break;
    case play:
    	gameState();
    	break;
    case sleep:
    	sleepMode();
    	break;
  }
  delay(20);
}
