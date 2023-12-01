#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "Task.h"
#include "../components/Led.h"

class BlinkTask: public Task {
  Led* led;

public:
  BlinkTask(int period, Led *led);  
  void tick();
};

#endif
