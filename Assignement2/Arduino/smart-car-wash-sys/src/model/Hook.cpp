#include <Hook.h>
#include <LightTask.h>
Hook::Hook() {
}

void Hook::init() {
    distance = new Sonar(SONAR);
    detector = new Pir(PIR);
    temp = new TemperatureSensor(TEMPSENSOR);
}

bool Hook::carPresence() {
    Serial.println("car detected");
    return detector->isDetected();
}




