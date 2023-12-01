#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin){
  this->pin = pin;    
}
  
void BlinkTask::init(int period){
  Task::init(period);
  led = new Led(pin);   
}
  
void BlinkTask::tick(){
  if (led->isOn()) {
    led->switchOff();
  } else {
    led->switchOn();
  }
}
