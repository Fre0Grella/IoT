#ifndef __WASHING_AREA_TASK__
#define __WASHING_AREA_TASK__

#include <Task.h>
#include <Hook.h>
#include <BlinkTask.h>

class WashingAreaTask: public Task{
    private:
        Hook* hook;
        enum States{WAIT_START,START_WASHING, END_WASHING, WAIT_EXIT, MAINTENANCE} state;
        long stateTimeStamp;
        void setState(States state);
        long timeInState();

    public:
        WashingAreaTask(Hook* hook);
        void tick();
};

#endif