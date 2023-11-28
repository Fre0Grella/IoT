#ifndef __LIGHTTASK__
#define __LIGHTTASK__

#include "Task.h"
#include "../components/Led.h"

class LightTask: public Task {
  int pin;
  Led* led;

public:

  LightTask(int pin);  
  void init();  
  void tick();
};

#endif
