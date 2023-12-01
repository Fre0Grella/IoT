#include <Arduino.h>
#include "tasks/BlinkTask.h"
#include "utils/Scheduler.h"


Scheduler schedule;

void testBlinkTask() {
  Led* l1 = new Led(13);
  Led* l2 = new Led(12);
  Task* t0 = new BlinkTask(500, l1);
  Task* t1 = new BlinkTask(200, l2);

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

