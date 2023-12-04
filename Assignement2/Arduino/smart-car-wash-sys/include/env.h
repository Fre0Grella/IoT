#include "ButtonImpl.h"
#include "Led.h"
#include "LCD.h"
#include "Gate.h"
#include "TemperatureSensor.h"
#include "Pir.h"
#include "Sonar.h"

#ifndef __ENV__
#define __ENV__

#define L1 8
#define L2 3
#define L3 4
#define GATE 6 
#define PIR 2
#define SONAR_ECHO 9
#define SONAR_TRG 10
#define TEMPSENSOR 11
#define BUT 5

#define N1 5000 
#define N2 4000
#define N3 7000
#define N4 3000


#define MIN_DIST 0.05
#define MAX_DIST 0.15 
#define MAX_TEMP 40

static Led* led1 = new Led(L1);
static Led* led2 = new Led(L2);
static Led* led3 = new Led(L3);
static LCD* screen = new LCD();
static Gate* gate = new Gate(GATE);
static Button* but = new ButtonImpl(BUT);
static Sonar* distance = new Sonar(SONAR_ECHO, SONAR_TRG, 10000);
//static Pir* detector = new Pir(PIR);
static TemperatureSensor* temp = new TemperatureSensor(TEMPSENSOR);

#endif