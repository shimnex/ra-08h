#include <stdio.h>
#include <string.h>
#include "tremo_uart.h"
#include "tremo_gpio.h"
#include "tremo_rcc.h"
#include "tremo_pwr.h"
#include "tremo_delay.h"
#include "tremo_gpio.h"

extern void board_led_init(void);
extern void board_led_rgb(bool r, bool g, bool b);
extern void board_led_cold(bool on);
extern void board_led_warm(bool on);

void uart_log_init(void)
{
    // uart0
    gpio_set_iomux(GPIOB, GPIO_PIN_0, 1);
    gpio_set_iomux(GPIOB, GPIO_PIN_1, 1);

    /* uart config struct init */
    uart_config_t uart_config;
    uart_config_init(&uart_config);

    uart_config.baudrate = UART_BAUDRATE_115200;
    uart_init(CONFIG_DEBUG_UART, &uart_config);
    uart_cmd(CONFIG_DEBUG_UART, ENABLE);
}

void board_init()
{
    rcc_enable_oscillator(RCC_OSC_XO32K, true);

    rcc_enable_peripheral_clk(RCC_PERIPHERAL_UART0, true);
    rcc_enable_peripheral_clk(RCC_PERIPHERAL_GPIOA, true);
    rcc_enable_peripheral_clk(RCC_PERIPHERAL_PWR, true);
 

    delay_ms(100);
    pwr_xo32k_lpm_cmd(true);
    
    uart_log_init();
    board_led_init();
}

int main(void)
{
    // Target board initialization
    board_init();

    while(1)
    {
        board_led_rgb(false, false, false);
        delay_ms(1000);
        board_led_rgb(true, false, false);
        delay_ms(1000);
        board_led_rgb(false, true, false);
        delay_ms(1000);
        board_led_rgb(false, false, true);
        delay_ms(1000);
        board_led_rgb(true, true, true);
        delay_ms(1000);

        board_led_cold(true);
        delay_ms(1000);
        board_led_warm(true);
        delay_ms(1000);
        board_led_cold(false);
        delay_ms(1000);
        board_led_warm(false);
        delay_ms(1000);
    }
}

#ifdef USE_FULL_ASSERT
void assert_failed(void* file, uint32_t line)
{
    (void)file;
    (void)line;

    while (1) { }
}
#endif
