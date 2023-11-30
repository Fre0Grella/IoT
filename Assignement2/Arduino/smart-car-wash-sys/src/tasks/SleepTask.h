#ifndef __SLEEPTASK__
#define __SLEEPTASK

#include "Task.h"
#include "../utils/Scheduler.h"
#include <Arduino.h>
#include <avr/sleep.h>
#include <EnableInterrupt.h>

class SleepTask: public Task
{
private:
    int pin;
    Scheduler sched;
    Task* wtask;
public:
    SleepTask();
    void tick();
    void init(int pin, Scheduler sched, Task *task);
    void clearScheduler();
};

#endif