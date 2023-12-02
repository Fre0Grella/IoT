#include <TemperatureSensor.h>
#include <Arduino.h>

const int SENSOR_ERROR_CELSIUS = 0.005;
const int MV_TO_CELSIUS = 0.48828125;

TemperatureSensor::TemperatureSensor(int pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

float TemperatureSensor::detectTemperature() {
    int sensor_temp_mv = analogRead(A0);
    return sensor_temp_mv * MV_TO_CELSIUS - SENSOR_ERROR_CELSIUS;
}

bool TemperatureSensor::isOverheat(int max_temp) {
    return this->detectTemperature() > max_temp;
}