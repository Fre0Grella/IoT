#include "SleepTask.h"


SleepTask::SleepTask(int pin, Scheduler scheduler, WelcomeTask *task) {
    this->pin = pin;
    this->sched = scheduler;
    this->wtask = task;
}

void SleepTask::tick() {
    attachInterrupt(digitalPinToInterrupt(this->pin),[]() {}, CHANGE);
    clearScheduler();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(this->pin));
    wtask->init();
}

void SleepTask::clearScheduler() {
    sched.deactivateAll();
}