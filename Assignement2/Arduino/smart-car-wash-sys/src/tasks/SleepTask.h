#ifndef __SLEEPTASK__
#define __SLEEPTASK

#include "Task.h"
#include "../utils/Scheduler.h"
#include "WelcomeTask.h"
#include <Arduino.h>
#include <avr/sleep.h>
#include <EnableInterrupt.h>

class SleepTask: public Task
{
private:
    int pin;
    Scheduler sched;
    WelcomeTask* wtask;
public:
    SleepTask(int pin, Scheduler sched, WelcomeTask *task);
    void tick();
    void clearScheduler();
};

#endif