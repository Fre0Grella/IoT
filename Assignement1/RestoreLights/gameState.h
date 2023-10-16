#ifndef RESTORELIGHTS_GAMESTATE_H
#define RESTORELIGHTS_GAMESTATE_H



// Turn on all the led in t1 time.
void turnOnSetup();

// Turn off all the led in the determined sequence in t2 time.
void turnOffSequence(int* seq);

// Elaborate a random sequence.
void randSequence();

// Read the input of the player and check if is correct, return 1 if correct, 0 if wrong, -1 if waiting for an input.
void readInput(int* correctSeq);

void gameState();

void incScore();

bool checkInput();

#endif
