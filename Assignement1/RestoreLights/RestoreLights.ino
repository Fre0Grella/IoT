#include "lib.h"

#define POT A1

long pastTime;

void setup() {
  pastTime = millis();
  // put your setup code here, to run once:
  
}

void loop() {
  idle(1,pastTime);
  
  int check = start(2,pastTime); 
  if(check == 1) {
  Serial.println(check);
  }
  int read = setDifficulty(POT);
  

}
