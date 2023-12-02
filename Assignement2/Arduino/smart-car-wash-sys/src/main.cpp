#include <Arduino.h>
#include <Scheduler.h>
#include <WelcomeTask.h>
#include <Hook.h>

Scheduler schedule;

void setup() {
  Serial.begin(9600);
  schedule.init(200);
  Hook* hook = new Hook();
  Task* welcome = new WelcomeTask(hook);
  welcome->setActive(true);
  schedule.addTask(welcome);
}

void loop() {
  schedule.schedule();
}
