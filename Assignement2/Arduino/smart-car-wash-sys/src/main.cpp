#include <Arduino.h>
#include <Scheduler.h>
#include <WelcomeTask.h>
#include <Hook.h>
#include <LCD.h>

Scheduler schedule;

void setup() {
  Serial.begin(9600);
  schedule.init(200);
  LCD* screen = new LCD();
  screen->init();
  Hook* hook = new Hook();
  Task* welcome = new WelcomeTask(hook);
  welcome->setActive(true);
  schedule.addTask(welcome);
}

void loop() {
  schedule.schedule();
}
