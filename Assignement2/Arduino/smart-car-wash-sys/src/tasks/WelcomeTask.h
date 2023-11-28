#ifndef __WELCOMETASK__
#define __WELCOMETASK__

#include "Task.h"
#include "../components/LCD.h"
#include "../components/Led.h"

class WelcomeTask: public Task{
    private:
        Led led;
        LCD screen;
    public:
        WelcomeTask(Led led, LCD screen);  
        void init();  
        void tick();
};

#endif