#ifndef __SLEEPTASK__
#define __SLEEPTASK

#include "Task.h"
#include <EnableInterrupt.h>

class SleepTask: public Task
{
private:
    int pin;
public:
    SleepTask(int pin);
    void tick();

};

#endif