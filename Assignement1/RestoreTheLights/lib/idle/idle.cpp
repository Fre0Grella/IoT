#include "../../include/common.h"
#include "idle.h"

long pastTimeWait = 0;
long pastTimeIdle = 0;

int fadeAmount = 5;
int currIntensity = 0;

enum IdleStates
{
    setUpIdle,
    fadeInOut
};

IdleStates e = setUpIdle;

void setDifficulty(int *diff)
{
    int raw = analogRead(DPOT);
    *diff = (raw / 256) + 1;
}

void waitPlayer(State *s, int *diff)
{
    long now = millis();
    long delay = now - pastTimeWait;
    if (delay >= 15)
    {
        analogWrite(GOLED, currIntensity);
        currIntensity = currIntensity + fadeAmount;
        if (currIntensity == 0 || currIntensity == 255)
        {
            fadeAmount = -fadeAmount;
        }
        pastTimeWait = now;
    }
    int buttonState = digitalRead(BUTONE);
    if (buttonState == HIGH)
    {
        setDifficulty(diff);
        digitalWrite(GOLED, LOW);
        e = setUpIdle;
        *s = play;
    }
    if (now - pastTimeIdle >= 10000)
    {
        digitalWrite(GOLED, LOW);
        e = setUpIdle;
        *s = sleep;
    }
}

void setTimer()
{
    Serial.println("Welcome to the Restore the Light Game.");
    Serial.println("Press Key B1 to Start");
    pastTimeIdle = millis();
    pastTimeWait = millis();
    e = fadeInOut;
}

void pulse(State *s, int *diff)
{
    switch (e)
    {
    case setUpIdle:
        setTimer();
        break;
    case fadeInOut:
        waitPlayer(s, diff);
        break;
    }
}
