#ifndef __CHECK_IN_OUT_AREA_TASK__
#define __CHECK_IN_OUT_AREA_TASK__
#include <Task.h>
#include <Hook.h>
#include <BlinkTask.h>

class CheckInOutAreaTask: public Task{
    private:
        Hook* hook;
        Task* blink;
        long stateTimeStamp;
        enum States{SLEEP, WELCOME, CAR_WAIT, EXIT}state;
        void setState(States state);
        long timeInState();
    public:
        CheckInOutAreaTask(Hook* hook, Task* blink);
        void tick();
};

#endif
