#include "Gate.h"

Gate::Gate(int pin)
{
    this->pin = pin;
    motor.attach(this->pin);
    motor.write(close);
}

void Gate::move(int angle)
{
    motor.write(angle);
}

void Gate::openGate()
{
    move(open);
}

void Gate::closeGate()
{
    move(close);
}

bool Gate::isOpen()
{
    return motor.read() == open;
}
