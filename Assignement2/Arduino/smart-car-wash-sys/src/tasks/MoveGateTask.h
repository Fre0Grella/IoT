#ifndef __MOVEGATETASK__
#define __MOVEGATETASK__

#include "Task.h"
#include "../components/Gate.h"

class MoveGateTask: public Task {
  bool isOpen;
  Gate* gate;

public:

  MoveGateTask(Gate *gate);  
  void tick();
};

#endif
