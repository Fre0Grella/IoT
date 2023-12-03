#ifndef __HOOK__
#define __HOOK__


#include <Led.h>
#include <Sonar.h>
#include <LCD.h>
#include <Pir.h>
#include <ServoMotor.h>
#include <Gate.h>
#include <TemperatureSensor.h>
#include <env.h>

class Hook{
    public: 
        Hook();
        void init();
        bool carPresence();
        float carDistance();

    private:
        Sonar* distance;
        Pir* detector;
        Gate* gate;
        TemperatureSensor* temp;
         
};


#endif