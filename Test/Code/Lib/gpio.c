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

/****************************************************************************/
/** \file gpio.c
**
** 
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "gpio.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/
/****************************************************************************
 ** \brief	 GPIO_ConfigGPIOMode
 **			 ����GPIOģʽ
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO3
 **			   PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK	
 **            PinMode��
 **						  (1)GPIO_OPEN_DRAIN_MODE:  ��©���ģʽ
 **						  (2)GPIO_UP_MODE ��		����ģʽ
 **						  (3)GPIO_DR_MODE�� 		����ģʽ
 **						  (4)GPIO_LOW_CURRENT_MODE�� ����������ģʽ
 **						  (5)GPIO_SLOW_SLOPE_MODE��  ��б��ģʽ
 **						  (6)GPIO_PUSH_PULL_MODE:    �������ģʽ
 **						  (7)GPIO_HIGH_CURRENT_MODE��ǿ��������ģʽ
 **						  (8)GPIO_FAST_CURRENT_MODE����б��ģʽ
 ** \return  none
 ** \note   
 ***************************************************************************/
void GPIO_ConfigGPIOMode( uint8_t Port, uint8_t PinMSK, uint8_t PinMode)
{
	switch(Port)
	{
		case GPIO0:
			{
				if(PinMode & GPIO_OPEN_DRAIN_MODE)
				{
					P0OD |= PinMSK;
				}
				if(PinMode & GPIO_UP_MODE)
				{
					P0UP |= PinMSK;
				}
				if(PinMode & GPIO_DR_MODE)
				{
					P0RD |= PinMSK;
				}	
				if(PinMode & GPIO_LOW_CURRENT_MODE)
				{
					P0DR |= PinMSK;
				}
				if(PinMode & GPIO_SLOW_SLOPE_MODE)
				{
					P0SR |= PinMSK;
				}			
			}
			break;
		case GPIO1:
			{
				if(PinMode & GPIO_OPEN_DRAIN_MODE)
				{
					P1OD |= PinMSK;
				}
				if(PinMode & GPIO_UP_MODE)
				{
					P1UP |= PinMSK;
				}
				if(PinMode & GPIO_DR_MODE)
				{
					P1RD |= PinMSK;
				}	
				if(PinMode & GPIO_LOW_CURRENT_MODE)
				{
					P1DR |= PinMSK;
				}
				if(PinMode & GPIO_SLOW_SLOPE_MODE)
				{
					P1SR |= PinMSK;
				}			
			}
			break;
		case GPIO2:
			{
				if(PinMode & GPIO_OPEN_DRAIN_MODE)
				{
					P2OD |= PinMSK;
				}
				if(PinMode & GPIO_UP_MODE)
				{
					P2UP |= PinMSK;
				}
				if(PinMode & GPIO_DR_MODE)
				{
					P2RD |= PinMSK;
				}	
				if(PinMode & GPIO_LOW_CURRENT_MODE)
				{
					P2DR |= PinMSK;
				}
				if(PinMode & GPIO_SLOW_SLOPE_MODE)
				{
					P2SR |= PinMSK;
				}			
			}
			break;
		case GPIO3:
			{
				if(PinMode & GPIO_OPEN_DRAIN_MODE)
				{
					P3OD |= PinMSK;
				}
				if(PinMode & GPIO_UP_MODE)
				{
					P3UP |= PinMSK;
				}
				if(PinMode & GPIO_DR_MODE)
				{
					P3RD |= PinMSK;
				}	
				if(PinMode & GPIO_LOW_CURRENT_MODE)
				{
					P3DR |= PinMSK;
				}
				if(PinMode & GPIO_SLOW_SLOPE_MODE)
				{
					P3SR |= PinMSK;
				}			
			}
			break;
		default:
			break;
	}
}

 /********************************************************************************
 ** \brief	 GPIO_EnableInt
 **			 ʹ��IO�ڵ��жϹ���
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO3
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 **  (1)P0��PinMSK����ֵ��Χ��GPIO_PIN_0_MSK ~ GPIO_PIN_5_MSK
 **  (2)P1��PinMSK����ֵ��Χ��GPIO_PIN_3_MSK ~ GPIO_PIN_7_MSK
 **  (3)P2��PinMSK����ֵ��Χ��GPIO_PIN_1_MSK ~ GPIO_PIN_6_MSK
 **  (4)P3��PinMSK����ֵ��Χ��GPIO_PIN_0_MSK ~ GPIO_PIN_2_MSK��GPIO_PIN_5_MSK��GPIO_PIN_6_MSK
 ******************************************************************************/
void GPIO_EnableInt(uint8_t Port, uint8_t PinMSK)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIE |= PinMSK;
			break;
		case GPIO1:
			P1EXTIE |= PinMSK;
			break;		
		case GPIO2:
			P2EXTIE |= PinMSK;
			break;	
		case GPIO3:
			P3EXTIE |= PinMSK;
			break;
		default:
			break;	
	}
}
/********************************************************************************
 ** \brief	 GPIO_DisableInt
 **			 �ر�IO�ڵ��жϹ���
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO3
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 **  (1)P0��PinMSK����ֵ��Χ��GPIO_PIN_0_MSK ~ GPIO_PIN_5_MSK
 **  (2)P1��PinMSK����ֵ��Χ��GPIO_PIN_3_MSK ~ GPIO_PIN_7_MSK
 **  (3)P2��PinMSK����ֵ��Χ��GPIO_PIN_1_MSK ~ GPIO_PIN_6_MSK
 **  (4)P3��PinMSK����ֵ��Χ��GPIO_PIN_0_MSK ~ GPIO_PIN_2_MSK��GPIO_PIN_5_MSK��GPIO_PIN_6_MSK
 ******************************************************************************/
void GPIO_DisableInt(uint8_t Port, uint8_t PinMSK)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIE &= ~PinMSK;
			break;
		case GPIO1:
			P1EXTIE &= ~PinMSK;
			break;		
		case GPIO2:
			P2EXTIE &= ~PinMSK;
			break;	
		case GPIO3:
			P3EXTIE &= ~PinMSK;
			break;
		default:
			break;	
	}
}

 /******************************************************************************
 ** \brief	 GPIO_GetIntFlag
 **			 ��ȡ�жϱ�־
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO3
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 (0~7)		 
 ** \return  0�����жϲ���
 **			 1�����жϲ���
 ** \note  
 **  (1)P0��PinNum����ֵ��Χ��GPIO_PIN_0~GPIO_PIN_5
 **  (2)P1��PinNum����ֵ��Χ��GPIO_PIN_3~GPIO_PIN_7
 **  (3)P2��PinNum����ֵ��Χ��GPIO_PIN_1~GPIO_PIN_6
 **  (4)P3��PinNum����ֵ��Χ��GPIO_PIN_0~GPIO_PIN_2��GPIO_PIN_5��GPIO_PIN_6
 ******************************************************************************/
uint8_t  GPIO_GetIntFlag(uint8_t Port, uint8_t PinNum)
{
	uint8_t PinIntFlag = 0;
	switch(Port)
	{
		case GPIO0:
			PinIntFlag = P0EXTIF & (1<<PinNum);
			break;
		case GPIO1:
			PinIntFlag = P1EXTIF & (1<<PinNum);
			break;		
		case GPIO2:
			PinIntFlag = P2EXTIF & (1<<PinNum);
			break;	
		case GPIO3:
			PinIntFlag = P3EXTIF & (1<<PinNum);
			break;
		default:
			break;	
	}
	return( (PinIntFlag)? 1:0);
}
 /********************************************************************************
 ** \brief	 GPIO_ClearIntFlag
 **			����жϱ�־λ
 ** \param [in] Port  �� GPIO0��GPIO1��GPIO2��GPIO3
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 (0~7)		 
 ** \return  none
 ** \note  
 **  (1)P0��PinNum����ֵ��Χ��GPIO_PIN_0~GPIO_PIN_5
 **  (2)P1��PinNum����ֵ��Χ��GPIO_PIN_3~GPIO_PIN_7
 **  (3)P2��PinNum����ֵ��Χ��GPIO_PIN_1~GPIO_PIN_6
 **  (4)P3��PinNum����ֵ��Χ��GPIO_PIN_0~GPIO_PIN_2��GPIO_PIN_5��GPIO_PIN_6   
 ******************************************************************************/
void GPIO_ClearIntFlag(uint8_t Port, uint8_t PinNum)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIF = 0xff &(~(1<<PinNum));
			break;
		case GPIO1:
			P1EXTIF = 0xff &(~(1<<PinNum));			
			break;		
		case GPIO2:
			P2EXTIF = 0xff &(~(1<<PinNum));
			break;	
		case GPIO3:
			P3EXTIF = 0xff &(~(1<<PinNum));
			break;
		default:
			break;	
	}
}