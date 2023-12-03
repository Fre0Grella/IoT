#include <BlinkTask.h>
#include <env.h>

BlinkTask::BlinkTask(int period, int pin){
  Task::init(period);
  this->led = new Led(L2); 
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
