#ifndef RESTORELIGHTS_GAMESTATE_H
#define RESTORELIGHTS_GAMESTATE_H

long t1 = 2000, t2=5000, t3=10000;
long inputPastTime;
int index=0;
enum gameStates { settingUpLeds, generatePattern, turnOffLights, turnOnLights, gameOver};
gameStates g = settingUpLeds;

// Turn on all the led in t1 time.
void turnOnSetup();

// Turn off all the led in the determined sequence in t2 time.
void turnOffSequence(int* seq);

// Elaborate a random sequence.
void randSequence();

// Read the input of the player and check if is correct, return 1 if correct, 0 if wrong, -1 if waiting for an input.
int readInput(int* correctSeq, int index);

#endif
