#include <Arduino.h>
#include "Gate.h"

Gate::Gate(int pin) {
    this->pin = pin;
    motor.attach(this->pin);
    motor.write(close);
}

void Gate::move(int angle) {
    int i = motor.read();
    if (i > angle) {
        for (i; i > angle; i--) {
            motor.write(i);
            delay(millisec);
        }
    } else {
        for (i; i < angle; i++) {
            motor.write(i);
            delay(millisec);
        }
    }
}

void Gate::openGate() {
move(open);
}

void Gate::closeGate() {
move(close);
}
        
bool Gate::isOpen() {
    return motor.read() == open;
}
