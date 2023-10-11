#ifndef RESTORELIGHTS_LIB_H
#define RESTORELIGHTS_LIB_H

int fadeAmount = 5;
int brightness;
int currIntensity = 0;
// Fading led waiting the start of the game.
void idle(int pin, long time);

// Read the analog input of the potentiometer and return a difficulty between 1-4.
int setDifficulty(int pin);

// Check if B1 button is pressed for starting the game.
bool start(int pin, long time);

//TODO
// Put arduino in sleep mode.
void sleepMode(void);

#endif //RESTORELIGHTS_LIB_H
