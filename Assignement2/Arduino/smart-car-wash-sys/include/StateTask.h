#ifndef __STATE_TAKS__
#define __STATE_TASK__

#include <Task.h>
#include "Arduino.h"

class StateTask: public Task {

public:
  StateTask() 
    : Task(){
  }

  void setState(int s){
      state = s;
      stateTimestamp = millis();
  }

  long elapsedTimeInState(){
      return millis() - stateTimestamp;
  }
  
private:
  int state;
  long stateTimestamp;
};

#endif