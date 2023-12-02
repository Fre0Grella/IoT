#include <WelcomeTask.h>
#include <env.h>

WelcomeTask::WelcomeTask(Hook* hook) {
    this->hook = hook;
}

void WelcomeTask::tick() {
    hook->lightOn(L1);
    hook->printOnLCD("Welcome!");
}