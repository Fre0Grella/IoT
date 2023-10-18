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

const int butPin[] = {BUTONE, BUTTWO, BUTTHREE, BUTFOUR};
const int ledPin[] = {LEDONE, LEDTWO, LEDTHREE, LEDFOUR};

enum State { idle, sleep, play };

State s = idle;

int diff = 1;
