#ifndef __GATE__
#define __GATE__

#include <Arduino.h>
#include "ServoMotor.h"
#include <ServoTimer2.h>

class Gate: public ServoMotor {
    public:
        Gate(int pin);
        void move(int angle);
        void openGate();
        void closeGate();
        bool isOpen();
    private:
        int pin;
        ServoTimer2 motor;
        const int millisec = 10;
        const int open = 180;
        const int close = 90;


};



#endif