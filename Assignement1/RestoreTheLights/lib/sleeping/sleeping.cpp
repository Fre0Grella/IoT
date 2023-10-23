#include "../../include/common.h"

void goSleep()
{
    Serial.println("go sleep... ");
    Serial.println("press any button to wake up");
    Serial.flush();
    delay(1000);

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_mode();
    sleep_disable();
    Serial.println("Wake Up");
    s = idle;
}
