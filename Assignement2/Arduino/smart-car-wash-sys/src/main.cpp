#include <Arduino.h>
#include <Scheduler.h>
#include <BlinkTask.h>
#include <checkInOutAreaTask.h>
#include <Hook.h>
#include <LCD.h>
#include <env.h>

Scheduler schedule;

void setup() {
  Serial.begin(9600);
  schedule.init(200);
  LCD* screen = new LCD();
  screen->init();
  Hook* hook = new Hook();
  hook->init();

  Task* blinkTask = new BlinkTask(100, L2);
  blinkTask->setActive(false);

  Task* cIOArea = new CheckInOutAreaTask(hook, screen, blinkTask); 
  cIOArea->init(100);
  schedule.addTask(cIOArea);
  schedule.addTask(blinkTask);
}

void loop() {
  schedule.schedule();
}
