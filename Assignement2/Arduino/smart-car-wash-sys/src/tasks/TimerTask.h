#ifndef __TIMERTASK__
#define __TIMERTASK

#include "Task.h"


class TimerTask: public Task {
    
    public:
        TimerTask(int timeToWait, Task* tList[], int nTask);
        void tick();
    
    private:
        Task** tList;
        int size;

        void activateTask(Task* tList[], int listSize);
};
#endif