#include "TimerTask.h"

TimerTask::TimerTask(int timeToWait, Task* tList, int nTask) {
    this->init(timeToWait);
    this->tList = tList;
    this->size = nTask;
}

void TimerTask::init(int period) {
Task::init(period);
}

void TimerTask::tick() {
    for (int i = 0; i < size; i++) {
        tList[i].setActive(true);
    }
}