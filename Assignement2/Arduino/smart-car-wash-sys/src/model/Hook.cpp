#include <Hook.h>
#include <LightTask.h>
#include <env.h>

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
    procedureFinished = true;
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
