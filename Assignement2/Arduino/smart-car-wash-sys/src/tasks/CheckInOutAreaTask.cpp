#include <CheckInOutAreaTask.h>
#include <env.h>

CheckInOutAreaTask::CheckInOutAreaTask(Hook* hook, Task* blink, LCD* screen, Gate* gate) {
    this->hook = hook;
    this->blink = blink;  
    this->screen = screen;
    this->gate = gate;
    setState(SLEEP);
}

void CheckInOutAreaTask::tick() {
    switch (state)
    {
    case SLEEP:
    //TODO aggiungere una vera sleep 
        if(hook->carPresence()) {
            if(!led1->isOn()){
                led1->switchOn();
            }
            screen->print("Welcome!");
            setState(WELCOME);
        }
        break;
    case WELCOME:
        if(timeInState() > N1) {
            led1->switchOff();
            screen->print("Proceed to the Washing Area");
            blink->setActive(true);
            gate->on();
            gate->openGate();
            delay(1000);
            setState(CAR_WAIT);
        }
        break;
    case CAR_WAIT:
        //Serial.println(hook->carDistance());
        //Serial.println(timeInState());

        if(hook->carDistance() <= MIN_DIST && timeInState() >= N2 && gate->isOpen()) {
            blink->setActive(false);
            led2->switchOn();
            screen->print("Ready to Wash");
            gate->closeGate();
            delay(1000);
            gate->off();
            hook->enterWashingArea();
            led3->switchOff();
            setState(EXIT);
        } else if(hook->carDistance() >= MAX_DIST && timeInState() >= N4) {
            hook->restartProcess();
            gate->closeGate();
            setState(SLEEP);
        }
        break;
    case EXIT:
        if(hook->isProcessFinished()) {
            hook->restartProcess();
            setState(SLEEP);
        }
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