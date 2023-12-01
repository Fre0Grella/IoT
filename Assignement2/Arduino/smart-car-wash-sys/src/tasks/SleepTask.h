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
    Task** tList;
    int listSize;

    void activateTask(Task* tList[], int listSize);
    void clearScheduler();
public:
    SleepTask(int pin, Scheduler sched, Task *tList[], int listSize);
    void tick();
    
};

#endif