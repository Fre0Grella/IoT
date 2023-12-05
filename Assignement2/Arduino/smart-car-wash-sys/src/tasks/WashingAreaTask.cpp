#include <WashingAreaTask.h>

WashingAreaTask::WashingAreaTask(Hook* hook, Task* blink, LCD* screen) {
    this->hook = hook;
    this->blink = blink; 
    this->screen = screen;
    this->elapsedTime = 0;
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
                this->elapsedTime = millis();
                setState(START_WASHING);
            }
        }
        break;
    
    case START_WASHING:
        //countdown
        screen->print(String((N3 - timeInState())/1000, DEC));

        if (timeInState() >= N3) {
            blink->setActive(false);
            setState(END_WASHING);
        }

        //TODO here it should write the temperature on the Gui

        //goes in maintainance if it is in overheat for N4 seconds
        if (temperature->isOverheat(MAX_TEMP)) {
            if (millis() - this->elapsedTime >= N4) {
                setState(MAINTENANCE);
            }
        } else {
            this->elapsedTime = millis();
        }
        break;

    case END_WASHING:
        led2->switchOff();
        led3->switchOn();
        screen->print("Washing complete, you can leave the area");
        gate->on();
        gate->openGate();
        setState(WAIT_EXIT);
        break;

    case WAIT_EXIT:
        if(distance->getDistance() >= MAX_DIST && timeInState() >= N4) { 
            hook->exitWashingArea();
            led3->switchOff();
            gate->closeGate();
            setState(WAIT_START);
        } 
        break;
    case MAINTENANCE:
        screen->print("Detected a Problem - Please Wait");

        //TODO here it should display Maintainance required on the PC.

        //TODO if the button in pressed on the gui it does those two thing.
        this->elapsedTime = millis();
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