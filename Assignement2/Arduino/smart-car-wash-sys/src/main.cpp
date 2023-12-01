#include <Arduino.h>
#include "tasks/BlinkTask.h"
#include "utils/Scheduler.h"
#include "tasks/LightTask.h"
#include "utils/Enviroment.h"
#include "components/Led.h"


Scheduler schedule;

void testBlinkTask() {
  Led* l1 = new Led(3);
  Led* l2 = new Led(2);
  Task* t0 = new BlinkTask(500, l1);
  t0->setActive(true);
  Task* t1 = new BlinkTask(500, l2);
  t1->setActive(true);
  schedule.addTask(t0);
  schedule.addTask(t1);
}

void testLightTask() {
  Task* lightTask = new LightTask(led2);
  lightTask->setActive(true);
  schedule.addTask(lightTask);
}

void testDistanceTask() {
  
}

void setup() {
  Serial.begin(9600);
  schedule.init(200);
  testLightTask();
}

void loop() {
  schedule.schedule();
}
