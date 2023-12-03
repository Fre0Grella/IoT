#include <CheckInOutAreaTask.h>
#include <env.h>

CheckInOutAreaTask::CheckInOutAreaTask(Hook* hook, Task* blink) {
    this->hook = hook;
    this->blink = blink;  
    setState(SLEEP);
}

void CheckInOutAreaTask::tick() {
    switch (state)
    {
    case SLEEP:
    //TODO aggiungere una vera sleep 
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
            gate->openGate();
            setState(CAR_WAIT);
        }
        break;
    case CAR_WAIT:
        Serial.println(hook->carDistance());
        Serial.println(timeInState());
        //TODO da fare bene come il vecchio task 
        if(hook->carDistance() < MIN_DIST && timeInState() > N2) {
            blink->setActive(false);
            if(!led2->isOn()) led2->switchOn();
            screen->print("Ready to Wash");
            gate->closeGate();
            hook->enterWashingArea();
            setState(EXIT);
        }else if(hook->carDistance() > MAX_DIST && timeInState() > N2) { //TODO da fare come vecchio task
            setState(SLEEP);
        }
        break; 
    case EXIT:
        gate->closeGate();
        led3->switchOff();
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