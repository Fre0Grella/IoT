#include <Hook.h>
#include <LightTask.h>
Hook::Hook() {
}

void Hook::init() {
    
    procedureFinished = false;
    inWashingArea = false;
}

void Hook::enterWashingArea() {
    inWashingArea = true;
}

void Hook::exitWashingArea() {
    inWashingArea = false;
}

bool Hook::washing() {
    return inWashingArea;
}

void Hook::finishProcess() {
    procedureFinished = true;
} 

void Hook::restartProcess() {
    procedureFinished = false;
}

bool Hook::isProcessFinished() {
    return procedureFinished;
}

bool Hook::carPresence() {
    detector->sync();
    Serial.println(detector->isDetected());
    return detector->isDetected();
}

float Hook::carDistance() {
    //Serial.print(distance->getDistance());
    //return distance->getDistance();
    return 4;
}




