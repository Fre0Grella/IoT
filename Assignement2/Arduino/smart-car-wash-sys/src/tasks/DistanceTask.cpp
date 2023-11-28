#include "DistanceTask.h"

DistanceTask::DistanceTask(int pin) {
  this->pin = pin;    
}
  
void DistanceTask::init(int period, int target, bool min, int timeOut) {
  Task::init(period);
  this->target = target;
  this->elapsedTime = 0;
  this->min = min;
  this->timeOut = timeOut;
  this->period = period;
  this->valid = false;
  this->sonar = new Sonar(this->pin);
}
  
void DistanceTask::tick() {
  valid = min ? this->sonar->getDistance() <= target : this->sonar->getDistance() >= target;
  if (valid) {
    elapsedTime += this->period;
    if (elapsedTime >= timeOut) {
      //here it should terminate the sonar and do whatever it needs to do if the sonar was revealing MINDIST or MAXDIST
      if (min) {

      } else {
        
      }
      this->setActive(false);
    }
  } else {
    elapsedTime = 0;
  }
}
