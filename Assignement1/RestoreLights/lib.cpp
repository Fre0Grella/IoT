#include "lib.h"
#include "common.h"
#include <arduino.h>

long pTimeStart = millis();

int setDifficulty() {
    int raw = AnalogRead(DPOT);
    return raw/256;
}

bool start() {
    now = millis();
    delay = buttonPastTime - now;

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
