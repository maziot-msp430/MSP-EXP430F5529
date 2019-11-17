#include "driverlib.h"
#include "maz_interface.h"
#include "maz_led.h"

static MAZBSP_LED_CTRL gLedCtrl[MAZBSP_LED_MAX] =
{
    {
         MAZBSP_LED_GPIOPORT_P1,
         MAZBSP_LED_GPIOPIN0,
         MAZBSP_LED_GPIOLEVEL_HIGH,
         MAZBSP_LED_STATUS_OFF,
    },
    {
         MAZBSP_LED_GPIOPORT_P8,
         MAZBSP_LED_GPIOPIN1,
         MAZBSP_LED_GPIOLEVEL_HIGH,
         MAZBSP_LED_STATUS_OFF,
    },
    {
         MAZBSP_LED_GPIOPORT_P8,
         MAZBSP_LED_GPIOPIN2,
         MAZBSP_LED_GPIOLEVEL_HIGH,
         MAZBSP_LED_STATUS_OFF,
    },
};

int16_t maz_led_init(void)
{
    MAZBSP_LED led = MAZBSP_LED1;
    MAZBSP_LED_CTRL *pctrl;

    for (led = MAZBSP_LED1; led < MAZBSP_LED_MAX; led++)
    {
        /* 设置LED相关GPIO为通用输出模式 */
        pctrl = &gLedCtrl[led];
        GPIO_setAsOutputPin(pctrl->port, pctrl->pin);

        /* 设置LED默认状态 */
        maz_led_set_status(led, pctrl->status);
    }

    return MAZRET_OK;
}

int16_t maz_led_set_status(MAZBSP_LED led, MAZBSP_LED_STATUS status)
{
    /*参数校验待实现uart打印后添加*/
    MAZBSP_LED_CTRL *pctrl = &gLedCtrl[led];

    if (MAZBSP_LED_STATUS_ON == status)
    {
        if (MAZBSP_LED_GPIOLEVEL_HIGH == pctrl->light)
        {
            GPIO_setOutputHighOnPin(pctrl->port, pctrl->pin);
        }
        else if (MAZBSP_LED_GPIOLEVEL_LOW == pctrl->light)
        {
            GPIO_setOutputLowOnPin(pctrl->port, pctrl->pin);
        }
    }
    else if (MAZBSP_LED_STATUS_OFF == status)
    {
        if (MAZBSP_LED_GPIOLEVEL_HIGH == pctrl->light)
        {
            GPIO_setOutputLowOnPin(pctrl->port, pctrl->pin);
        }
        else if (MAZBSP_LED_GPIOLEVEL_LOW == pctrl->light)
        {
            GPIO_setOutputHighOnPin(pctrl->port, pctrl->pin);
        }
    }
    else if (MAZBSP_LED_STATUS_TOGGLE == status)
    {
        GPIO_toggleOutputOnPin(pctrl->port, pctrl->pin);
    }

    return MAZRET_OK;
}

