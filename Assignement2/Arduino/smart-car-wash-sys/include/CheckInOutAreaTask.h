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
        /**time on detection*/
        long elapsedTime;
        /**variable used to check if the distance detector was detecting for MINDIST when it goes directly on MAXDIST*/
        bool min;
        /**variable used to check if the distance detector was detecting for MAXDIST when it goes directly on MINDIST*/
        bool max;
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
