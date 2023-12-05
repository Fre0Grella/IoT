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
            but->sync();
            if(but->isPressed()) {
                led2->switchOff();
                blink->setActive(true);
                setState(START_WASHING);
                
                this->elapsedTime = millis();
            }
        }
        break;
    
    case START_WASHING:
        
        screen->print(String((N3 - timeInState())/1000, DEC));
        Serial.println(temperature->detectTemperature());
        if (timeInState() > N3) {
            blink->setActive(false);
            setState(END_WASHING);
            Serial.println("Washing complete");
        }
        if (temperature->isOverheat(MAX_TEMP)){
            
            if (millis() - elapsedTime >= N4) {
                setState(MAINTENANCE);
                blink->setActive(false);
                //Serial.println("OVERHEAT going in maintenance mode");
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
        Serial.println("Wait for the car to exit the area");
        this->elapsedTime = millis();
        break;

    case WAIT_EXIT:
        
        if(distance->getDistance() >= MAX_DIST || distance->getDistance() == NO_OBJ_DETECTED) {
            if (millis() - elapsedTime > N4) {
            hook->exitWashingArea();
            Serial.print("Car washed:");
            Serial.println(hook->getWashCount());
            Serial.println("Going to Sleep");
            led3->switchOff();
            gate->closeGate();
            setState(WAIT_START);
            }
        } else {
            elapsedTime = millis();
        }
        break;
    case MAINTENANCE:
        Serial.println("Maintenance required");
        screen->print("Detected a Problem - Please Wait");
        delay(3000);
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