#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "../components/Sonar.h"

class DistanceTask: public Task {
  int pin;
  int target; 
  int period;
  int elapsedTime;
  int timeOut;
  bool min;
  bool valid;
  Sonar* sonar;

public:

  DistanceTask(int pin);  
  void init(int period, int target, bool min, int timeOut);  
  void tick();
};

#endif
