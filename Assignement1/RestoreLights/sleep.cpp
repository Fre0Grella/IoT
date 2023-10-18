#include <arduino.h>
#include <avr/sleep.h>
#include "sleep.h"

#include "common.h"


void sleepMode() {
  switch(sl) {
    case createInt: 
    	attInterrupts(); 
    	break;
    case sleeping:
    	goSleep();
    	break;
  }
}

void attInterrupts() {
  Serial.println("go sleep... ");
  Serial.println("press B4 to wake up");
  Serial.flush();
  attachInterrupt(digitalPinToInterrupt(BUTFOUR), wakeUp, RISING);
  sl = sleeping;
}

void goSleep() {
  delay(1000);
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); 
  sleep_enable();
  sleep_mode(); 
}

void wakeUp() {
  Serial.println("Wake Up");
  s = idle;
  sl = createInt;
  sleep_disable(); 
  detachInterrupt(digitalPinToInterrupt(BUTFOUR));
}
