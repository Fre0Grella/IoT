#ifndef __DISTANCETASK__
#define __DISTANCETASK__

#include <Task.h>
#include <Sonar.h>

class DistanceTask: public Task {
  int target; 
  int period;
  int elapsedTime;
  int timeOut;
  bool min;
  Sonar* sonar;

public:
  DistanceTask(int period, int target, bool min, int timeOut, Sonar *sonar);   
  void tick();
};

#endif
