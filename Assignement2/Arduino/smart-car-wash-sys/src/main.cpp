#include <Arduino.h>
#include "tasks/BlinkTask.h"
#include "utils/Scheduler.h"
#include "tasks/LightTask.h"
#include "utils/Enviroment.h"
#include "components/Led.h"


Scheduler schedule;

void testBlinkTask() {
  Task* t0 = new BlinkTask(500, led1);
  Task* t1 = new BlinkTask(200, led2);
  t0->setActive(true);
  t1->setActive(true);
  schedule.addTask(t0);
  schedule.addTask(t1);
}

void testLightTask() {
  Task* lightTask = new LightTask(led2);
  Task* lightTask2 = new LightTask(led1);
  lightTask->setActive(true);
  lightTask2->setActive(true);
  schedule.addTask(lightTask);
  schedule.addTask(lightTask2);
}

void testDistanceTask() {
  
}

void setup() {
  Serial.begin(9600);
  schedule.init(200);
  testBlinkTask();
}

void loop() {
  schedule.schedule();
}
