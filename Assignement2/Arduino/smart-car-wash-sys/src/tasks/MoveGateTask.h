#ifndef __MOVEGATETASK__
#define __MOVEGATETASK__

#include "Task.h"
#include "../components/Gate.h"

class MoveGateTask: public Task {
  int pin; 
  int period;
  bool isOpen;
  Gate* gate;

public:

  MoveGateTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
