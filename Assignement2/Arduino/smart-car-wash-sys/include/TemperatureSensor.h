#ifndef __TEMPERATURESENSOR__
#define __TEMPERATURESENSOR__

class TemperatureSensor {
   public:
    TemperatureSensor(int pin);
    float detectTemperature();
    bool isOverheat(int max_temp);

   private:
    int pin;
};

#endif