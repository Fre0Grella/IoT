
long pastTimeWait = 0;
long pastTimeIdle = 0;

int fadeAmount = 5;
int currIntensity = 0;

enum IdleStates { setUpIdle, fadeInOut };

IdleStates e = setUpIdle;

// Read and set the difficulty of the game 
void setDifficulty();

// let a led fading in and out waiting for a player input to change state
void waitPlayer();

// Initialize the game and set up a timer
void setTimer();

// Manage the state of the idle phase
void pulse();