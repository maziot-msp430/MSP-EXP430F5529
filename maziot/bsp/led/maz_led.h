#ifndef MAZIOT_BSP_LED_MAZ_LED_H_
#define MAZIOT_BSP_LED_MAZ_LED_H_

#include "driverlib.h"

typedef enum _MAZBSP_LED_
{
    MAZBSP_LED1 = 0,
    MAZBSP_LED2,
    MAZBSP_LED3,
    MAZBSP_LED_MAX,
} MAZBSP_LED;

typedef enum _MAZBSP_LED_GPIOPORT_
{
    MAZBSP_LED_GPIOPORT_P1 = GPIO_PORT_P1,
    MAZBSP_LED_GPIOPORT_P2 = GPIO_PORT_P2,
    MAZBSP_LED_GPIOPORT_P3 = GPIO_PORT_P3,
    MAZBSP_LED_GPIOPORT_P4 = GPIO_PORT_P4,
    MAZBSP_LED_GPIOPORT_P5 = GPIO_PORT_P5,
    MAZBSP_LED_GPIOPORT_P6 = GPIO_PORT_P6,
    MAZBSP_LED_GPIOPORT_P7 = GPIO_PORT_P7,
    MAZBSP_LED_GPIOPORT_P8 = GPIO_PORT_P8,
    MAZBSP_LED_GPIOPORT_P9 = GPIO_PORT_P9,
    MAZBSP_LED_GPIOPORT_P10 = GPIO_PORT_P10,
    MAZBSP_LED_GPIOPORT_P11 = GPIO_PORT_P11,
    MAZBSP_LED_GPIOPORT_PA = GPIO_PORT_PA,
    MAZBSP_LED_GPIOPORT_PB = GPIO_PORT_PB,
    MAZBSP_LED_GPIOPORT_PC = GPIO_PORT_PC,
    MAZBSP_LED_GPIOPORT_PD = GPIO_PORT_PD,
    MAZBSP_LED_GPIOPORT_PE = GPIO_PORT_PE,
    MAZBSP_LED_GPIOPORT_PF = GPIO_PORT_PF,
    MAZBSP_LED_GPIOPORT_PJ = GPIO_PORT_PJ,
} MAZBSP_LED_GPIOPORT;

typedef enum _MAZBSP_LED_GPIOPIN_
{
    MAZBSP_LED_GPIOPIN0 = GPIO_PIN0,
    MAZBSP_LED_GPIOPIN1 = GPIO_PIN1,
    MAZBSP_LED_GPIOPIN2 = GPIO_PIN2,
    MAZBSP_LED_GPIOPIN3 = GPIO_PIN3,
    MAZBSP_LED_GPIOPIN4 = GPIO_PIN4,
    MAZBSP_LED_GPIOPIN5 = GPIO_PIN5,
    MAZBSP_LED_GPIOPIN6 = GPIO_PIN6,
    MAZBSP_LED_GPIOPIN7 = GPIO_PIN7,
    MAZBSP_LED_GPIOPIN8 = GPIO_PIN8,
    MAZBSP_LED_GPIOPIN9 = GPIO_PIN9,
    MAZBSP_LED_GPIOPIN10 = GPIO_PIN10,
    MAZBSP_LED_GPIOPIN11 = GPIO_PIN11,
    MAZBSP_LED_GPIOPIN12 = GPIO_PIN12,
    MAZBSP_LED_GPIOPIN13 = GPIO_PIN13,
    MAZBSP_LED_GPIOPIN14 = GPIO_PIN14,
    MAZBSP_LED_GPIOPIN15 = GPIO_PIN15,
    MAZBSP_LED_GPIOPIN_ALL8 = GPIO_PIN_ALL8,
    MAZBSP_LED_GPIOPIN_ALL16 = GPIO_PIN_ALL16,
} MAZBSP_LED_GPIOPIN;

typedef enum _MAZBSP_LED_GPIOLEVEL_
{
    MAZBSP_LED_GPIOLEVEL_HIGH = GPIO_INPUT_PIN_HIGH,
    MAZBSP_LED_GPIOLEVEL_LOW = GPIO_INPUT_PIN_LOW,
} MAZBSP_LED_GPIOLEVEL;

typedef enum _MAZBSP_LED_STATUS_
{
    MAZBSP_LED_STATUS_ON = 0,
    MAZBSP_LED_STATUS_OFF,
    MAZBSP_LED_STATUS_TOGGLE,
    MAZBSP_LED_STATUS_MAX,
} MAZBSP_LED_STATUS;

typedef struct _MAZBSP_LED_CTRL_
{
    MAZBSP_LED_GPIOPORT port;               // 连接LED的GPIOPORT
    MAZBSP_LED_GPIOPIN pin;                 // 连接LED的GPIOPIN
    MAZBSP_LED_GPIOLEVEL light;             // 高电平还是低电平点亮
    MAZBSP_LED_STATUS status;               // 默认状态
} MAZBSP_LED_CTRL;

int16_t maz_led_init(void);
int16_t maz_led_set_status(MAZBSP_LED led, MAZBSP_LED_STATUS status);

#endif /* MAZIOT_BSP_LED_MAZ_LED_H_ */
