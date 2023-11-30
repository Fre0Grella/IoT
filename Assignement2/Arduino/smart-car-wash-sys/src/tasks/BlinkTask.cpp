#include "BlinkTask.h"

BlinkTask::BlinkTask(){
}
  
void BlinkTask::init(int period, Led* led){
  Task::init(period);
  this->led = led; 
}
  
void BlinkTask::tick(){
  if (!led->isOn()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
}
