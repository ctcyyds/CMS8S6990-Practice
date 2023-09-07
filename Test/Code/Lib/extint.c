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
/** \file extit.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "extint.h"

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
void EXTINT_ConfigInt(uint8_t Extintn, uint8_t IntMode)
{
	if( EXTINT0 == Extintn)
	{
		if(EXTINT_TRIG_LOW == IntMode)
			IT0 = 0;
		if(EXTINT_TRIG_FALLING == IntMode)
			IT0 = 1;
	}
	if( EXTINT1 == Extintn)
	{
		if(EXTINT_TRIG_LOW == IntMode)
			IT1 = 0;
		if(EXTINT_TRIG_FALLING == IntMode)
			IT1 = 1;
	}
}
/********************************************************************************
 ** \brief	 EXTINT_EnableInt
 **			 ʹ���ⲿ�жϹ���
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_EnableInt(uint8_t Extintn)
{	
	if( EXTINT0 == Extintn)
	{
		EX0 =1; 
	}
	if( EXTINT1 == Extintn)
	{
		EX1 =1; 
	}
}
/********************************************************************************
 ** \brief	 EXTINT_DisableInt
 **			 �ر��ⲿ�жϹ���
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_DisableInt(uint8_t Extintn)
{
	if( EXTINT0 == Extintn)
	{
		EX0 =0;
	}
	if( EXTINT1 == Extintn)
	{
		EX1 =0;
	}
}
/********************************************************************************
 ** \brief	 EXTINT_GetIntFlag
 **			 ��ȡ�жϱ�־
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1	 
 ** \return  0:���ж���1�����ж�
 ** \note  
 ******************************************************************************/
uint8_t  EXTINT_GetIntFlag(uint8_t Extintn)
{
	if(EXTINT0 == Extintn)
	{
		return((TCON & TMR_TCON_IE0_Msk)? 1:0);
	}
	if(EXTINT1 == Extintn)
	{
		return((TCON & TMR_TCON_IE1_Msk)? 1:0);	
	}
	return 0;
}
 /********************************************************************************
 ** \brief	 EXTINT_ClearIntFlag
 **			 ���жϱ�־
 ** \param [in]  Extintn : (1)EXTINT0     :�ⲿ�ж�0
 **            				(2)EXTINT1     :�ⲿ�ж�1	 
 ** \return  none
 ** \note   
 ******************************************************************************/
void EXTINT_ClearIntFlag(uint8_t Extintn)
{
	if(EXTINT0 == Extintn)
	{
		IE0 =0;
	}
	if(EXTINT1 == Extintn)
	{
		IE1 =0;
	}	
}

