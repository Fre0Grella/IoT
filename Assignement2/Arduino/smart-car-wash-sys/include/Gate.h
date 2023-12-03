#ifndef __GATE__
#define __GATE__

#include <Arduino.h>
#include <ServoMotor.h>
#include <ServoTimer2.h>

class Gate: public ServoMotor {
    public:
        Gate(int pin);
        void on();
        void setPosition(int angle);
        void off();
        void openGate();
        bool isOpen();
        void closeGate();
    private:
        int pin;
        ServoTimer2 motor;
        int open;
        int close;
};



#endif