#include "ButtonImpl.h"
#include "Led.h"
#include "LCD.h"
#include "Gate.h"
#include "TemperatureSensor.h"
#include "Pir.h"
#include "Sonar.h"

#ifndef __ENV__
#define __ENV__

#define L1 2
#define L2 3
#define L3 4
#define GATE 1
#define PIR 8
#define SONAR_ECHO 9
#define SONAR_TRG 10
#define TEMPSENSOR 11
#define BUT 5

#define N1 5000 
#define N2 4000
#define N3 10
#define N4 5


#define MIN_DIST 5 
#define MAX_DIST 10 
#define MAX_TEMP 40

Led* led1 = new Led(L1);
Led* led2 = new Led(L2);
Led* led3 = new Led(L3);
LCD* screen = new LCD();
Gate* gate = new Gate(GATE);
Button* but = new ButtonImpl(BUT);
Sonar* distance = new Sonar(SONAR_ECHO, SONAR_TRG, 10000);
Pir* detector = new Pir(PIR);
TemperatureSensor* temp = new TemperatureSensor(TEMPSENSOR);


#endif