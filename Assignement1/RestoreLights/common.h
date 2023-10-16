#ifndef RESTORELIGHTS_COMMON_H
#define RESTORELIGHTS_COMMON_H
// Start Common File
#define NUM_LED 4
#define DPOT A0

#define GOLED 6

#define BUTONE 3
#define BUTTWO 4
#define BUTTHREE 5
#define BUTFOUR 2

#define LEDONE 8
#define LEDTWO 9
#define LEDTHREE 10
#define LEDFOUR 11

enum State { idle, sleep, play, gameOver };

State s = idle;
int score = 0;
long pastTime;
long buttonPastTime;
int ledPin[] = {LEDONE, LEDTWO, LEDTHREE, LEDFOUR};
int butPin[] = {BUTONE, BUTTWO, BUTTHREE, BUTFOUR};
int genSeq[NUM_LED];
int currSeq[NUM_LED];


#endif
