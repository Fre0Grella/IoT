#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

class ServoMotor {
    public:
    virtual void move(int angle) = 0;
};

#endif