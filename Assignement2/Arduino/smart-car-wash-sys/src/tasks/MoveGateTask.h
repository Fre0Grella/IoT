#ifndef __MOVEGATETASK__
#define __MOVEGATETASK__

#include "Task.h"
#include "../components/Gate.h"

class MoveGateTask: public Task {
  int pin; 
  bool isOpen;
  Gate* gate;

public:

  MoveGateTask(int pin);  
  void init();  
  void tick();
};

#endif
