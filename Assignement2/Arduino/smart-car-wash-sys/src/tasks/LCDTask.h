#ifndef __LCDTASK__
#define __LCDTASK__

#include "Task.h"
#include "../components/LCD.h"

class LCDTask: public Task{
    private:
        LCD* screen;
        String message;
    public:
        LCDTask();  
        void init(LCD *screen, String message);  
        void tick();
};

#endif