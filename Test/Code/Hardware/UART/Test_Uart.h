#ifndef __TEST_UART_H__
#define __TEST_UART_H__

#include "../User/All_include.h"

/****************[UART模块的波特率时钟发生器]****************/
#define BRT_UART 1
#define TMR1_UART 0
#define TMR2_UART 0
#define TMR4_UART 0
/**********************************/

/****************[API]****************/
// 使用UART0进行串口通讯
void UART_Config(uint8_t UARTChose);
// 配置中断
void UART_ISR_Config(uint8_t UARTChose, uint8_t IRQPN);
/**********************************/

#endif