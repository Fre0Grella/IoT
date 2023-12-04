#include <WashingAreaTask.h>

WashingAreaTask::WashingAreaTask(Hook* hook, Task* blink, LCD* screen) {
    this->hook = hook;
    this->blink = blink; 
    this->screen = screen;
    setState(WAIT_START);
}

void WashingAreaTask::tick() {
    switch (state)
    {
    case WAIT_START:
        if(hook->washing()) {
            Serial.println("Ciao");
            but->sync();
            if(but->isPressed()) {
                blink->setActive(true);
                setState(START_WASHING);
            }
        }
        break;
    
    case START_WASHING:
        // this "if" is for displaying the countdown
        screen->print(String((N3 - timeInState())/1000, DEC));
    
        if (timeInState() > N3) {
            blink->setActive(false);
            setState(END_WASHING);
        }

        //TODO add temperature control for enter maintenance mode
        break;

    case END_WASHING:
        led2->switchOff();
        led3->switchOn();
        screen->print("Washing complete, you can leave the area");
        gate->on();
        gate->openGate();
        delay(1000);
        setState(WAIT_EXIT);
        break;

    case WAIT_EXIT:
    //This way should follow the assignement 
        if(hook->carDistance() >= MAX_DIST) {
            if (timeInState() >= N4) {
                hook->exitWashingArea();
            led3->switchOff();
            setState(WAIT_START);    
            }
        } else {
            setState(WAIT_EXIT);
        }
        break;

    case MAINTENANCE:
        screen->print("Detected a Problem - Please Wait");

        //TODO Write the gui for the maintenance

        setState(START_WASHING);
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