#include "lib.h"
#include <arduino.h>


int setDifficulty(int pin) {
    int raw = AnalogRead(pin);
    return raw/256;
}

bool start(int pin, long time) {
    long now = millis();
    long delay = time - now;
    if (delay >= 20) {

        int buttonState = digitalRead(pin);
        if (buttonState == HIGH) {
            return true;
        }
    }
}

void Idle(int pin, long time) {
    long now = millis();
    long delay = time - now;

    if (delay >= 15) {
        analogWrite(LED_PIN, currIntensity);
        currIntensity = currIntensity + fadeAmount;
        if (currIntensity == 0 || currIntensity == 255) {
            fadeAmount = -fadeAmount ;
        }
    }
}
//
// Created by marco on 09/10/2023.
//
