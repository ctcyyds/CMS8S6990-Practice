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
/** \file extint.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __EXTINT_H__
#define __EXTINT_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8S6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **�ⲿ�ж�ͨ��
/*---------------------------------------------------------------------------*/
#define		EXTINT0				(0x00)			/*EXTINT channel 0 number*/
#define		EXTINT1				(0x01)			/*EXTINT channel 1 number*/
/*----------------------------------------------------------------------------
 **�ⲿ�жϴ���ģʽ
/*---------------------------------------------------------------------------*/
#define  EXTINT_TRIG_LOW		(0x00)			/*�͵�ƽ����ģʽ*/
#define  EXTINT_TRIG_FALLING  	(0x01)			/*�½��ش���ģʽ*/

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/********************************************************************************
 ** \brief	 EXTINT_ConfigInt
 **			 �����ⲿ�жϹ���
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1
 **			     IntMode  ��(1)EXTINT_TRIG_LOW	:�͵�ƽ����ģʽ
 **							(2)EXTINT_TRIG_FALLING :�½��ش���ģʽ
 ** \return  none
 ** \note  
 ******************************************************************************/
void EXTINT_ConfigInt(uint8_t Extintn, uint8_t IntMode);
/********************************************************************************
 ** \brief	 EXTINT_EnableInt
 **			 ʹ���ⲿ�жϹ���
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_EnableInt(uint8_t Extintn);

/********************************************************************************
 ** \brief	 EXTINT_DisableInt
 **			 �ر��ⲿ�жϹ���
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1 
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_DisableInt(uint8_t Extintn);

/********************************************************************************
 ** \brief	 EXTINT_GetIntFlag
 **			 ��ȡ�жϱ�־
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1	 
 ** \return  0:���ж���1�����ж�
 ** \note  
 ******************************************************************************/
uint8_t  EXTINT_GetIntFlag(uint8_t Extintn);
 
 /********************************************************************************
 ** \brief	 EXTINT_ClearIntFlag
 **			 ���жϱ�־
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1		 
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_ClearIntFlag(uint8_t Extintn);


#endif /* __EXTINT_H__ */






