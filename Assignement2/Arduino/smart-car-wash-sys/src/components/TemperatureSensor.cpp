#include <TemperatureSensor.h>
#include <Arduino.h>

const int SENSOR_ERROR_CELSIUS = 0.005;
const int MV_TO_CELSIUS = 0.48828125;

TemperatureSensor::TemperatureSensor(int pin) {
    this->value = analogRead(pin);
}

float TemperatureSensor::detectTemperature() {
    int value_in_mV = 4.8876 * value;
    double value_in_C = value_in_mV * 0.1;
    return value_in_C;
}

bool TemperatureSensor::isOverheat(int max_temp) {
    return this->detectTemperature() > max_temp;
}