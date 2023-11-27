#include "DistanceTask.h"

DistanceTask::DistanceTask(int pin) {
  this->pin = pin;    
}
  
void DistanceTask::init(int period, int target) {
  Task::init(period);
  this->target = target;
  this->sonar = new Sonar(this->pin);   
}
  
void DistanceTask::tick() {
    if (this->sonar->getDistance() <= this->target) {

    }
}
