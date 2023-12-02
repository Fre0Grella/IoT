#include <LightTask.h>

LightTask::LightTask(Led *led){
  Task::init();
  this->led = led;  
}
  
void LightTask::tick(){
  if (!led->isOn()) {
    led->switchOn();
  } else {
    led->switchOff();
  }
  this->setActive(false);
}
