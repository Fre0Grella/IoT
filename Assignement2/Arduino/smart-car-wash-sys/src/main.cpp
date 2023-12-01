#include <Arduino.h>
#include "tasks/BlinkTask.h"
#include "utils/Scheduler.h"


Scheduler schedule;

void testBlinkTask() {
  Task* t0 = new BlinkTask(13);
  t0->init(500);

  Task* t1 = new BlinkTask(12);
  t1->init(500);

  schedule.addTask(t0);
  schedule.addTask(t1);

}

void testDistanceTask() {
  
}

void setup() {
  Serial.begin(9600);
  schedule.init(100);
  testBlinkTask();
}

void loop() {
  schedule.schedule();
}

