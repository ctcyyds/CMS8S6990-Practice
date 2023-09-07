#ifndef __TEST_UART_H__
#define __TEST_UART_H__

#include "../User/All_include.h"

/****************[UARTģ��Ĳ�����ʱ�ӷ�����]****************/
#define BRT_UART 1
#define TMR1_UART 0
#define TMR2_UART 0
#define TMR4_UART 0
/**********************************/

/****************[API]****************/
// ʹ��UART0���д���ͨѶ
void UART_Config(uint8_t UARTChose);
// �����ж�
void UART_ISR_Config(uint8_t UARTChose, uint8_t IRQPN);
/**********************************/

#endif