#include <Hook.h>
#include <LightTask.h>
Hook::Hook() {
}

void Hook::init() {
    distance = new Sonar(SONAR_ECHO, SONAR_TRG, 10000);
    detector = new Pir(PIR);
    temp = new TemperatureSensor(TEMPSENSOR);
}

bool Hook::carPresence() {
    detector->sync();
    Serial.println(detector->isDetected());
    return detector->isDetected();
}

float Hook::carDistance() {
    //Serial.print(distance->getDistance());
    //return distance->getDistance();
    return 4;
}




