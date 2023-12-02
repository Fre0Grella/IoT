#include <DistanceTask.h>

/** third parameter indicates if the sonar needs to check whether it should 
 * check if the object distance is min than target (min = true)
 * or it is grater than target (min = false) */
DistanceTask::DistanceTask(int period, int target, bool min, int timeOut, Sonar *sonar) {
  Task::init(period);
  this->target = target;
  this->elapsedTime = 0;
  this->min = min;
  this->timeOut = timeOut;
  this->period = period;
  this->sonar = sonar;
}

  
void DistanceTask::tick() {
  bool valid = min ? this->sonar->getDistance() <= target : this->sonar->getDistance() >= target;
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
