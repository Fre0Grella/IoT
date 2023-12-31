#include "MoveGateTask.h"

MoveGateTask::MoveGateTask(Gate *gate) {
  Task::init();
  this->gate = gate;
}

void MoveGateTask::tick() {
  this->gate->isOpen() ? this->gate->closeGate() : this->gate->openGate();
  this->setActive(false);
}
