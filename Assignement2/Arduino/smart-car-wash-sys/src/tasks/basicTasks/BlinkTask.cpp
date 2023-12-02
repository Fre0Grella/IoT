#include <BlinkTask.h>

BlinkTask::BlinkTask(int period, Led* led){
  Task::init(period);
  this->led = led; 
  state = OFF;
}

void BlinkTask::tick(){
  switch (state){
    case OFF:
      led->switchOn();
      state = ON; 
      break;
    case ON:
      led->switchOff();
      state = OFF;
      break;
  }
}
