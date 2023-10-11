#ifndef RESTORELIGHTS_GAMESTATE_H
#define RESTORELIGHTS_GAMESTATE_H


int led[4];
int but[4];
int score=0;

long t1, t2, t3;

//Select the pin that are gonna be used.
void pinSetup(int l1, int l2, int l3, int l4, int b1, int b2, int b3, int b4);

// Turn on all the led in t1 time.
void turnOnSetup(long time);

// Turn off all the led in random sequence in t2 time and return the turn-off sequence.
int* randTurnOff(long time);

// Read the input sequence of the player and check if the sequence is correct.
bool checkInput(int* correctSeq);

#endif
