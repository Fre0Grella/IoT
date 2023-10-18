int T1 = 2000;
int T2 = 4000;
int T3 = 8000;

float F = 0.95;

long pastTimeOff = 0;
long pastTimeOn = 0;
long pastTimeOver = 0;
long pastTimePlay = 0;
long buttonPastTime = 0;

int score = 0;

int gameDiff = 1;

int index = 1;

enum gameStates { settingDiff, setUpArray, generatePattern, 
                 settingUpGame, turnOffLights, turnOnLights, 
                 gameOver };

gameStates g = settingDiff;

const int numLeds = 4;

int pattern[numLeds];
int corPatt[numLeds];

// Manage the state of the game phase
void gameState();

// Decrease the time of input and the time of shut down by some factor F
void increaseDiff();

// Clean up the array used to store the pattern of shut down of the led 
void resetArray();

// Create the next pattern of the led
void patternCreation();

// Set all the led on in a certain T1 time
void setLedOn();

// Shut down all the led in the determined pattern in a certain t2 time
void lightsOff();

// Manage the Input phase changing the game state
void lightsOn();

// Read and register the input of the player
void readInput();

// Check if the input pattern is correct and return true if so, otherwise false
bool checkInput();

// Increment and notify the new score
void incScore();

// Notify the end of the game and the final score
void gameLostMessage();

// turn on the red led for 1 second and wait 10 second to reset the game
void gameRestarts();
