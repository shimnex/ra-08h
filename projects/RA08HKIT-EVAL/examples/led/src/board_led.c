#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tremo_system.h"
#include "tremo_gpio.h"


void board_led_init(void)
{
    //LED RGB
	gpio_set_iomux(GPIOA, GPIO_PIN_4,0);
	gpio_set_iomux(GPIOA, GPIO_PIN_5,0);
	gpio_set_iomux(GPIOA, GPIO_PIN_7,0);
    gpio_init(GPIOA, GPIO_PIN_4, GPIO_MODE_OUTPUT_PP_LOW);
	gpio_init(GPIOA, GPIO_PIN_5, GPIO_MODE_OUTPUT_PP_LOW);
	gpio_init(GPIOA, GPIO_PIN_7, GPIO_MODE_OUTPUT_PP_LOW);

    //Dual LED
    gpio_set_iomux(GPIOA, GPIO_PIN_14,0);
    gpio_set_iomux(GPIOA, GPIO_PIN_15,0);
    gpio_init(GPIOA, GPIO_PIN_14, GPIO_MODE_OUTPUT_PP_LOW);
	gpio_init(GPIOA, GPIO_PIN_15, GPIO_MODE_OUTPUT_PP_LOW);
}

void board_led_rgb(bool r, bool g, bool b)
{
	gpio_write(GPIOA, GPIO_PIN_5, r ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW);
	gpio_write(GPIOA, GPIO_PIN_4, g ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW);
	gpio_write(GPIOA, GPIO_PIN_7, b ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW);
}

void board_led_cold(bool on)
{
    gpio_write(GPIOA, GPIO_PIN_14, on ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW);
}

void board_led_warm(bool on)
{
    gpio_write(GPIOA, GPIO_PIN_15, on ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW);
}
