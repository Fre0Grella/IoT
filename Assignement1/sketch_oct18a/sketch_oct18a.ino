// C++ code
//
// Start Common File

#include <avr/sleep.h>


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

// --> End Common File

// --> idle.h start



// idle.h end

// Start idle File
long pastTimeWait = 0;
long pastTimeIdle = 0;

int fadeAmount = 5;
int currIntensity = 0;

enum IdleStates { setUpIdle, fadeInOut };

IdleStates e = setUpIdle;

void setDifficulty() {
    int raw = analogRead(DPOT);
    diff = (raw/256) + 1;
}

void waitPlayer() {
    long now = millis();
    long delay = now - pastTimeWait;
    if (delay >= 15) {
      analogWrite(GOLED, currIntensity);
      currIntensity = currIntensity + fadeAmount;
      if (currIntensity == 0 || currIntensity == 255) {
        fadeAmount = -fadeAmount ;
      }
      pastTimeWait = now;
    }
    int buttonState = digitalRead(BUTONE);
    if (buttonState == HIGH) {
      setDifficulty();
      digitalWrite(GOLED, LOW);
      e = setUpIdle;
      s = play;
    }
    if (now - pastTimeIdle >= 10000) {
      digitalWrite(GOLED, LOW);
      e = setUpIdle;
      s = sleep;
    }
}

void setTimer() {
  Serial.println("Welcome to the Restore the Light Game.");
  Serial.println("Press Key B1 to Start");
  pastTimeIdle = millis();
  pastTimeWait = millis();
  e = fadeInOut;
}

void pulse() {
  switch(e)
  {
    case setUpIdle: 
    	setTimer(); 
    	break;
    case fadeInOut:
    	waitPlayer();
    	break;
  }
}

// --> End Idle

// Start play .h

// --> End play .h

// Start play

int T1 = 2000;
int T2 = 3000;
int T3 = 6000;
int minT2 = 1000;
int minT3 = 2000;

float F = 1;

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

void gameState() {
  
  switch(g)
  {
    case settingDiff:
    	Serial.println("Go!");
    	gameDiff = diff;
    	increaseDiff();
    	g = setUpArray;
    	break;
    case setUpArray:
    	resetArray();
    	break;
    case generatePattern: 
    	patternCreation(); 
    	break;
    case settingUpGame: 
    	setLedOn();
    	break;
    case turnOffLights:
    	lightsOff();
       	break;
    case turnOnLights:
    	lightsOn();
    	break;
    case gameOver:
    	gameRestarts();
    	break;
  }  
}

void increaseDiff() {
  T2 *= (F - (gameDiff * 0.10));
  T3 *= (F - (gameDiff * 0.10));
}

void resetArray() {
  for (int i=0; i < numLeds; i++) {
    pattern[i] = -1;
    corPatt[i] = -1;
  }
  index = 1;
  g = generatePattern;
}

void patternCreation() {
  int a = 0;
  int i = 0;
  srand((int) millis());
  do {
    a = rand() % numLeds;
    bool isPresent = false;
    for (int k : pattern) {
      if (k == a) {
        isPresent = true;
      }
    }
    if (!isPresent) {
      pattern[i] = a;
      i++;
    }
  } while (i < numLeds);
  pastTimeOn = millis();
  g = settingUpGame;
}

void setLedOn() {
  long now = millis();
  long delay = now - pastTimeOn;
  for (int i : ledPin) {
    digitalWrite(i, HIGH);
  }
  
  if (delay > T1) {
    pastTimeOff = millis();
   	g = turnOffLights;
  }
}

void lightsOff() {
  
  long now = millis();
  long delay = now - pastTimeOff;
  digitalWrite(ledPin[pattern[delay / ((T2 + minT2) / numLeds)]], LOW);

  if (delay > (T2 + minT2)) {
    pastTimePlay = millis();
    g = turnOnLights;
  }
}

void readInput() {
    long now = millis();
    long delay = now - buttonPastTime;
    int i = 0;
    if (delay >= 20) {
        while (i < numLeds) {
            if (digitalRead(butPin[i]) == HIGH) {
              bool isPresent = false;
              for (int a : corPatt) {
                if (a == i) {
                  isPresent = true;
                }
              }
              if(!isPresent) {
                digitalWrite(ledPin[i], HIGH);
                corPatt[numLeds - index] = i;
                index++;
                i = numLeds;
              }
            }
          	i++;
        }
        buttonPastTime = now;
    }
        
}

bool checkInput() {
    bool check = true;

    for (int i = 0; i < numLeds; i++) {
        if (pattern[i] != corPatt[i]) {
            check = false;
        }
    }
    return check;
}

void incScore() {
  score++;
  increaseDiff();
  Serial.print("New Point! Score: ");
  Serial.println(score);
}

void gameLostMessage() {
  lightsGoOff();
  digitalWrite(GOLED, HIGH);
  pastTimeOver = millis();
  Serial.print("Game Over. Final Score: ");
  Serial.println(score);
  g = gameOver;
}

void lightsGoOff() {
  for (int i : ledPin) {
    digitalWrite(i, LOW);
  }
}

void lightsOn() {
  
  long now = millis();
  long delay = now - pastTimePlay;
  
  if (delay > (T3 + minT3)) {
    gameLostMessage();
  }
  
  if (index < numLeds + 1) {
    readInput();
  } else {
    if (checkInput()) {
      incScore();
      g = setUpArray;
    } else {
      gameLostMessage();
    }
  }
  
}

void gameRestarts() {

  long now = millis();
  long delay = now - pastTimeOver;
  
  if (delay > 1000) {
  	analogWrite(GOLED, LOW);
  }
  
  if (delay > 10000) {
    T1 = 2000;
    T2 = 2000;
    T3 = 5000;
    score = 0;
    s = idle;
    g = settingDiff;
  }
}

// --> End play

// Start Sleep.cpp

enum SleepState { createInt, sleeping};

SleepState sl = createInt;

void sleepMode() {
  switch(sl) {
    case createInt: 
    	attInterrupts(); 
    	break;
    case sleeping:
    	goSleep();
    	break;
  }
}

void attInterrupts() {
  Serial.println("go sleep... ");
  Serial.println("press B4 to wake up");
  Serial.flush();
  attachInterrupt(digitalPinToInterrupt(BUTFOUR), []() {}, RISING); // []() {} -> empty lambda
  sl = sleeping;
}

void goSleep() {
  delay(1000);
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
  sleep_enable();
  sleep_mode();
  sleep_disable();
  Serial.println("Wake Up");
  s = idle;
  sl = createInt;
  detachInterrupt(digitalPinToInterrupt(BUTFOUR));
}

// --> End sleep.cpp

void setup()
{
  Serial.begin(9600);
  
  pinMode(GOLED, OUTPUT);
  
  pinMode(LEDONE, OUTPUT);
  pinMode(LEDTWO, OUTPUT);
  pinMode(LEDTHREE, OUTPUT);
  pinMode(LEDFOUR, OUTPUT);
  
  pinMode(BUTONE, INPUT);
  pinMode(BUTTWO, INPUT);
  pinMode(BUTTHREE, INPUT);
  pinMode(BUTFOUR, INPUT);

}

void loop()
{
  switch(s)
  {
    case idle: 
    	pulse(); 
    	break;
    case play:
    	gameState();
    	break;
    case sleep:
    	sleepMode();
    	break;
  }
  
}
