#include <LCDTask.h>

LCDTask::LCDTask(LCD* screen, String message) {
    Task::init();
    this->message = message;
    this->screen = screen;
}

void LCDTask::tick() {
    screen->clear();
    screen->print(this->message);
    this->setActive(false);
}