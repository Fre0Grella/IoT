#ifndef __TIMERTASK__
#define __TIMERTASK

#include "Task.h"


class TimerTask: public Task {
//[TODO] trovare un modo per passargli i task da settare active
    public:
        TimerTask(int timeToWait);
        void init(int period);
        void tick();
    
    private:
        
};
#endif