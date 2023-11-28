#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include "Task.h"
#include "../components/Sonar.h"

class DistanceTask: public Task {
  int pin;
  int target;
  Sonar* sonar;

public:

  DistanceTask(int pin);  
  void init(int period, int target);  
  void tick();
};

#endif
