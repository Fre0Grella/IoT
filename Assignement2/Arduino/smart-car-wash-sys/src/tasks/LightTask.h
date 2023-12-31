#ifndef __LIGHTTASK__
#define __LIGHTTASK__

#include "Task.h"
#include "components/Led.h"

class LightTask: public Task {
  Led* led;

public:
  LightTask(Led *led);
  void tick();
};

#endif
