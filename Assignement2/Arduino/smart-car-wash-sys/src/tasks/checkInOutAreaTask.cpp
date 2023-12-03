#include <checkInOutAreaTask.h>
#include <env.h>
#define MINDIST 5

CheckInOutAreaTask::CheckInOutAreaTask(Hook* hook, LCD* screen, Task* blink) {
    this->hook = hook;
    this->screen = screen;
    this->blink = blink;
    led1 = new Led(L1);
    led2 = new Led(L2);
    setState(SLEEP);
}

void CheckInOutAreaTask::tick() {
    switch (state)
    {
    case SLEEP: 
        if(hook->carPresence()) {
            led1->switchOn();
            screen->print("Welcome!");
            setState(WELCOME);
        }
        break;
    case WELCOME:
        if(timeInState() > N1) {
            led1->switchOff();
            screen->print("Proceed to the Washing Area");
            blink->setActive(true);
            setState(OPEN_GATE);
        }
        break;
    case OPEN_GATE:
        if(hook->carDistance() < MINDIST) {
            setState(CAR_WAIT);
        }
        break;
    case CAR_WAIT:
        Serial.println(hook->carDistance());
        Serial.println(timeInState());
        if(hook->carDistance() < MINDIST && timeInState() > N2) {
            blink->setActive(false);
            if(!led2->isOn()) led2->switchOn();
            screen->print("Ready to Wash");
            hook->enterWashingArea();
            setState(EXIT);
        }else if(timeInState() > N2) {
            setState(OPEN_GATE);
        }
        break; 
    case EXIT:
        if(hook->isProcessFinished()) {
            hook->restartProcess();
            setState(SLEEP);
        }
        break;
    default:
        break;
    }
}

void CheckInOutAreaTask::setState(States state) {
    this->state = state;
    stateTimeStamp = millis();
}

long CheckInOutAreaTask::timeInState() {
    return millis() - stateTimeStamp;
} 