#ifndef __LCD__
#define __LCD__

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Display.h>

class LCD: public Display {
private:
    LiquidCrystal_I2C* lcd; 
    int cursorX;
    int cursorY;
public:
    LCD();
    void init();
    void print(String string);
    void clear();
    void backLighOn();
    void backLightOff();
};
#endif