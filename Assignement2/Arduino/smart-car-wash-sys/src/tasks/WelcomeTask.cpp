#include "WelcomeTask.h"

WelcomeTask::WelcomeTask(Led* led, LCD* screen) {
    this->led = led;
    this->screen = screen;
    this->init();
}

void WelcomeTask::init() {
    this->setActive(false);
    Task::init();
}

void WelcomeTask::tick() {
    led->switchOn();
    screen->print("Welcome");
    this->setActive(false);
}