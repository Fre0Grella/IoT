#include "LightTask.h"

LightTask::LightTask(int pin){
  this->pin = pin;    
}
  
void LightTask::init(){
  Task::init();
  led = new Led(pin);   
}
  
void LightTask::tick(){
  if (!led->isOn()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
  this->setActive(false);
}
