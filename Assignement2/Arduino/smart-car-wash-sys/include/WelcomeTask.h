#ifndef __WELCOME_TASK__
#define __WELCOME_TASK__
#include <Task.h>
#include <Hook.h>

class WelcomeTask: public Task{
    private:
        Hook* hook;
    public:
        WelcomeTask(Hook *hook);
        void tick();

};

#endif