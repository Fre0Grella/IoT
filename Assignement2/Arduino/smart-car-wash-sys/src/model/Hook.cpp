#include <Hook.h>
Hook::Hook() {
}

void Hook::init() {
    led1 = new Led(L1);
    led2 = new Led(L2);
    led3 = new Led(L3);
    display = new LCD();
    distance = new Sonar(SONAR);
    detector = new Pir(PIR);
    temp = new TemperatureSensor(TEMPSENSOR);
}

void Hook::printOnLCD(String message) {
    display->print(message);
}

void Hook::lightOn(int led) {
    switch(led) {
        case L1: 
            led1->switchOn();
            break;
        case L2: 
            led2->switchOn();
            break;
        case L3:
            led3->switchOn();
            break;
        default:
            Serial.print("its not a led pin");
            break;
    }
}


