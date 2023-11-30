#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin){
  this->pin = pin;    
}
  
void BlinkTask::init(int period){
  Task::init(period);
  led = new Led(pin);   
}
  
void BlinkTask::tick(){
<<<<<<< HEAD
  if (led->isOn()) {
=======
  if (!led->isOn()) {
    led->switchOn();
  } else {
>>>>>>> task-creation
    led->switchOff();
  } else {
    led->switchOn();
  }
}
