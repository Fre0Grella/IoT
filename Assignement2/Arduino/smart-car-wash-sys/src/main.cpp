#include <Arduino.h>
#include "tasks/SleepTask.h"
#include "tasks/WelcomeTask.h"
#include "tasks/TimerTask.h"
#include "utils/Scheduler.h"
#include "components/Led.h"
#include "components/LCD.h"


Scheduler sched;

void setup() {
  Led* led1 = new Led(3);
  LCD* screen = new LCD();
  Task* wlcTask = new WelcomeTask(led1, screen);
  Task* slpTask = new SleepTask(5,sched,wlcTask);
  sched.addTask(slpTask);
  sched.addTask(wlcTask);
  
}

void loop() {
  sched.schedule();
}

