#include "MoveGateTask.h"

MoveGateTask::MoveGateTask(int pin) {
  this->pin = pin;    
}
  
void MoveGateTask::init() {
  Task::init();
  this->gate = new Gate(this->pin);
}

void MoveGateTask::tick() {
  this->gate->isOpen() ? this->gate->closeGate() : this->gate->openGate();
  this->setActive(false);
}
