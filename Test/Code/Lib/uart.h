/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/*****************************************************************************/
/** \file uart.h
**
**
**
** History:
** 
******************************************************************************/
#ifndef __UART_H__
#define __UART_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **UART ͨ��
/*---------------------------------------------------------------------------*/
#define UART0					(0x00)			/*UART channel 0 number*/
#define UART1					(0x01)			/*UART channel 0 number*/
/*----------------------------------------------------------------------------
 **UART ģʽ
/*---------------------------------------------------------------------------*/
#define UART_MOD_SYN				(0x00)		/*ͬ��ģʽ*/
#define	UART_MOD_ASY_8BIT 			(0x01)		/*8λ�첽ģʽ�Ҳ����ʿɱ�*/				
#define UART_MOD_ASY_9BIT			(0x03)		/*9λ�첽ģʽ�Ҳ����ʿɱ�*/
#define UART_MOD_ASY_9BIT_STATIC	(0x02)		/*9λ�첽ģʽ�Ҳ�����ΪFsys/32����Fsys/64*/
/*----------------------------------------------------------------------------
 **UART ������ʱ��
/*---------------------------------------------------------------------------*/
#define UART_BAUD_TMR1				(0x00)		/*������ʱ��ѡ��Timer1*/
#define UART_BAUD_TMR4				(0x01)		/*������ʱ��ѡ��Timer4*/
#define UART_BAUD_TMR2				(0x02)		/*������ʱ��ѡ��Timer2*/
#define UART_BAUD_BRT				(0x03)		/*������ʱ��ѡ��BRT*/
/*----------------------------------------------------------------------------
 ** BRT �����ʶ�ʱ��ʱ�ӷ�Ƶ
/*---------------------------------------------------------------------------*/
#define BRT_CLK_DIV_1				(0x00)		/*Fbrt = Fsys/1*/
#define BRT_CLK_DIV_2				(0x01)		/*Fbrt = Fsys/2*/
#define BRT_CLK_DIV_4				(0x02)		/*Fbrt = Fsys/4*/
#define BRT_CLK_DIV_8				(0x03)		/*Fbrt = Fsys/8*/
#define BRT_CLK_DIV_16				(0x04)		/*Fbrt = Fsys/16*/
#define BRT_CLK_DIV_32				(0x05)		/*Fbrt = Fsys/32*/
#define BRT_CLK_DIV_64				(0x06)		/*Fbrt = Fsys/64*/
#define BRT_CLK_DIV_128				(0x07)		/*Fbrt = Fsys/128*/
/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/



/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/******************************************************************************
 ** \brief UART_ConfigRunMode
 **			����UART����ģʽ
 ** \param [in]     UARTn: 			(1)UART0
 **									(2)UART1
 **					UARTMode:		(1)UART_MOD_SYN : ͬ��ģʽ
 **									(2)UART_MOD_ASY_8BIT: 8λ�첽ģʽ
 **									(3)UART_MOD_ASY_9BIT��9λ�첽ģʽ
 **									(4)UART_MOD_ASY_9BIT_STATIC��9λ�����ʹ̶��첽ģʽ
 **					UARTBaudTimer:  (1)UART_BAUD_TMR1 :	Timer1����������
 **									(2)UART_BAUD_TMR4 :	Timer4����������
 **									(3)UART_BAUD_TMR2 : Timer2����������
 **									(4)UART_BAUD_BRT : BRT����������
 ** \return none
******************************************************************************/
void UART_ConfigRunMode(uint8_t UARTn, uint8_t UARTMode, uint8_t UARTBaudTimer);
/******************************************************************************
 ** \brief UART_EnableDoubleFrequency
 **			ʹ��UART�����ʱ�Ƶģʽ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return none
******************************************************************************/
void UART_EnableDoubleFrequency(uint8_t UARTn);
/******************************************************************************
 ** \brief UART_DisableDoubleFrequency
 **			�ر�UART�����ʱ�Ƶģʽ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return none
******************************************************************************/
void UART_DisableDoubleFrequency(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_ConfigBaudRate
 **			����UART������
 ** \param [in]    UARTn:  (1)UART0 : UART0
 **									(2)UART1 : UART1
 **					BaudRateValue:  ������ֵ
 ** \return Timer1/4: 8λ�Զ���װģʽ��THxֵ
 **			Timer2: 16 λ�Զ���װģʽ�� RLDH:RLDL ֵ
 **			BRT: 16 λ��ʱģʽ BRTH:BRTL ֵ
******************************************************************************/
uint16_t UART_ConfigBaudRate(uint8_t UARTn, uint32_t  BaudRateValue);

/******************************************************************************
 ** \brief UART_EnableReceive
 **			��������ģʽ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_EnableReceive(uint8_t UARTn);
/******************************************************************************
 ** \brief UART_DisableReceive
 **			�رս���ģʽ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_DisableReceive(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_EnableInt
 **			�����ж�
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_EnableInt(uint8_t UARTn);
/******************************************************************************
 ** \brief UART_DisableInt
 **			�ر��ж�
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_DisableInt(uint8_t UARTn);


/******************************************************************************
 ** \brief UART_GetReceiveIntFlag
 **			��ȡ�����жϱ�־λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 0�����жϣ�1�����ж�
******************************************************************************/
uint8_t  UART_GetReceiveIntFlag(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_ClearReceiveIntFlag
 **			��������жϱ�־λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_ClearReceiveIntFlag(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_GetSendIntFlag
 **			��ȡ�����жϱ�־λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 0�����жϣ�1�����ж�
******************************************************************************/
uint8_t  UART_GetSendIntFlag(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_ClearSendIntFlag
 **			��������жϱ�־λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
void UART_ClearSendIntFlag(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_GetBuff
 **			��ȡ����Buff��ֵ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 
******************************************************************************/
uint8_t UART_GetBuff(uint8_t UARTn);

/******************************************************************************
 ** \brief UART_SendBuff
 **			�������ݵ�����Buff
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 **				   UARTSendValue : ���͵�8λֵ
 ** \return 
******************************************************************************/
void UART_SendBuff(uint8_t UARTn, uint8_t UARTSendValue);

/******************************************************************************
 ** \brief UART_SendNinthBit
 **			�������ݵĵھ�λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 **				   UARTSendValue : ���͵ĵھ�λֵ 0 /1
 ** \return 
******************************************************************************/
void UART_SendNinthBit(uint8_t UARTn, uint8_t UARTSendValue);
/******************************************************************************
 ** \brief UART_GetNinthBit
 **			��ȡ���ݵĵھ�λ
 ** \param [in]    UARTn: (1) UART0
 **						  (2) UART1
 ** \return 0/1
******************************************************************************/
uint8_t UART_GetNinthBit(uint8_t UARTChannelNumber);

/******************************************************************************
 ** \brief UART_EnableBRT
 **		   ʹ��BRTʱ��ģ��
 ** \param [in]none 
 ** \return none
******************************************************************************/
void UART_EnableBRT(void);
/******************************************************************************
 ** \brief UART_ConfigBRTClk
 **		   ����BRTģ��ʱ��
 ** \param [in] BRTClkDiv : BRT_CLK_DIV_1 ~ BRT_CLK_DIV_128
 ** \return none
******************************************************************************/
void UART_ConfigBRTClk(uint8_t BRTClkDiv);
/******************************************************************************
 ** \brief UART_ConfigBRTPeriod
 **		   ����BRTģ��ʱ������
 ** \param [in] BRTPeriod: 16bit
 ** \return none
******************************************************************************/
void UART_ConfigBRTPeriod(uint16_t BRTPeriod);

/******************************************************************************
 ** \brief UART_DisableBRT
 **		   �ر�BRTʱ��ģ��
 ** \param [in] none
 ** \return none
******************************************************************************/
void UART_DisableBRT(void);




#endif /* __UART_H__ */






