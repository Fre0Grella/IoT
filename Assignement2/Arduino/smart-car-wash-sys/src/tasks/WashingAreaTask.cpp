#include <WashingAreaTask.h>

WashingAreaTask::WashingAreaTask(Hook* hook, LCD* screen) {
    this->hook = hook;
    this->screen = screen;
    setState(WAIT_START);
} 

void WashingAreaTask::tick() {
    switch (state)
    {
    case WAIT_START:
        if(hook->washing()) {
            
        }
        break;
    
    default:
        break;
    }
}




void WashingAreaTask::setState(States state) {
    this->state = state;
    stateTimeStamp = millis();
}

long WashingAreaTask::timeInState() {
    return millis() - stateTimeStamp;
} 