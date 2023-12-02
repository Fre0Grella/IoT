/*
#include "SleepTask.h"


SleepTask::SleepTask(int pin, Scheduler scheduler, Task *tList[], int listSize) {    
    this->pin = pin;
    this->sched = scheduler;
    this->tList = tList;
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
    activateTask(tList, listSize);
}

void SleepTask::clearScheduler() {
    sched.deactivateAll();
}

void SleepTask::activateTask(Task* tList[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        tList[i]->setActive(true);
    }
    
}
*/