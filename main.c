#include "driverlib.h"
#include "maz_led.h"

void delay(int ms)
{
    volatile int t = ms;
    while(t > 0)
    {
        t--;
    }
}

int main(void)
{
    WDT_A_hold(WDT_A_BASE);
    maz_led_init();

    while (1)
    {
        maz_led_set_status(MAZBSP_LED1, MAZBSP_LED_STATUS_TOGGLE);
        delay(25000);
        maz_led_set_status(MAZBSP_LED2, MAZBSP_LED_STATUS_TOGGLE);
        delay(25000);
        maz_led_set_status(MAZBSP_LED3, MAZBSP_LED_STATUS_TOGGLE);
        delay(25000);
    }
}
