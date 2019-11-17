#include "driverlib.h"
#include "maz_interface.h"
#include "maz_key.h"

static MAZBSP_KEY_CTRL gKeyCtrl[MAZBSP_KEY_MAX] =
{
    {
         MAZBSP_KEY_GPIOPORT_P1,
         MAZBSP_KEY_GPIOPIN7,
         MAZBSP_KEY_GPIOLEVEL_LOW,
         MAZBSP_KEY_MODE_INTERRUPT,
    },
    {
         MAZBSP_KEY_GPIOPORT_P2,
         MAZBSP_KEY_GPIOPIN2,
         MAZBSP_KEY_GPIOLEVEL_LOW,
         MAZBSP_KEY_MODE_INTERRUPT,
    },
};

int16_t maz_key_init(void)
{
    MAZBSP_KEY key = MAZBSP_KEY1;
    MAZBSP_KEY_CTRL *pctrl;
    uint8_t edge;

    for (key = MAZBSP_KEY1; key < MAZBSP_KEY_MAX; key++)
    {
        pctrl = &gKeyCtrl[key];

        if (MAZBSP_KEY_GPIOLEVEL_HIGH == pctrl->press)
        {
            GPIO_setAsInputPinWithPullDownResistor(pctrl->port, pctrl->pin);
            edge = GPIO_LOW_TO_HIGH_TRANSITION;
        }
        else if (MAZBSP_KEY_GPIOLEVEL_LOW == pctrl->press)
        {
            GPIO_setAsInputPinWithPullUpResistor(pctrl->port, pctrl->pin);
            edge = GPIO_HIGH_TO_LOW_TRANSITION;
        }

        if (MAZBSP_KEY_MODE_INTERRUPT == pctrl->mode)
        {
            GPIO_selectInterruptEdge(pctrl->port, pctrl->pin, edge);
            GPIO_clearInterrupt(pctrl->port, pctrl->pin);
            GPIO_enableInterrupt(pctrl->port, pctrl->pin);

            /* 使能总中断 */
            __bis_SR_register(GIE);
        }
    }

    return MAZRET_OK;
}

