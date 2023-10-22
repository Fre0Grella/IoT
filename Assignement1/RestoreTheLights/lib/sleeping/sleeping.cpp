#include "../../include/common.h"
/*enum SleepState
{
    createInt,
    sleeping
};

SleepState sl = createInt;*/

/*void attInterrupts()
{
    Serial.println("go sleep... ");
    Serial.println("press B4 to wake up");
    Serial.flush();
    attachInterrupt(digitalPinToInterrupt(BUTFOUR), []() {}, RISING);
    sl = sleeping;
}*/

void goSleep(State *s)
{
    delay(1000);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    Serial.println("Wake Up");
    *s = idle;
    //sl = createInt;
    //detachInterrupt(digitalPinToInterrupt(BUTFOUR));
}

/*void sleepMode(State *s)
{
    switch (sl)
    {
    case createInt:
        attInterrupts();
        break;
    case sleeping:
        goSleep(s);
        break;
    }
}*/
