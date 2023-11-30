#include "WelcomeTask.h"

WelcomeTask::WelcomeTask(Led* led, LCD* screen) {
    this->led = led;
    this->screen = screen;
    this->init();
}

void WelcomeTask::init() {
    Task::init(0);

}

void WelcomeTask::tick() {
    led->switchOn();
    screen->print("Welcome");
    this->setActive(false);
}