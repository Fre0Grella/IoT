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
        attachInterrupt(digitalPinToInterrupt(PIR),[]() {}, CHANGE);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        sleep_disable();
        detachInterrupt(digitalPinToInterrupt(PIR));
        if(!led1->isOn()){
            led1->switchOn();
        }
        screen->print("Welcome!");
        setState(WELCOME);
        break;
    case WELCOME:
        if(timeInState() > N1) {
            led1->switchOff();
            blink->setActive(true);
            screen->print("Proceed to the Washing Area");
            gate->openGate();
            setState(CAR_WAIT);
        }
        break;
    case CAR_WAIT:
        //Serial.println(hook->carDistance());
        //Serial.println(timeInState());
        Serial.println(distance->getDistance());
        if(distance->getDistance() <= MIN_DIST && timeInState() >= N2 && gate->isOpen()) {
            blink->setActive(false);
            led2->switchOn();
            screen->print("Ready to Wash");
            gate->closeGate();
            hook->enterWashingArea();
            led3->switchOff();
            setState(EXIT);
        } else if(distance->getDistance() >= MAX_DIST && timeInState() >= N4) {
            blink->setActive(false);
            led2->switchOff();
            gate->closeGate();
            hook->restartProcess();
            setState(SLEEP);
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