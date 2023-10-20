#include "../../include/common.h"

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

enum gameStates
{
    settingDiff,
    setUpArray,
    generatePattern,
    settingUpGame,
    turnOffLights,
    turnOnLights,
    gameOver
};

gameStates g = settingDiff;

const int numLeds = 4;

int pattern[numLeds];
int corPatt[numLeds];

void increaseDiff()
{
    T2 *= (F - (gameDiff * 0.10));
    T3 *= (F - (gameDiff * 0.10));
}

void resetArray()
{
    for (int i = 0; i < numLeds; i++)
    {
        pattern[i] = -1;
        corPatt[i] = -1;
    }
    index = 1;
    g = generatePattern;
}

void patternCreation()
{
    int a = 0;
    int i = 0;
    srand((int)millis());
    do
    {
        a = rand() % numLeds;
        bool isPresent = false;
        for (int k : pattern)
        {
            if (k == a)
            {
                isPresent = true;
            }
        }
        if (!isPresent)
        {
            pattern[i] = a;
            i++;
        }
    } while (i < numLeds);
    pastTimeOn = millis();
    g = settingUpGame;
}

void setLedOn()
{
    long now = millis();
    long delay = now - pastTimeOn;
    for (int i : ledPin)
    {
        digitalWrite(i, HIGH);
    }

    if (delay > T1)
    {
        pastTimeOff = millis();
        g = turnOffLights;
    }
}

void lightsOff()
{

    long now = millis();
    long delay = now - pastTimeOff;
    digitalWrite(ledPin[pattern[delay / (T2 / numLeds)]], LOW);

    if (delay > (T2 + minT2))
    {
        pastTimePlay = millis();
        g = turnOnLights;
    }
}

void readInput()
{
    long now = millis();
    long delay = now - buttonPastTime;
    int i = 0;
    if (delay >= 20)
    {
        while (i < numLeds)
        {
            if (digitalRead(butPin[i]) == HIGH)
            {
                bool isPresent = false;
                for (int a : corPatt)
                {
                    if (a == i)
                    {
                        isPresent = true;
                    }
                }
                if (!isPresent)
                {
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

bool checkInput()
{
    bool check = true;

    for (int i = 0; i < numLeds; i++)
    {
        if (pattern[i] != corPatt[i])
        {
            check = false;
        }
    }
    return check;
}

void incScore()
{
    score++;
    increaseDiff();
    Serial.print("New Point! Score: ");
    Serial.println(score);
}

void lightsGoOff()
{
    for (int i : ledPin)
    {
        digitalWrite(i, LOW);
    }
}

void gameLostMessage()
{
    lightsGoOff();
    digitalWrite(GOLED, HIGH);
    pastTimeOver = millis();
    Serial.print("Game Over. Final Score: ");
    Serial.println(score);
    g = gameOver;
}

void lightsOn()
{

    long now = millis();
    long delay = now - pastTimePlay;

    if (delay > (T3 + minT3))
    {
        gameLostMessage();
    }

    if (index < numLeds + 1)
    {
        readInput();
    }
    else
    {
        if (checkInput())
        {
            incScore();
            g = setUpArray;
        }
        else
        {
            gameLostMessage();
        }
    }
}

void gameRestarts(State *s)
{

    long now = millis();
    long delay = now - pastTimeOver;

    if (delay > 1000)
    {
        digitalWrite(GOLED, LOW);
    }

    if (delay > 10000)
    {
        T1 = 2000;
        T2 = 2000;
        T3 = 5000;
        score = 0;
        *s = idle;
        g = settingDiff;
    }
}

void gameState(State *s, int *diff)
{

    switch (g)
    {
    case settingDiff:
        Serial.println("Go!");
        gameDiff = *diff;
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
        gameRestarts(s);
        break;
    }
}
