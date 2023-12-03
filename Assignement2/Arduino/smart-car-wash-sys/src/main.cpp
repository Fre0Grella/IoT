#include <Arduino.h>
#include <Scheduler.h>
#include <BlinkTask.h>
#include <MoveGateTask.h>
#include <CheckInOutAreaTask.h>
#include <Hook.h>
#include <LCD.h>
#include <env.h>

Scheduler schedule;



void setup() {
  Serial.begin(9600);
  schedule.init(200);
  
  screen->init();
  Hook* hook = new Hook();
  hook->init();
  

  Task* blinkTask = new BlinkTask(100, L2);
  blinkTask->setActive(false);


  Task* cIOArea = new CheckInOutAreaTask(hook, blinkTask); 
  cIOArea->init(100);
  schedule.addTask(cIOArea);
  schedule.addTask(blinkTask);
}

void loop() {
  schedule.schedule();
}
