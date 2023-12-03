#ifndef __CHECK_IN_OUT_AREA_TASK__
#define __CHECK_IN_OUT_AREA_TASK__
#include <Task.h>
#include <Hook.h>

class CheckInOutAreaTask: public Task{
    private:
        Hook* hook;
        Led* led1;
    
    public:
        CheckInOutAreaTask(Hook* hook, LCD* screen);
        void tick();
};

#endif
