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
            Serial.println("Ciao");
            if(but->isPressed()) {
                setState(START_WASHING);
            }
        }
        break;
    
    case START_WASHING:
        // this "if" is for displaying the countdown
        if (timeInState() % 1000 == 0) {
            double ltod = N3 - (timeInState()%1000);
            String s = String(ltod, DEC);
            screen->print(s);
        }
    
        if (timeInState() > N3) {
            setState(END_WASHING);
        }

        //TODO add temperature control for enter maintenance mode
    break;

    case END_WASHING:
        led2->switchOff();
        led3->switchOn();
        screen->print("Washing complete, you can leave the area");
        gate->openGate();
    break;

    case WAIT_EXIT:
        //TODO da fare come vecchio task v
        if(hook->carDistance() > MAX_DIST && timeInState() > N4) { 
            hook->exitWashingArea();
            setState(WAIT_START);
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