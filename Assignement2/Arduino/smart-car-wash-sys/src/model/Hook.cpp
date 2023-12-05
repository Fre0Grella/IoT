#include <Hook.h>
#include <LightTask.h>
#include <env.h>

Hook::Hook() {
}

void Hook::init() {
    procedureFinished = false;
    inWashingArea = false;
    washCount = 0;
}

void Hook::enterWashingArea() {
    inWashingArea = true;
}

void Hook::exitWashingArea() {
    inWashingArea = false;
    procedureFinished = true;
    washCount++;
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

int Hook::getWashCount() {
    return washCount;
}
