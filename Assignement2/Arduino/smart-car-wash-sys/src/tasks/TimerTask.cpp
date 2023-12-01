#include "TimerTask.h"

TimerTask::TimerTask(int timeToWait, Task* tList, int nTask) {    
    Task::init(timeToWait);
    this->tList = tList;
    this->size = nTask;
}

void TimerTask::tick() {
    for (int i = 0; i < size; i++) {
        tList[i].setActive(true);
    }
    this->setActive(false);
}