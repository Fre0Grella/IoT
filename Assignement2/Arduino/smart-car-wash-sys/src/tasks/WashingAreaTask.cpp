#include <WashingAreaTask.h>

WashingAreaTask::WashingAreaTask(Hook* hook) {
    this->hook = hook;
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