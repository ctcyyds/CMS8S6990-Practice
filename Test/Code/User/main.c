#include "../User/All_include.h"

uint32_t SystemClock = 24000000;

int main(void)
{
  u16 result;
  // 串口初始化
  UART_Config(UART0); // BAUD = 19200; TX = P23; RX = P22;
  // 串口中断优先级
  // UART_ISR_Config(UART0, IRQ_UART0);

  // EPWM_Config();
  ADC_Config();

//  result = ADC_GetADCResult();
//  printf("result = %d\r\n", result);

  // 呼吸灯
  // Lamp_Run();

  // P04 = 0;
  // LED显示
  // LED_Run();

  while (1)
  {
    // printf("你还好吗world!001\r\n");
  }
}