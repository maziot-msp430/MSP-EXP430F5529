#include "driverlib.h"
#include "maz_led.h"
#include "maz_key.h"

void delay(int ms)
{
    volatile int t = ms;
    while (t > 0)
    {
        t--;
    }
}

int mode = 0;

int main(void)
{
    WDT_A_hold(WDT_A_BASE);
    maz_led_init();
    maz_key_init();

    while (1)
    {
        if (mode == 1)
        {
            maz_led_set_status(MAZBSP_LED1, MAZBSP_LED_STATUS_TOGGLE);
            delay(25000);
            maz_led_set_status(MAZBSP_LED2, MAZBSP_LED_STATUS_TOGGLE);
            delay(25000);
            maz_led_set_status(MAZBSP_LED3, MAZBSP_LED_STATUS_TOGGLE);
            delay(25000);
        }
        else
        {
            maz_led_set_status(MAZBSP_LED1, MAZBSP_LED_STATUS_TOGGLE);
            maz_led_set_status(MAZBSP_LED2, MAZBSP_LED_STATUS_TOGGLE);
            maz_led_set_status(MAZBSP_LED3, MAZBSP_LED_STATUS_TOGGLE);
            delay(25000);
        }
    }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    mode = 1;
    P1IFG &= ~BIT7;
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
    mode = 0;
    P2IFG &= ~BIT2;
}

