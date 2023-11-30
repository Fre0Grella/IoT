#include "SleepTask.h"


SleepTask::SleepTask() {    
}

void SleepTask::init(int pin, Scheduler scheduler, Task *task) {
    this->pin = pin;
    this->sched = scheduler;
    this->wtask = task;
    Task::init();
}

void SleepTask::tick() {
    attachInterrupt(digitalPinToInterrupt(this->pin),[]() {}, CHANGE);
    clearScheduler();
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(this->pin));
    wtask->setActive(true);
}

void SleepTask::clearScheduler() {
    sched.deactivateAll();
}