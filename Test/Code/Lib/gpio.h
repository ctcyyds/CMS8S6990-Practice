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
/** \file gpio.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **GPIO����
 ---------------------------------------------------------------------------*/
#define  GPIO_PIN_0_MSK				(0x01)		/* GPIO Pin 0 mask */
#define  GPIO_PIN_1_MSK				(0x02)		/* GPIO Pin 1 mask */
#define  GPIO_PIN_2_MSK				(0x04)		/* GPIO Pin 2 mask */
#define  GPIO_PIN_3_MSK				(0x08)		/* GPIO Pin 3 mask */
#define  GPIO_PIN_4_MSK				(0x10)		/* GPIO Pin 4 mask */
#define  GPIO_PIN_5_MSK				(0x20)		/* GPIO Pin 5 mask */
#define  GPIO_PIN_6_MSK				(0x40)		/* GPIO Pin 6 mask */
#define  GPIO_PIN_7_MSK				(0x80)		/* GPIO Pin 7 mask */

#define  GPIO_PIN_0					(0x00)		/* GPIO Pin 0 number*/
#define  GPIO_PIN_1					(0x01)		/* GPIO Pin 1 number */
#define  GPIO_PIN_2					(0x02)		/* GPIO Pin 2 number */
#define  GPIO_PIN_3					(0x03)		/* GPIO Pin 3 number */
#define  GPIO_PIN_4					(0x04)		/* GPIO Pin 4 number */
#define  GPIO_PIN_5					(0x05)		/* GPIO Pin 5 number */
#define  GPIO_PIN_6					(0x06)		/* GPIO Pin 6 number */
#define  GPIO_PIN_7					(0x07)		/* GPIO Pin 7 number */

#define  GPIO0						(0x00)
#define  GPIO1						(0x01)
#define  GPIO2						(0x02)
#define  GPIO3						(0x03)

#define  GPIO_P00					(0x00)
#define  GPIO_P01					(0x01)
#define  GPIO_P02					(0x02)
#define  GPIO_P03					(0x03)
#define  GPIO_P04					(0x04)
#define  GPIO_P05					(0x05)
#define  GPIO_P13					(0x13)
#define  GPIO_P14					(0x14)
#define  GPIO_P15					(0x15)
#define  GPIO_P16					(0x16)
#define  GPIO_P17					(0x17)
#define  GPIO_P21					(0x21)
#define  GPIO_P22					(0x22)
#define  GPIO_P23					(0x23)
#define  GPIO_P24					(0x24)
#define  GPIO_P25					(0x25)
#define  GPIO_P26					(0x26)
#define  GPIO_P30					(0x30)
#define  GPIO_P31					(0x31)
#define  GPIO_P32					(0x32)
#define  GPIO_P35					(0x35)
#define  GPIO_P36					(0x36)

/*----------------------------------------------------------------------------
 **GPIO ����ģʽMask
---------------------------------------------------------------------------*/
#define  GPIO_OPEN_DRAIN_MODE	(0x02)		/*GPIO ��©ģʽ*/
#define  GPIO_PUSH_PULL_MODE	(0x00)		/*GPIO �������ģʽ*/
#define  GPIO_UP_MODE			(0x04)		/*GPIO ����ģʽ*/
#define  GPIO_DR_MODE			(0x08)		/*GPIO ����ģʽ*/
#define  GPIO_LOW_CURRENT_MODE	(0x10)		/*GPIO �͵���(������)ģʽ*/
#define  GPIO_HIGH_CURRENT_MODE	(0x00)		/*GPIO �ߵ���(ǿ����)ģʽ*/
#define  GPIO_SLOW_SLOPE_MODE	(0x20)		/*GPIO ��б��ģʽ*/
#define  GPIO_FAST_SLOPE_MODE	(0x00)		/*GPIO ����ģʽ*/


/*----------------------------------------------------------------------------
 ** IO���Ÿ���ģʽ
---------------------------------------------------------------------------*/
#define  GPIO_MUX_GPIO		(0x00)			/*GPIO����*/
/*--GPIO���ֹ��ܣ�����IO�������ã�-------------------------------------------*/
/*----Timer2�Ƚ����ͨ��-----------------------------------------------------*/
#define  GPIO_MUX_CC0		(0x04)
#define  GPIO_MUX_CC1		(0x05)
#define  GPIO_MUX_CC2		(0x06)
#define  GPIO_MUX_CC3		(0x07)
/*----UARTͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_TXD0		(0x08)
#define  GPIO_MUX_RXD0		(0x09)
#define  GPIO_MUX_TXD1		(0x0A)
#define  GPIO_MUX_RXD1		(0x0B)
/*----I2Cͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_SCL		(0x0C)
#define  GPIO_MUX_SDA		(0x0D)
/*----SPIͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_NSS		(0x0E)
#define  GPIO_MUX_SCLK		(0x0F)
#define  GPIO_MUX_MOSI		(0x10)
#define  GPIO_MUX_MISO		(0x11)
/*----EPWMͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_PG0		(0x12)
#define  GPIO_MUX_PG1		(0x13)
#define  GPIO_MUX_PG2		(0x14)
#define  GPIO_MUX_PG3		(0x15)
#define  GPIO_MUX_PG4		(0x16)
#define  GPIO_MUX_PG5		(0x17)
/*----BEEPͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_BEEP		(0x18)
/*----ACMPͨ��---------------------------------------------------------------*/
#define  GPIO_MUX_C0O		(0x1A)
#define  GPIO_MUX_C1O		(0x1B)

/*--ANALOG����--------------------------------------------------------------*/
#define  GPIO_MUX_ANALOG	(0x01)			/*ģ�⹦��(GPIO���ܹر�)*/
/*----ADC����ͨ��-----------------------------------------------------------*/
#define  GPIO_P00_MUX_AN0	(0x01)
#define  GPIO_P01_MUX_AN1	(0x01)
#define  GPIO_P02_MUX_AN2	(0x01)
#define  GPIO_P03_MUX_AN3	(0x01)
#define  GPIO_P04_MUX_AN4	(0x01)
#define  GPIO_P05_MUX_AN5	(0x01)
#define  GPIO_P13_MUX_AN6	(0x01)
#define  GPIO_P14_MUX_AN7	(0x01)
#define  GPIO_P15_MUX_AN18	(0x01)
#define  GPIO_P16_MUX_AN19	(0x01)
#define  GPIO_P17_MUX_AN20	(0x01)
#define  GPIO_P21_MUX_AN21	(0x01)
#define  GPIO_P22_MUX_AN8	(0x01)
#define  GPIO_P23_MUX_AN9	(0x01)
#define  GPIO_P24_MUX_AN10	(0x01)
#define  GPIO_P25_MUX_AN11	(0x01)
#define  GPIO_P26_MUX_AN12	(0x01)
#define  GPIO_P30_MUX_AN22	(0x01)
#define  GPIO_P31_MUX_AN13	(0x01)
#define  GPIO_P32_MUX_AN14	(0x01)
#define  GPIO_P35_MUX_AN16	(0x01)
#define  GPIO_P36_MUX_AN17	(0x01)
/*----ACMP����ͨ��-----------------------------------------------------------*/
#define  GPIO_P13_MUX_C0P0	(0x01)
#define  GPIO_P00_MUX_C0P1	(0x01)
#define  GPIO_P01_MUX_C0P2	(0x01)
#define  GPIO_P30_MUX_C0P4	(0x01)
#define  GPIO_P24_MUX_C0P5	(0x01)
#define  GPIO_P14_MUX_C0N	(0x01)

#define  GPIO_P04_MUX_C1P0	(0x01)
#define  GPIO_P03_MUX_C1P1	(0x01)
#define  GPIO_P02_MUX_C1P2	(0x01)
#define  GPIO_P30_MUX_C1P4	(0x01)
#define  GPIO_P24_MUX_C1P5	(0x01)
#define  GPIO_P05_MUX_C1N	(0x01)

/*----OPA����ͨ��-----------------------------------------------------------*/
#define  GPIO_P30_MUX_OP0O	(0x01)
#define  GPIO_P31_MUX_OP0N	(0x01)
#define  GPIO_P32_MUX_OP0P	(0x01)

#define  GPIO_P22_MUX_OP1P	(0x01)
#define  GPIO_P23_MUX_OP1N	(0x01)
#define  GPIO_P24_MUX_OP1O	(0x01)

/*----PGA����ͨ��-----------------------------------------------------------*/
#define  GPIO_P31_MUX_PGAP		(0x01)
#define  GPIO_P32_MUX_PGAGND	(0x01)
#define  GPIO_P26_MUX_PGAO		(0x01)

/********************************************************************************
 ** \brief	 GPIO_SET_MUX_MODE
 **			 ����IO�ڵĸ��ù���
 ** \param [in] PorttCFG ��IO�ڵĸ��üĴ��� P00CFG.....
 **            PinMode ��IO�ڵĸ��ù��� 
 ** \return  none
********************************************************************************/
#define  GPIO_SET_MUX_MODE(PortCFG,PinMode)		(PortCFG = PinMode)	

/********************************************************************************
 ** \brief	 GPIO_SET_PS_MODE
 **			 ���ö˿����빦�ܷ���
 ** \param [in]  Ps_mode��PS_INT0��PS_INT1..... PS_FB
 **				 gpio:	GPIO_P00 .... GPIO_P36 
 ** \return  none
********************************************************************************/
#define  GPIO_SET_PS_MODE(Ps_mode,gpio)		(Ps_mode = gpio)	

/********************************************************************************
 ** \brief	 GPIO_ENABLE_OUTPUT
 **			 ʹ��GPIOΪ�������ģʽ
 ** \param [in] PortTRIS ������Ĵ��� P0TRIS ��P1TRIS ��P2TRIS ��P3TRIS 
 **            PinNum 
 ** \return  none
 ******************************************************************************/
#define	 GPIO_ENABLE_OUTPUT(PortTRIS, PinNum)	(PortTRIS |= (1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_OUTPUT
 **			 ʹ��GPIOΪ��̬����ģʽ
 ** \param [in] PorttRIS ������Ĵ��� P0TRIS ��P1TRIS ��P2TRIS ��P3TRIS 
 **            PinNum 
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INPUT(PortTRIS, PinNum)	(PortTRIS &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_OD
 **			 GPIO��©���ܿ���
 ** \param [in] PorttOD  :��©���ܼĴ�����P0OD��P1OD��P2OD��P3OD
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_OD(PortOD, PinNum)			(PortOD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_OD
 **			 GPIO��©���ܹر�
 ** \param [in] PorttOD  :��©���ܼĴ�����P0OD��P1OD��P2OD��P3OD
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_OD(PortOD, PinNum)		(PortOD &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_UP
 **			 GPIO�������ܿ���
 ** \param [in] PorttUP  :�������ܼĴ�����P0UP��P1UP��P2UP��P3UP
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_UP(PortUP, PinNum)			(PortUP |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_UP
 **			 GPIO�������ܹر�
 ** \param [in] PorttUP  :�������ܼĴ�����P0UP��P1UP��P2UP��P3UP
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_UP(PortUP, PinNum)		(PortUP &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_RD
 **			 GPIO�������ܿ���
 ** \param [in] PorttRD  :�������ܼĴ�����P0RD��P1RD��P2RD��P3RD
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_RD(PortRD, PinNum)			(PortRD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_RD
 **			 GPIO�������ܹر�
 ** \param [in] PorttRD  :�������ܼĴ�����P0RD��P1RD��P2RD��P3RD
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_RD(PortRD, PinNum)		(PortRD &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_LOW_CURRENT
 **			 GPIO�������������ܿ���
 ** \param [in] PorttDR  :�������ܼĴ�����P0DR��P1DR��P2DR��P3DR
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_LOW_CURRENT(PortDR, PinNum)	(PortDR |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_LOW_CURRENT
 **			 GPIO�������������ܹر�
 ** \param [in] PorttDR  :�������ܼĴ�����P0DR��P1DR��P2DR��P3DR
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_LOW_CURRENT(PortDR, PinNum)	(PortDR &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_LOW_CURRENT
 **			 GPIO��б�ʹ��ܿ���
 ** \param [in] PorttSR  :б�ʿ��ƹ��ܼĴ�����P0SR��P1SR��P2SR��P3SR
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_SLOW_SLOPE(PortSR, PinNum)      (PortSR |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_LOW_CURRENT
 **			 GPIO��б�ʹ��ܹر�
 ** \param [in] PorttSR  :б�ʿ��ƹ��ܼĴ�����P0SR��P1SR��P2SR��P3SR
 **            PinNum  : 0~7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_SLOW_SLOPE(PortSR, PinNum)     (PortSR &= ~(1<<PinNum))


/*----------------------------------------------------------------------------
 **GPIO �����жϴ���ģʽ
/*---------------------------------------------------------------------------*/
#define  GPIO_INT_RISING	(0x01)			/*�����ش����ж�*/
#define  GPIO_INT_FALLING	(0x02)			/*�½��ش����ж�*/
#define  GPIO_INT_BOTH_EDGE	(0x03)			/*�������½��ؾ������ж�*/

/********************************************************************************
 ** \brief	 GPIO_SET_INT_MODE
 **			 ����IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEICFG ��IO�ڵ��ⲿ�ж�ģʽ���üĴ���
 **            PinIntMode ��IO�ڵĸ��ù��� 
 ** \return  none
 ******************************************************************************/
#define  GPIO_SET_INT_MODE(PortEICFG, PinIntMode)	(PortEICFG = PinIntMode)

/********************************************************************************
 ** \brief	 GPIO_ENABLE_INT_MODE
 **			ʹ��IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEXTIE ��IO�ڵ��ⲿ�жϼĴ���
 **            PinMSK��GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INT_MODE(PortEXTIE,PinMSK)		(PortEXTIE |= PinMSK)	

/********************************************************************************
 ** \brief	 GPIO_DISABLE_INT_MODE
 **			�ر�IO�ڵ��ⲿ�жϹ���
 ** \param [in] PorttEXTIE ��IO�ڵ��ⲿ�жϼĴ���
 **            PinMSK: GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_INT_MODE(PortEXTIE,PinMSK)	(PortEXTIE &= ~PinMSK)	

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/



/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
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
void GPIO_ConfigGPIOMode( uint8_t Port, uint8_t PinMSK, uint8_t PinMode);

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
void GPIO_EnableInt(uint8_t Port, uint8_t PinMSK);
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
void GPIO_DisableInt(uint8_t Port, uint8_t PinMSK);

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
uint8_t  GPIO_GetIntFlag(uint8_t Port, uint8_t PinNum);
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
void GPIO_ClearIntFlag(uint8_t Port, uint8_t PinNum);

#endif /* __GPIO_H__ */






