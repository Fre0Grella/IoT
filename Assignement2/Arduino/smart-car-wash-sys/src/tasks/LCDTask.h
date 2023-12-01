#ifndef __LCDTASK__
#define __LCDTASK__

#include "Task.h"
#include "components/LCD.h"

class LCDTask: public Task{
    private:
        LCD* screen;
        String message;
    public:
        LCDTask(LCD *screen, String message); 
        void tick();
};

#endif