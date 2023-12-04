#ifndef __CHECK_IN_OUT_AREA_TASK__
#define __CHECK_IN_OUT_AREA_TASK__
#include <Task.h>
#include <Hook.h>
#include <BlinkTask.h>
#include <avr/sleep.h>

class CheckInOutAreaTask: public Task{
    private:
        Hook* hook;
        Task* blink;
        long stateTimeStamp;
        LCD* screen;
        Gate* gate;
        enum States{SLEEP, WELCOME, CAR_WAIT, EXIT}state;
        void setState(States state);
        long timeInState();
    public:
        CheckInOutAreaTask(Hook* hook, Task* blink, LCD* screen, Gate* gate);
        void tick();
};

#endif
