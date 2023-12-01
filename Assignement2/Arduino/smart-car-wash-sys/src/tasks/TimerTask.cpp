#include "TimerTask.h"

TimerTask::TimerTask(int timeToWait, Task* tList[], int nTask) {    
    Task::init(timeToWait);
    this->tList = tList;
    this->size = nTask;
}

void TimerTask::tick() {
    activateTask(tList, size);
    this->setActive(false);
}

void TimerTask::activateTask(Task* tList[], int listSize) {
    for (int i = 0; i < listSize; i++) {
        tList[i]->setActive(true);
    }
}
