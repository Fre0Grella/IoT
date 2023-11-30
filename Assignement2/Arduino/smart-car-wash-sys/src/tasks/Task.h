#ifndef __TASK__
#define __TASK__

class Task {
  int myPeriod;
  int timeElapsed;
  bool active;
  
public:
  virtual void init(int period){
    myPeriod = period;  
    timeElapsed = 0;
    active = false;
  }

  virtual void init() {
    active = false;
    myPeriod = 0;
    timeElapsed = 0;
  }

  virtual void tick() = 0;

  virtual bool updateAndCheckTime(int basePeriod){
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod){
      timeElapsed = 0;
      return true;
    } else {
      return false; 
    }
  }

  virtual bool isActive(){
    return active;
  }

  virtual void setActive(bool active){
    this->active = active;
  }
  
};

#endif
