#include "../User/All_include.h"

uint32_t SystemClock = 24000000;

int main(void)
{
    // 串口初始化
    UART_Config(UART0);
    // 串口中断优先级
    // UART_ISR_Config(UART0, IRQ_UART0);

    EPWM_Config();

    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_GPIO);
    GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_4);
		
		P04 = 0;
    // LED显示
    // LED_Run();

    while (1)
    {
        // printf("你还好吗world!001\r\n");
    }
}