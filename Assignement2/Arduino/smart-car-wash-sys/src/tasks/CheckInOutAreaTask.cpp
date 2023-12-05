#include <CheckInOutAreaTask.h>
#include <env.h>


CheckInOutAreaTask::CheckInOutAreaTask(Hook* hook, Task* blink, LCD* screen, Gate* gate) {
    this->hook = hook;
    this->blink = blink;  
    this->screen = screen;
    this->gate = gate;
    this->elapsedTime = 0;
    this->min = false;
    this->max = false;
    setState(SLEEP);
}

void CheckInOutAreaTask::tick() {
    float dist;
    switch (state) {
    case SLEEP:
        
        screen->backLightOff();
        screen->clear();
        attachInterrupt(digitalPinToInterrupt(PIR),[]() {}, CHANGE);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        sleep_disable();
        detachInterrupt(digitalPinToInterrupt(PIR));
        Serial.println("Wake Up");
        screen->backLighOn();
        if(!led1->isOn()){
            led1->switchOn();
        }
        screen->print("Welcome!");
        setState(WELCOME);
        Serial.println("Welcome area");
        break;
    case WELCOME:
        
        if(timeInState() > N1) {
            led1->switchOff();
            blink->setActive(true);
            screen->print("Proceed to the Washing Area");
            gate->openGate();
            this->elapsedTime = millis();
            setState(CAR_WAIT);
            Serial.println("Wait for the car to enter the washing area");
            this->elapsedTime = millis();
        }
        break;
    case CAR_WAIT:
        dist = distance->getDistance();
        
        if(dist <= MIN_DIST && dist >= 0) {
            this->min = true;
            if (this->max) {
                this->max = false;
                this->elapsedTime = millis();
            }
            if ((millis() - this->elapsedTime) >= N2) {
                blink->setActive(false);
                led2->switchOn();
                screen->print("Ready to Wash");
                gate->closeGate();
                hook->enterWashingArea();
                Serial.println("Enter the Washing area, wait to start");
                led3->switchOff();
                setState(EXIT);
            }
        } else if(dist >= MAX_DIST || dist == NO_OBJ_DETECTED) {
            this->max = true;
            if(this->min) {
                this->min = false;
                this->elapsedTime = millis();
            }
            if((millis() - this->elapsedTime) >= N4) {
                blink->setActive(false);
                led2->switchOff();
                gate->closeGate();
                hook->restartProcess();
                setState(SLEEP);
            }
        } else {
            this->max = false;
            this->min = false;
            this->elapsedTime = millis();
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