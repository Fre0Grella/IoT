#include "SleepTask.h"

SleepTask::SleepTask(int pin) {
    this->pin = pin;
}

void SleepTask::tick() {
    attachInterrupt(digitalPinToInterrupt(this->pin),[]() {}, CHANGE);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(this->pin));
}