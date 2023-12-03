#ifndef __WASHING_AREA_TASK__
#define __WASHING_AREA_TASK__

#include <Task.h>
#include <Hook.h>
#include <BlinkTask.h>

class WashingAreaTask: public Task{
    private:
        Hook* hook;
        LCD* screen;
        enum States{WAIT_START} state;
        long stateTimeStamp;
        void setState(States state);
        long timeInState();

    public:
        WashingAreaTask(Hook* hook, LCD* screen);
        void tick();
};

#endif