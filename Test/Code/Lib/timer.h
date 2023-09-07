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
/** \file timer.h
**
** 
**
** History:
** 
******************************************************************************/
#ifndef __TIMER_H__
#define __TIMER_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **Timer ģ��
---------------------------------------------------------------------------*/
#define		TMR0					(0x00)			/* Timer 0 Number*/	
#define		TMR1					(0x01)			/* Timer 1 Number*/	
#define 	TMR2					(0x02)			/* Timer 2 Number*/	
#define		TMR3					(0x03)			/* Timer 3 Number*/	
#define 	TMR4					(0x04)			/* Timer 4 Number*/	

/*----------------------------------------------------------------------------
 **Timer ����ģʽ
---------------------------------------------------------------------------*/
#define		TMR_MODE_TIMING		 	(0x00)			/*��ʱ����ʱģʽ(Timer 0,1,3,4)*/
#define		TMR_MODE_COUNT			(0x01)			/*��ʱ������ģʽ(Timer 0,1)*/
	
/*----------------------------------------------------------------------------
 **Timer ʱ�ӷ�Ƶ
---------------------------------------------------------------------------*/	
#define 	TMR_CLK_DIV_12			(0x00)			/*ϵͳʱ��12��Ƶ(Timer 0,1,3,4)*/
#define 	TMR_CLK_DIV_4			(0x01)			/*ϵͳʱ��4��Ƶ(Timer 0,1,3,4)*/
/*----------------------------------------------------------------------------
 **Timer ��ʱ/����ģʽ
---------------------------------------------------------------------------*/	
#define 	TMR_TIM_13BIT					(0x00)		/*��ʱ/����13λģʽ*/
#define 	TMR_TIM_16BIT					(0x01)		/*��ʱ/����16λģʽ*/
#define 	TMR_TIM_AUTO_8BIT				(0x02)		/*��ʱ/����8λ�Զ�����ģʽ*/
#define 	TMR_TIM_TWO_INDEPENDENT_8BIT	(0x03)		/*��ʱ/����2������8λģʽ*/

/*----------------------------------------------------------------------------
 ****************************************************************************
---------------------------------------------------------------------------*/	
/*----------------------------------------------------------------------------
 **Timer2 ��ʱ/����/�Ƚ�/����ģʽ
---------------------------------------------------------------------------*/	
#define		TMR2_MODE_TIMING		(0x01)			/*��ʱ��2��ʱģʽ*/
#define		TMR2_MODE_COUNT			(0x02)			/*��ʱ��2����ģʽ*/
#define 	TMR2_MODE_COMPARE		(0x02)			/*��ʱ��2�Ƚ�ģʽ*/
/*----------------------------------------------------------------------------
 **Timer2 ʱ�ӷ�Ƶ
---------------------------------------------------------------------------*/	
#define 	TMR2_CLK_DIV_12			(0x00)						/*ϵͳʱ��12��Ƶ*/
#define 	TMR2_CLK_DIV_24			(0x01<<TMR_T2CON_T2PS_Pos)	/*ϵͳʱ��24��Ƶ*/
/*----------------------------------------------------------------------------
 **Timer2 �Ƚ�/��������ͨ��
---------------------------------------------------------------------------*/	
#define 	TMR2_CC0				(0x00)			/*Timer2 Compare or Capture Channel 0 number*/
#define 	TMR2_CC1				(0x01)			/*Timer2 Compare or Capture Channel 1 number*/
#define 	TMR2_CC2				(0x02)			/*Timer2 Compare or Capture Channel 2 number*/
#define 	TMR2_CC3				(0x03)			/*Timer2 Compare or Capture Channel 3 number*/


/*----------------------------------------------------------------------------
 **Timer2 ����ģ�� �������ģʽ
---------------------------------------------------------------------------*/	
#define 	TMR2_CAP_WRITE_REGISTER	(0x03)						/*����ͨ����д�Ĵ���ʱ����*/
#define		TMR2_CAP_EDGE_FALLING	(0x00)						/*����ͨ���½��ز���*/
#define		TMR2_CAP_EDGE_RISING	(0x01)						/*����ͨ�������ز���*/
#define		TMR2_CAP_EDGE_BOTH		(0x03)						/*����ͨ�����������½����ض��ɲ���*/	
/*----------------------------------------------------------------------------
 **Timer2 ����ģʽ
---------------------------------------------------------------------------*/	
#define 	TMR2_AUTO_LOAD			(0x02<< TMR_T2CON_T2Rn_Pos)	/*Timer2�Զ�����ģʽ*/
#define		TMR2_T2EX_LOAD			(0x03<< TMR_T2CON_T2Rn_Pos)	/*Timer2��T2EX�����½�������ģʽ*/
#define		TMR2_LOAD_DISBALE		(0x00<< TMR_T2CON_T2Rn_Pos)	/*��ֹ����*/
/*----------------------------------------------------------------------------
 **Timer2 �Ƚ�ģʽ
---------------------------------------------------------------------------*/	
#define		TMR2_CMP_MODE_0			(0x00)						/*Timer2�Ƚ�ģʽ0*/
#define		TMR2_CMP_MODE_1			(0x01<< TMR_T2CON_T2CM_Pos)	/*Timer2�Ƚ�ģʽ1*/
/*----------------------------------------------------------------------------
 **Timer2 �Ƚ�ģ��0 �жϲ���ģʽ
---------------------------------------------------------------------------*/	
#define		TMR2_CMP_INT_MODE1		(0x01<< TMR_T2CON_I3FR_Pos)	/*�Ƚ�ͨ��0��TL2/TH2��RLDL/RLDH�Ӳ���ȵ����ʱ�̲����ж�*/	
#define		TMR2_CMP_INT_MODE0		(0x00)						/*�Ƚ�ͨ��0��TL2/TH2��RLDL/RLDH����ȵ������ʱ�̲����ж�*/	


/***************************************************************************
 ** \brief	TMR0_SET_PERIOD
 **			���ö�ʱ����ʱ����
 ** \param [in] TimerPeriodH:(1)TH0 
 **				TimerPeriodL:(1)TL0 
 ** \return  none
 ** \note    13λ��ʱ�� ��THx[7:0],TLx[4:0]
*****************************************************************************/
#define		TMR0_SET_PERIOD(TimerPeriodH,TimerPeriodL)	do{\
															TH0 = (uint8_t)TimerPeriodH;\
															TL0 = (uint8_t)TimerPeriodL;\					
														}while(0)
/***************************************************************************
 ** \brief	TMR1_SET_PERIOD
 **			���ö�ʱ����ʱ����
 ** \param [in] TimerPeriodH:(1)TH1 
 **				TimerPeriodL:(1)TL1 
 ** \return  none
 ** \note    13λ��ʱ�� ��THx[7:0],TLx[4:0]
*****************************************************************************/
#define		TMR1_SET_PERIOD(TimerPeriodH,TimerPeriodL)	do{\
															TH1 = (uint8_t)TimerPeriodH;\
															TL1 = (uint8_t)TimerPeriodL;\					
															}while(0)
/***************************************************************************
 ** \brief	TMR3_SET_PERIOD
 **			���ö�ʱ����ʱ����
 ** \param [in] TimerPeriodH:(1)TH3 
 **				TimerPeriodL:(1)TL3 
 ** \return  none
 ** \note    13λ��ʱ�� ��THx[7:0],TLx[4:0]
*****************************************************************************/
#define		TMR3_SET_PERIOD(TimerPeriodH,TimerPeriodL)	do{\
															TH3 = (uint8_t)TimerPeriodH;\
															TL3 = (uint8_t)TimerPeriodL;\					
															}while(0)
															
/***************************************************************************
 ** \brief	TMR4_SET_PERIOD
 **			���ö�ʱ����ʱ����
 ** \param [in] TimerPeriodH:(1)TH4 
 **				TimerPeriodL:(1)TL4 
 ** \return  none
 ** \note    13λ��ʱ�� ��THx[7:0],TLx[4:0]
*****************************************************************************/
#define		TMR4_SET_PERIOD(TimerPeriodH,TimerPeriodL)	do{\
															TH4 =(uint8_t)TimerPeriodH;\
															TL4 =(uint8_t)TimerPeriodL;\					
															}while(0)															
																													
/***************************************************************************
 ** \brief	TMR2_SET_PERIOD
 **			���ö�ʱ����ʱ����
 ** \param [in]  TimerPeriod:16bit
 ** \return  none
 ** \note    
*****************************************************************************/
#define		TMR2_SET_PERIOD(TimerPeriod)	do{\
													TH2 = (uint8_t)(TimerPeriod >> 8);\
													TL2 = (uint8_t)(TimerPeriod);\														
												}while(0)

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	TMR_ConfigRunMode
 **			���ö�ʱ������ģʽ
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 **				TimerMode 	��(1)TMR_MODE_TIMING	:��ʱģʽ
 **							  (2)TMR_MODE_COUNT		:����ģʽ
 **				TimerModeBranch	��ģʽ�ķ�֧
 **								(1)TMR_TIM_13BIT 	:13λ��ʱ/����ģʽ
 **								(2)TMR_TIM_16BIT 	:16λ��ʱ/����ģʽ		
 **								(3)TMR_TIM_AUTO_8BIT :8λ�Զ����ض�ʱ/����ģʽ
 **								(4)TMR_TIM_TWO_INDEPENDENT_8BIT	:����������8λ��ʱ/����ģʽ
 ** \return  none
 ** \note    �˺�����֧��TMR2 
 *****************************************************************************/
void TMR_ConfigRunMode(uint8_t Timern, uint8_t TimerMode, uint8_t TimerModeBranch);
/*****************************************************************************
 ** \brief	TMR_ConfigTimerClk
 **			���ö�ʱ������ʱ��
 ** \param [in]  Timern	��		TMR0,TMR1,TMR3,TMR4
 **				TimerClkDiv	��(1)TMR_CLK_DIV_4 
 **							  (2)TMR_CLK_DIV_12
 ** \note   
 *****************************************************************************/
void TMR_ConfigTimerClk(uint8_t Timern,uint8_t TimerClkDiv);
/***************************************************************************
 ** \brief	TMR_ConfigTimerPeriod
 **			���ö�ʱ����ʱ����
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 **				TimerPeriodH:(1)TH0 (2)TH1 (3)TH3 (4)TH4
 **				TimerPeriodL:(1)TL0 (2)TL1 (3)TL3 (4)TL4
 ** \return  none
 ** \note   13λ��ʱ�� ��THx[7:0],TLx[4:0]
*****************************************************************************/
void TMR_ConfigTimerPeriod(uint8_t Timern , uint8_t TimerPeriodHigh,uint8_t TimerPeriodLow);
/*****************************************************************************
 ** \brief	TMR_EnableGATE
 **			ʹ�ܶ�ʱ���ſ�
 ** \param [in] Timern	��	TMR0,TMR1
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR_EnableGATE(uint8_t Timern);
/*****************************************************************************
 ** \brief	TMR_DisableGATE
 **			�رն�ʱ���ſ�
 ** \param [in] Timern	��	TMR0,TMR1
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR_DisableGATE(uint8_t Timern);

/*****************************************************************************
 ** \brief	TMR_GetCountValue
 **			��ȡ��ʱ������ģʽ�ļ���ֵ
 ** \param [in] Timern	��	TMR0,TMR1
 ** \return  16bits�ļ���ֵ��[THn:TLn]
 ** \note   ģʽ2/3: ������ʹ��
 *****************************************************************************/
uint16_t TMR_GetCountValue(uint8_t Timern);

/*****************************************************************************
 ** \brief	TMR_EnableOverflowInt
 **			ʹ�ܶ�ʱ������ж�
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR_EnableOverflowInt(uint8_t TimerMask);

/*****************************************************************************
 ** \brief	TMR_DisableOverflowInt
 **			�رն�ʱ������ж�
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR_DisableOverflowInt(uint8_t TimerMask);
/*****************************************************************************
 ** \brief	TMR_GetOverflowIntFlag
 **			��ȡ��ʱ���жϱ�־
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return   0�����жϣ� 1�����ж�
 ** \note   ��ʱ��0��3ʹ��ģʽ3ʱ������TLn������ж�ʹ��TMR0��3�жϱ�־
 **									   THn������ж�ʹ��TMR1��4�жϱ�־ 
 *****************************************************************************/
uint8_t TMR_GetOverflowIntFlag(uint8_t TimerNumber);
/*****************************************************************************
 ** \brief	TMR_ClearOverflowIntFlag
 **			�����ʱ������жϱ�־
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR_ClearOverflowIntFlag(uint8_t TimerNumber);
/*****************************************************************************
 ** \brief	TMR_Start
 **			������ʱ��
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR_Start(uint8_t Timern);
/*****************************************************************************
 ** \brief	TMR_Stop
 **			�رն�ʱ��
 ** \param [in] Timern	��		TMR0,TMR1,TMR3,TMR4
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR_Stop(uint8_t Timern);


/*****************************************************************************
 ** \brief	TMR2_ConfigRunMode
 **			����Timer2����ģʽ
 ** \param [in]	Timer2Mode 	:	(1)TMR2_MODE_TIMING	:��ʱģʽ
 **								(2)TMR2_MODE_COUNT	:����ģʽ
 **			   Timer2LoadMode	��	
 **								(1)TMR2_AUTO_LOAD	:��ʱ��2�Զ�����ģʽ
 **								(2)TMR2_T2EX_LOAD	:��ʱ��2�ⲿ��������ģʽ
**								(3)TMR2_LOAD_DISBALE: ��ֹ����
 ** \return  none
 ** \note    
*****************************************************************************/
void TMR2_ConfigRunMode(  uint8_t Timer2Mode, uint8_t Timer2LoadMode);
/*****************************************************************************
 ** \brief	TMR2_ConfigTimerClk
 **			���ö�ʱ������ʱ��
 ** \param [in]	TimerClkDiv	��TMR2_CLK_DIV_12 ��TMR2_CLK_DIV_24
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_ConfigTimerClk(uint8_t TimerClkDiv);

/***************************************************************************
 ** \brief	TMR2_ConfigTimerPeriod
 **			���ö�ʱ��2��ʱ����
 ** \param [in] TimerPeriod����ʱ��2��ʱ����
 ** \return  none
 ** \note   
*****************************************************************************/
void TMR2_ConfigTimerPeriod(uint16_t TimerPeriod);
/*****************************************************************************
 ** \brief	TMR2_EnableGATE
 **			ʹ�ܶ�ʱ��2�ſع���
 ** \param [in] none
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_EnableGATE(void);
/*****************************************************************************
 ** \brief	TMR2_DisableGATE
 **			�رն�ʱ��2�ſع���
 ** \param [in] none
 ** \return  none
 ** \note  
 *****************************************************************************/
void TMR2_DisableGATE(void);
/*****************************************************************************
 ** \brief	TMR2_EnableCompare
 **			ʹ�ܱȽ�ģʽ
 ** \param [in]	Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 **				CompareMode :(1)TMR2_CMP_MODE_0
 **							 (2)TMR2_CMP_MODE_1
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_EnableCompare(uint8_t Timer2CCn, uint8_t CompareMode);
/*****************************************************************************
 ** \brief	TMR2_DisableCompare
 **			�رձȽ�ģʽ
 ** \param [in]	Timer2CCMask:  TMR2_CC0 ~ TMR2_CC3
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_DisableCompare(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_ConfigCompareValue
 **			���ñȽ�ͨ���Ƚ�ֵ
 ** \param [in]	Timer2CCMask:  TMR2_CC0 ~ TMR2_CC3
 **				CompareValue:  0x0 ~ 0xFFFF;
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_ConfigCompareValue(uint8_t Timer2CCn, uint16_t CompareValue);

/*****************************************************************************
 ** \brief	TMR2_ConfigCompareIntMode
 **			���ñȽ�ͨ���Ƚ��ж�ģʽ
 ** \param [in]	Timer2CompareIntMode:	(1)TMR2_CMP_INT_MODE0   
 **										(2)TMR2_CMP_INT_MODE1	  
 ** \return  none
 ** \note   
 **						 
 *****************************************************************************/
void TMR2_ConfigCompareIntMode(uint8_t Timer2CompareIntMode);

/*****************************************************************************
 ** \brief	TMR2_EnableCapture
 **			ʹ�ܲ���ģʽ
 ** \param [in]	Timer2CCMask:  TMR2_CC0 ~ TMR2_CC3
 **				Timer2CaptureMode: (1)TMR2_CAP_WRITE_REGISTER   ����ͨ����д�Ĵ���ʱ����
 **								   (2)TMR2_CAP_EDGE_FALLING		����ͨ���½��ز���			  	
 **								   (3)TMR2_CAP_EDGE_RISING		����ͨ�������ز���
 **								   (4)TMR2_CAP_EDGE_BOTH		����ͨ�����������½����ض��ɲ���							   
 ** \return  none
 ** \note  
 *****************************************************************************/
void TMR2_EnableCapture(uint8_t Timer2CCn, uint8_t Timer2CaptureMode);

/*****************************************************************************
 ** \brief	TMR2_DisableCapture
 **			�رղ���ģʽ
 ** \param [in]	Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return  none
 ** \note   
*****************************************************************************/
void TMR2_DisableCapture(uint8_t Timer2CCn);

/*****************************************************************************
 ** \brief	TMR2_GetCaptureValue
 **			��ȡ����ֵ
 ** \param [in]	Timer2CCn:  TMR2_CC0 ~ TMR2_CC3			
 ** \return  16bit value
 ** \note   
 *****************************************************************************/
uint16_t TMR2_GetCaptureValue(uint8_t Timer2CCn);

/*****************************************************************************
 ** \brief	TMR2_EnableOverflowInt
 **			ʹ�ܶ�ʱ��2����ж�
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_EnableOverflowInt(void);
/*****************************************************************************
 ** \brief	TMR2_DisableOverflowInt
 **			�رն�ʱ��2����ж�
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_DisableOverflowInt(void);
/*****************************************************************************
 ** \brief	TMR_GetOverflowIntFlag
 **			��ȡ��ʱ��2����жϱ�־
 ** \param [in] none
 ** \return   0�����жϣ� 1�����ж�
 ** \note   
 *****************************************************************************/
uint8_t TMR2_GetOverflowIntFlag(void);
/*****************************************************************************
 ** \brief	TMR2_ClearOverflowIntFlag
 **			�����ʱ��2����жϱ�־
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_ClearOverflowIntFlag(void);

/*****************************************************************************
 ** \brief	TMR2_EnableT2EXInt
 **			ʹ�ܶ�ʱ��2�ⲿ����T2EX�ж�
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_EnableT2EXInt(void);

/*****************************************************************************
 ** \brief	TMR2_DisableT2EXInt
 **			�رն�ʱ��2�ⲿ����T2EX�ж�
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_DisableT2EXInt(void);
/*****************************************************************************
 ** \brief	TMR_GetT2EXIntFlag
 **			��ȡ��ʱ��2�ⲿ����T2EX�жϱ�־
 ** \param [in] none
 ** \return   0�����жϣ� 1�����ж�
 ** \note   
 *****************************************************************************/
uint8_t TMR2_GetT2EXIntFlag(void);
/*****************************************************************************
 ** \brief	TMR2_ClearT2EXIntFlag
 **			�����ʱ��2�ⲿ����T2EX�жϱ�־
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_ClearT2EXIntFlag(void);

/*****************************************************************************
 ** \brief	TMR2_EnableCompareInt
 **			ʹ�ܶ�ʱ��2ͨ���Ƚ��ж�
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_EnableCompareInt(uint8_t Timer2CCn);

/*****************************************************************************
 ** \brief	TMR2_DisableCompareInt
 **			�رն�ʱ��2ͨ���Ƚ��ж�
 ** \param [in] Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_DisableCompareInt(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_GetCompareIntFlag
 **			��ȡ��ʱ��2ͨ���Ƚ��жϱ�־
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   0�����жϣ� 1�����ж�
 ** \note   
 *****************************************************************************/
uint8_t TMR2_GetCompareIntFlag(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_ClearCompareIntFlag
 **			�����ʱ��2ͨ���Ƚ��жϱ�־
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_ClearCompareIntFlag(uint8_t Timer2CCn);

/*****************************************************************************
 ** \brief	TMR2_EnableCaptureInt
 **			ʹ�ܶ�ʱ��2ͨ�������ж�
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_EnableCaptureInt(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_DisableCaptureInt
 **			�رն�ʱ��2ͨ�������ж�
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_DisableCaptureInt(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_GetCaptureIntFlag
 **			��ȡ��ʱ��2ͨ�������жϱ�־
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   0�����жϣ� 1�����ж�
 ** \note   
 *****************************************************************************/
uint8_t TMR2_GetCaptureIntFlag(uint8_t Timer2CCn);
/*****************************************************************************
 ** \brief	TMR2_ClearCaptureIntFlag
 **			�����ʱ��2ͨ�������жϱ�־
 ** \param [in]Timer2CCn:  TMR2_CC0 ~ TMR2_CC3
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_ClearCaptureIntFlag(uint8_t Timer2CCn);


/*****************************************************************************
 ** \brief	TMR2_AllIntEnable
 **			��ʱ��2���жϿ���
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_AllIntEnable(void);

/*****************************************************************************
 ** \brief	TMR2_AllIntDisable
 **			��ʱ��2���жϹر�
 ** \param [in] none
 ** \return   none
 ** \note   
 *****************************************************************************/
void TMR2_AllIntDisable(void);
/*****************************************************************************
 ** \brief	TMR2_Start
 **			������ʱ��2
 ** \param [in] none
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_Start(void);
/*****************************************************************************
 ** \brief	TMR2_Stop
 **			�رն�ʱ��2
 ** \param [in] none
 ** \return  none
 ** \note   
 *****************************************************************************/
void TMR2_Stop(void);

#endif /* __TIMER_H__ */






