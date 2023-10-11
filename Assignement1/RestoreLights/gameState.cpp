#include "gameState.h"
#include <stdlib.h>


//Select the pin that are gonna be used.
void pinSetup(int l1, int l2, int l3, int l4, int b1, int b2, int b3, int b4) {
led[0] = l1;
led[1] = l2;
led[2] = l3;
led[3] = l4;
but[0] = b1;
but[1] = b2;
but[2] = b3;
but[3] = b4;
}

// Turn on all the led in t1 time.
void turnOnSetup(long time) {
    long now = millis();
    long delay = now - time;

    digitalWrite(led[0], HIGH);
    digitalWrite(led[1], HIGH);
    if (delay > t1) {
        digitalWrite(led[2], HIGH);
        digitalWrite(led[3], HIGH);
    }
}

// Turn off all the led in random sequence in t2 time and return the turn-off sequence.
int* randTurnOff(long time) {
    return nullptr;
}

// Read the input sequence of the player and check if the sequence is correct.
bool checkInput(int* correctSeq) {
    return false;
}