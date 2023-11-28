#include "Sonar.h"

#include "Arduino.h"

Sonar::Sonar(int echoP) : echoPin(echoP) {
  pinMode(echoPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  temperature = 20; // default value
}

void Sonar::setTemperature(float temp){
  temperature = temp;
}
float Sonar::getSoundSpeed(){
  return 331.5 + 0.6*temperature;   
}

float Sonar::getDistance(){
    digitalWrite(echoPin,LOW);
    delayMicroseconds(3);
    digitalWrite(echoPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(echoPin,LOW);
    
    float tUS = pulseIn(echoPin, HIGH);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS / 1000.0 / 1000.0 / 2;
        float d = t*getSoundSpeed();
        return d;
    }
}

