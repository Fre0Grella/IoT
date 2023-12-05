#include <TemperatureSensor.h>
#include <Arduino.h>

const int SENSOR_ERROR_CELSIUS = 0.005;
const int MV_TO_CELSIUS = 0.48828125;

TemperatureSensor::TemperatureSensor(int pin)
{
    this->pin = pin;
}

float TemperatureSensor::detectTemperature()
{
    // invio il dato sulla seriale
    return ((analogRead(this->pin)* 0.00488) - 0.5) / 0.01;
}

bool TemperatureSensor::isOverheat(int max_temp)
{
    return this->detectTemperature() > max_temp;
}