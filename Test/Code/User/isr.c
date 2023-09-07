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
/** \file isr.c
**
**
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms8s6990.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
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

/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void INT0_IRQHandler(void) interrupt INT0_VECTOR
{
	P05 = ~P05;
}
/******************************************************************************
 ** \brief	 Timer 0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void Timer0_IRQHandler(void) interrupt TMR0_VECTOR
{
}
/******************************************************************************
 ** \brief	 INT0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void INT1_IRQHandler(void) interrupt INT1_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	 Timer 1 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void Timer1_IRQHandler(void) interrupt TMR1_VECTOR
{
	// P05 = ~P05;
	// TH1 = (65536 - 200) >> 8;
	// TL1 = 65536 - 200;
}
/******************************************************************************
 ** \brief	 UART 0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void UART0_IRQHandler(void) interrupt UART0_VECTOR
{
	if (UART_GetSendIntFlag(UART0))
	{

		UART_ClearSendIntFlag(UART0);
	}
	if (UART_GetReceiveIntFlag(UART0))
	{
		UART_SendBuff(UART0, UART_GetBuff(UART0));
		UART_ClearReceiveIntFlag(UART0);
	}
}
/******************************************************************************
 ** \brief	 Timer 2 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void Timer2_IRQHandler(void) interrupt TMR2_VECTOR
{
}
/******************************************************************************
 ** \brief	 UART 1 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void UART1_IRQHandler(void) interrupt UART1_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	 GPIO 0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void P0EI_IRQHandler(void) interrupt P0EI_VECTOR
{
}
/******************************************************************************
 ** \brief	 GPIO 1 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void P1EI_IRQHandler(void) interrupt P1EI_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	 GPIO 2 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void P2EI_IRQHandler(void) interrupt P2EI_VECTOR
{
}
/******************************************************************************
 ** \brief	 GPIO 3 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void P3EI_IRQHandler(void) interrupt P3EI_VECTOR
{
	;
}

/******************************************************************************
 ** \brief	 LVD interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void LVD_IRQHandler(void) interrupt LVD_VECTOR
{
}
/******************************************************************************
 ** \brief	 LSE interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void LSE_IRQHandler(void) interrupt LSE_VECTOR
{
}

/********************************************************************************
 ** \brief	 ACMP interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void ACMP_IRQHandler(void) interrupt ACMP_VECTOR
{
}
/******************************************************************************
 ** \brief	 Timer 3 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void Timer3_IRQHandler(void) interrupt TMR3_VECTOR
{
}
/******************************************************************************
 ** \brief	 Timer 4 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void Timer4_IRQHandler(void) interrupt TMR4_VECTOR
{
}
/******************************************************************************
 ** \brief	 EPWM interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void EPWM_IRQHandler(void) interrupt EPWM_VECTOR
{
}
/******************************************************************************
 ** \brief	 ADC interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void ADC_IRQHandler(void) interrupt ADC_VECTOR
{
}
/******************************************************************************
 ** \brief	 WDT interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void WDT_IRQHandler(void) interrupt WDT_VECTOR
{
}
/******************************************************************************
 ** \brief	I2C interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void I2C_IRQHandler(void) interrupt I2C_VECTOR
{
	;
}
/******************************************************************************
 ** \brief	SPI interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
void SPI_IRQHandler(void) interrupt SPI_VECTOR
{
	;
}
