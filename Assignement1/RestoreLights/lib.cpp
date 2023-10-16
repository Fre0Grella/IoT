#include "lib.h"
#include "common.h"
#include <arduino.h>



int setDifficulty() {
    int raw = analogRead(DPOT);
    return raw/256;
}

bool start() {
    long now = millis();
    long delay = buttonPastTime - now;

    if (delay > 20) {
        buttonPastTime = now;
        int buttonState = digitalRead(BUTONE);
        if (buttonState == HIGH) {
            return true;
        }
    }
}

void fading() {
        analogWrite(GOLED, currIntensity);
        currIntensity = currIntensity + fadeAmount;
        if (currIntensity == 0 || currIntensity == 255) {
            fadeAmount = -fadeAmount ;
        }
    delay(15);
}
