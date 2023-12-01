#include <Arduino.h>
#include "tasks/LightTask.h"
#include "tasks/LCDTask.h"
#include "tasks/SleepTask.h"
#include "tasks/TimerTask.h"
#include "utils/Scheduler.h"
#include "components/Led.h"
#include "components/LCD.h"


Scheduler sched;

void setup() {
  Led* led1 = new Led(3);
  LCD* screen = new LCD();
  Task* lightTask = new LightTask(led1);
  sched.addTask(lightTask);
  Task* screenTask = new LCDTask(screen, "welcome");
  sched.addTask(screenTask);
  Task* list[] = {lightTask, screenTask};
  Task* slpTask = new SleepTask(5,sched,list, 2);
  sched.addTask(slpTask);
  
  
}

void loop() {
  sched.schedule();
}

