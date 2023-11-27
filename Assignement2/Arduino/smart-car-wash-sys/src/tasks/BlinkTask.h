#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "../components/Led.h"

class BlinkTask: public Task {
  int pin;
  Led* led;

public:

  BlinkTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
