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

enum State { idle, sleep, play,};

State s = idle;
int score = 0;
int dif = 0;
long pastTime;
long buttonPastTime;
int ledPin[] = {LEDONE, LEDTWO, LEDTHREE, LEDFOUR};
int butPin[] = {BUTONE, BUTTWO, BUTTHREE, BUTFOUR};
int genSeq[NUM_LED];
int currSeq[NUM_LED];



int fadeAmount = 5;
int brightness;
int currIntensity = 0;
long pTimeStart;

long t1 = 2000, t2=5000, t3=10000;
long inputPastTime;
int index=0;
enum gameStates { settingUpLeds, generatePattern, turnOffLights, turnOnLights, gameOver};
gameStates g = settingUpLeds;

#endif
