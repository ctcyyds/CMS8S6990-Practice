#include "../User/All_include.h"

uint32_t SystemClock = 24000000;

int main(void)
{
  u16 result;
  // ���ڳ�ʼ��
  UART_Config(UART0); // BAUD = 19200; TX = P23; RX = P22;
  // �����ж����ȼ�
  // UART_ISR_Config(UART0, IRQ_UART0);

  // EPWM_Config();
  ADC_Config();

//  result = ADC_GetADCResult();
//  printf("result = %d\r\n", result);

  // ������
  // Lamp_Run();

  // P04 = 0;
  // LED��ʾ
  // LED_Run();

  while (1)
  {
    // printf("�㻹����world!001\r\n");
  }
}