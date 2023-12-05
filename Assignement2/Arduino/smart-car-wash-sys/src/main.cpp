#include <Arduino.h>
#include <Scheduler.h>
#include <BlinkTask.h>
#include <MoveGateTask.h>
#include <CheckInOutAreaTask.h>
#include <WashingAreaTask.h>
#include <Hook.h>
#include <LCD.h>
#include <env.h>

Scheduler schedule;
void setup() {
  Serial.begin(9600);
  schedule.init(90);
  screen->init();
  gate->on();
  Hook* hook = new Hook();
  hook->init();

  Task* blinkTask = new BlinkTask(100, led2);
  blinkTask->setActive(false);

  Task* blinkTaskWash = new BlinkTask(500, led2);
  blinkTaskWash->setActive(false);

  Task* cIOArea = new CheckInOutAreaTask(hook, blinkTask, screen, gate); 
  cIOArea->init(200);

  Task* washArea = new WashingAreaTask(hook, blinkTaskWash, screen);
  washArea->init(200);

  schedule.addTask(cIOArea);
  schedule.addTask(blinkTask);
  schedule.addTask(blinkTaskWash);
  schedule.addTask(washArea);
}

void loop() {
  //Serial.println(distance->getDistance());
  //Serial.println(temperature->detectTemperature());
  //delay(1000);
  schedule.schedule();
  //Serial.println(temp->detectTemperature());
}
