#ifndef RESTORELIGHTS_LIB_H
#define RESTORELIGHTS_LIB_H

// Fading led waiting the start of the game.
void fading();

// Read the analog input of the potentiometer and return a difficulty between 1-4.
int setDifficulty();

// Check if B1 button is pressed for starting the game.
bool start();

//TODO
// Put arduino in sleep mode.
void sleepMode(void);

#endif //RESTORELIGHTS_LIB_H
