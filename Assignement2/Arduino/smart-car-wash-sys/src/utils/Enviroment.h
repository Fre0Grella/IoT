#ifndef __ENVIROMENT__
#define __ENVIROMENT__

#include "../components/Led.h"
#include "../components/LCD.h"
#include "../components/Pir.h"
#include "../components/Gate.h"
#include "../components/Sonar.h"

struct Enviroment
{
    Led* led1 = new Led(2);
    Led* led2 = new Led(3);
    Led* led3 = new Led(4);
    Gate* gate = new Gate(1);
    Pir* pir = new Pir(7);
    LCD* screen = new LCD();
    Sonar* distance = new Sonar(8);

};


#endif