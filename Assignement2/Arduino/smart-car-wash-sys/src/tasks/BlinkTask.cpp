#include "BlinkTask.h"

BlinkTask::BlinkTask(int period, Led* led){
  this->led = led;
  Task::init(period);
}
  
void BlinkTask::tick(){
  if (!led->isOn()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
}
