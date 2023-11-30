#ifndef __TIMERTASK__
#define __TIMERTASK

#include "Task.h"


class TimerTask: public Task {
    
    public:
        TimerTask();
        void init(int timeToWait, Task* tList, int nTask);
        void tick();
    
    private:
        Task* tList;
        int size;
};
#endif