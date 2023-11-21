#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "../components/Led.h"

class BlinkTask: public Task {

  int pin;
  Light* led;
  enum { ON, OFF} state;

public:

  BlinkTask(int pin);  
  void init(int period);  
  void tick();
};

#endif

