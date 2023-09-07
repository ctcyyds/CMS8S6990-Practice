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
/** \file epwm.h
**
** 
**
** History:
** 
******************************************************************************/
#ifndef __EPWM_H__
#define __EPWM_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **EPWMͨ��Mask
/*---------------------------------------------------------------------------*/
#define EPWM_CHANNEL_NUM                     (6)    /* EPWM channel number */
#define EPWM_CH_0_MSK                       (0x1)   /* EPWM channel 0 mask */
#define EPWM_CH_1_MSK                       (0x2)   /* EPWM channel 1 mask */
#define EPWM_CH_2_MSK                       (0x4)   /* EPWM channel 2 mask */
#define EPWM_CH_3_MSK                       (0x8)   /* EPWM channel 3 mask */
#define EPWM_CH_4_MSK                       (0x10)  /* EPWM channel 4 mask */
#define EPWM_CH_5_MSK                       (0x20)  /* EPWM channel 5 mask */

#define EPWM0								(0x00)	/* EPWM channel 0 number */
#define EPWM1								(0x01)	/* EPWM channel 1 number */
#define EPWM2								(0x02)	/* EPWM channel 2 number */
#define EPWM3								(0x03)	/* EPWM channel 3 number */
#define EPWM4								(0x04)	/* EPWM channel 4 number */
#define EPWM5								(0x05)	/* EPWM channel 5 number */
/*----------------------------------------------------------------------------
 **EPWM����ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_COUNT_UP_DOWN			(0x02)  /*EPWM������COUNT��ģʽ�����¼��������Ķ��룩ģʽ*/
#define EPWM_COUNT_DOWN				(0x00)  /*EPWM������COUNT��ģʽ�����¼��������ض��룩ģʽ*/
/*----------------------------------------------------------------------------
 **EPWM����Ƚϵ�Ԫ(OCU)ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_OCU_ASYMMETRIC			(0x04)  /*EPWM����Ƚϵ�Ԫ��OCU��ģʽ�� �ǶԳƼ���ģʽ*/
#define EPWM_OCU_SYMMETRIC			(0x00)  /*EPWM����Ƚϵ�Ԫ��OCU��ģʽ�� �ԳƼ���ģʽ*/
/*----------------------------------------------------------------------------
 **EPWM���η�������Ԫ(WFG)ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_WFG_INDEPENDENT 		(0x00)  /*EPWM���η�������WFG��ģʽ��������������ģʽ*/
#define EPWM_WFG_COMPLEMENTARY 		(0x10)  /*EPWM���η�������WFG��ģʽ������ģʽ*/
#define EPWM_WFG_SYNCHRONIZED		(0x20)  /*EPWM���η�������WFG��ģʽ��ͬ��ģʽ*/
/*----------------------------------------------------------------------------
 **EPWM������Ƶ�Ԫ(OC)ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_OC_GROUP					(0x08)  /*EPWM������ƣ�OC��ģʽ�� ���ģʽ*/
#define EPWM_OC_INDEPENDENT 			(0x00)  /*EPWM������ƣ�OC��ģʽ�� ͨ�����Զ�������*/
/*----------------------------------------------------------------------------
 **EPWMɲ��Դ
/*---------------------------------------------------------------------------*/
#define EPWM_BRK_SOFTWARE  					(0x00)		/*���ɲ��*/
#define EPWM_BRK_FB							(0x01)		/*FBɲ��*/
#define EPWM_BRK_ACMP0						(0x02)		/*ACMP0ɲ��*/
#define EPWM_BRK_ACMP1						(0x03)		/*ACMP1ɲ��*/
#define EPWM_BRK_ADC						(0x04)		/*ADC�Ƚ�ɲ��*/
/*----------------------------------------------------------------------------
 **EPWMɲ��ԴFBɲ������ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_BRK_FB_LOW						(0x0<< EPWM_PWMFBKC_PWMFBES_Pos)	/*FB�͵�ƽ����ɲ��*/
#define EPWM_BRK_FB_HIGH					(0x1<< EPWM_PWMFBKC_PWMFBES_Pos)	/*FB�ߵ�ƽ����ɲ��*/
/*----------------------------------------------------------------------------
 **EPWM ɲ��������ģʽ
/*---------------------------------------------------------------------------*/
#define EPWM_BRK_COUNT_HOLD					(0x1<< EPWM_PWMFBKC_PWMFBCCE_Pos)	/*ɲ�������������0*/
#define EPWM_BRK_COUNT_CLEAR				(0x00)					/*ɲ�����������0*/

/*----------------------------------------------------------------------------
 **EPWMʱ�ӷ�Ƶϵ��
 * �ܷ�Ƶ(PWMnDIV��Ƶ) = Fpwmn-PSC��Ƶ * CLK_DIV��Ƶ
 *   Fpwmn-PSC��Ƶ = PWMnPSC/2 (PWMnPSC��Ϊ0�����)----2��Ƶ
/*---------------------------------------------------------------------------*/
#define EPWM_CLK_DIV_1						(0xff)					//=Fsys��ϵͳʱ�ӣ�
#define EPWM_CLK_DIV_2						(0x04)					//= Fpwmn-PSC   (PWMnPSC/2)
#define EPWM_CLK_DIV_4						(0x00)					//= Fpwmn-PSC/2 ((PWMnPSC/2)/2)
#define EPWM_CLK_DIV_8						(0x01)					//= Fpwmn-PSC/4 ((PWMnPSC/2)/4)
#define EPWM_CLK_DIV_16						(0x02)					//= Fpwmn-PSC/8 ((PWMnPSC/2)/8)
#define EPWM_CLK_DIV_32						(0x03)					//= Fpwmn-PSC/16((PWMnPSC/2)/16)



/*****************************************************************************
 ** \brief	 EPWM_ENABLE_LOAD
 **			 ʹ�ܼ������ڡ�ռ�ձ�����(PERIODn��CMPn��CMPDn)
 ** \param [in]ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
 ****************************************************************************/
#define EPWM_ENABLE_LOAD(ChannelMask) 	(PWMLOADEN |= ChannelMask)

/*****************************************************************************
 ** \brief	 EPWM_ENABLE_COUNT
 **			 ʹ��EPWM����
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
** \note    
 ****************************************************************************/
#define EPWM_ENABLE_COUNT(ChannelMask) 	(PWMCNTE |= ChannelMask)

/*****************************************************************************
 ** \brief	 EPWM_DISABLE_COUNT
 **			 �ر�EPWM����
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
** \note   
 ****************************************************************************/
#define EPWM_DISABLE_COUNT(ChannelMask) 	(PWMCNTE &= ~ChannelMask)

/*****************************************************************************
 ** \brief	 EPWM_ENABLE_OUTPUT
 **			 ʹ��EPWM���
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK 
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK
 ** \return  none
 ****************************************************************************/
#define EPWM_ENABLE_OUTPUT(ChannelMask) 	(PWMOE |= ChannelMask)
/*****************************************************************************
 ** \brief	 EPWM_DISABLE_OUTPUT
 **			 �ر�EPWM���
 ** \param [in]ChannelMask : EPWM_CH_0_MSK ��EPWM_CH_1_MSK ��EPWM_CH_2_MSK 
 **							 EPWM_CH_3_MSK ��EPWM_CH_4_MSK ��EPWM_CH_5_MSK
 ** \return  none
 ****************************************************************************/
#define EPWM_DISABLE_OUTPUT(ChannelMask) 	(PWMOE &= ~ChannelMask)
/*****************************************************************************
 ** \brief	 EPWM_SET_MASK_LEVEL
 **			����EPWM�����ƽ
 ** \param [in] MaskValue : xx000000 : ����EPWM0~5 ����ֵΪ��
 **						  ......
 **						  xx111111 : ����EPWM0~5 ����ֵΪ��
 ** \return  none
 ** \note    PG0 : bit0 ��PG1��bit1��PG2: bit2��PG3��bit3��PG4��bit4��PG5��bit5
 ****************************************************************************/
#define EPWM_SET_MASK_LEVEL(MaskValue)  (PWMMASKD = MaskValue)

/*****************************************************************************
 ** \brief	 EPWM_ENABLE_MASK
 **			����EPWM�������
 ** \param [in] ChannelMsk : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
 ****************************************************************************/
#define EPWM_ENABLE_MASK(ChannelMsk)  (PWMMASKE |= ChannelMsk)

/*****************************************************************************
 ** \brief	 EPWM_DISABLE_MASK
 **			 �ر�EPWM�������
 ** \param [in] ChannelMsk : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
 ****************************************************************************/
#define EPWM_DISABLE_MASK(ChannelMsk)  (PWMMASKE &= ~(ChannelMsk))

/*****************************************************************************
 ** \brief	 EPWM_SET_BRAKE_LEVEL
 **			����EPWMɲ����ƽ
 ** \param [in]MaskValue : xx000000 : ����EPWM0~5 ɲ����ƽΪ��
 **						  ......
 **						  xx111111 : ����EPWM0~5 ɲ����ƽΪ��
 ** \return  none
 ** \note    PG0 : bit0 ��PG1��bit1��PG2: bit2��PG3��bit3��PG4��bit4��PG5��bit5
 ****************************************************************************/
#define EPWM_SET_BRAKE_LEVEL(BrakeValue)  ( PWMFBKD = BrakeValue)
												  

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	 EPWM_ConfigRunMode
 **			 ����EPWM������ģʽ
 ** \param [in] EpwmRunMode:  
							   (1)EPWM_COUNT_UP_DOWN
							   (2)EPWM_COUNT_DOWN
							   (3)EPWM_OCU_ASYMMETRIC
							   (4)EPWM_OCU_SYMMETRIC
							   (5)EPWM_WFG_INDEPENDENT
							   (6)EPWM_WFG_COMPLEMENTARY
							   (7)EPWM_WFG_SYNCHRONIZED
							   (8)EPWM_OC_GROUP
							   (9)EPWM_OC_INDEPENDENT
 ** \return  none
 ** \note    ����9����ʽ����ϳɲ�ͬ������ģʽ���ҹ���һ��8λ�Ĵ���
 ****************************************************************************/
void EPWM_ConfigRunMode( uint8_t EpwmRunMode);
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelClk	
 ** \param [in] ClkDiv: (1)EPWM_CLK_DIV_1 
 **						(2)EPWM_CLK_DIV_2
 **						(2)EPWM_CLK_DIV_4
 **						(2)EPWM_CLK_DIV_8
 **						(2)EPWM_CLK_DIV_16
 **						(2)EPWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)PWM01PSC��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����PWMxxPSC=0x01
 **	����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ
 **	(2)EPWM ��Ƶ��Ϊ������PWMxPSC PWMnDIV 
 **	��һ����Ƶ(PWMxPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ��ϵͳʱ�ӷ�Ƶϵ��PWMxPSC+1
 **	�ڶ�����Ƶ��PWMnDIV): 0x00 FEPWMPSC/2; 0x01 FEPWMPSC/4��0x02:FEPWMPSC/8��0x3 FEPWMPSC/16
 **	0x04 FEPWMPSC ; ���� Fsys 
 ** ��Ƶ������1~4096����Fsys=8M��EPWM��Ƶ�ʷ�Χ��1.95k ~ 8M	
 ****************************************************************************/
void EPWM_ConfigChannelClk(uint8_t ChannelNum,uint8_t ClkDiv);
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelPeriod
 **			 ����EPWMͨ����Ƶ���Լ�ռ�ձ�
 ** \param [in] ChannelNum : EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
 ****************************************************************************/
void EPWM_ConfigChannelPeriod(uint8_t ChannelNum,uint16_t Period);
 
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelSymDuty
 **			 ����EPWMͨ���Գ�ģʽռ�ձ�
 ** \param [in] ChannelNum  :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				Duty: 16λռ�ձ�
 ** \return none
 ** \note   
 ****************************************************************************/
void EPWM_ConfigChannelSymDuty(uint8_t ChannelNum,uint16_t Duty);
 /*****************************************************************************
 ** \brief	 EPWM_ConfigChannelAsymDuty
 **			 ����EPWMͨ���ǶԳ�ģʽռ�ձ�
 ** \param [in] ChannelNum  :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				DownCmp: 16 bit ���±Ƚ�ֵ
 ** \return none
 ** \note    ֻ���������Ķ������(���¼���)ģʽ
 ****************************************************************************/
void EPWM_ConfigChannelAsymDuty(uint8_t ChannelNum,uint16_t UpCmp, uint16_t DowmCmp);
 
 /****************************************************************************
 ** \brief	 EPWM_EnableOneShotMode
 **			 ����One-Shotģʽ
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void EPWM_EnableOneShotMode(uint8_t ChannelMask);
/****************************************************************************
 ** \brief	 EPWM_EnableAutoLoadMode
 **			 �����Զ�����ģʽ
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void EPWM_EnableAutoLoadMode(uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 EPWM_Start
 **			
 ** \param [in]  ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
 ****************************************************************************/
void EPWM_Start( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_Stop
 **				
 ** \param [in] ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    ֹͣ��������EPWM��������0
*****************************************************************************/
void EPWM_Stop( uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 EPWM_EnableOutput
 **			 ����EPWM���
 ** \param [in] ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableOutput
 **			 �ر�EPWM���
 ** \param [in] ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_DisableOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_EnableFaultBrake
 **			 ����EPWMɲ��ģʽ
 ** \param [in] BrakeSource: [0]: EPWM_BRK_SOFTWARE		:���ɲ��
 **						   	[1]: EPWM_BRK_FB			:�ⲿӲ��ɲ��ͨ��
 **                        	[2]: EPWM_BRK_ACMP0			:�Ƚ���0ɲ��
 **                        	[3]: EPWM_BRK_ACMP1			:�Ƚ���1ɲ��
 ** 					   	[4]: EPWM_BRK_ADC			:ADCɲ��
 **				CountMode:(1)EPWM_BRK_COUNT_HOLD		
 **						  (2)EPWM_BRK_COUNT_CLEAR
 ** \return  none
 ** \note  	 
*****************************************************************************/
void EPWM_EnableFaultBrake( uint8_t BrakeSource , uint8_t CountMode);
/*****************************************************************************
 ** \brief	 EPWM_DisableFaultBrake
 **			 �ر�EPWMɲ��
 ** \param [in] BrakeSource: [0]: EPWM_BRK_SOFTWARE		:���ɲ��
 **						   	[1]: EPWM_BRK_FB			:�ⲿӲ��ɲ��ͨ��
 **                        	[2]: EPWM_BRK_ACMP0			:�Ƚ���0ɲ��
 **                        	[3]: EPWM_BRK_ACMP1			:�Ƚ���1ɲ��
 ** 					   	[4]: EPWM_BRK_ADC			:ADCɲ��
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_DisableFaultBrake( uint8_t BrakeSource);
/****************************************************************************
 ** \brief	 EPWM_ConfigChannelBrakeLevel
 **			 ����EPWMͨ��ɲ����ƽ
 ** \param [in]  ChannelMask�� EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 **		   		 BrakeLevel: FaultBreake���EPWMͨ����ƽ ��0/1(��/��)
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelBrakeLevel( uint8_t ChannelMask, uint8_t BrakeLevel);

/****************************************************************************
 ** \brief	 EPWM_EnableDeadZone
 **			 ��������
 ** \param [in] ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK		
 **			DeadTime : ����ʱ��( 0~0xFF) = DeadTime * Tepwm
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_EnableDeadZone( uint8_t ChannelMask, uint8_t DeadTime);
/*****************************************************************************
 ** \brief	 EPWM_DisableDeadZone
 **			 �ر�EPWM����
 ** \param [in] ChannelMask:  EPWM_CH_0_MSK ~ EPWM_CH_5_MSK		
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_DisableDeadZone( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_EnableMaskControl
 **			 ������ƿ���
 ** \param [in] ChannelMask:  EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	 	
 ** 	    	MaskLevel: ��������� :0/1(��/��)
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableMaskControl( uint8_t ChannelMask, uint8_t MaskLevel);
/*****************************************************************************
 ** \brief	 EPWM_DisableMaskControl
 **			 ������ƹر�
 ** \param [in] ChannelMask:  EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	 		
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableMaskControl( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_EnableUpCmpInt
 **			 �������ϱȽ��ж�
 ** \param [in]  ChannelMask�� EPWM_CH_0_MSK ~ EPWM_CH_5_MSK		
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableUpCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableUpCmptInt
 **			 �ر����ϱȽ��ж�
 ** \param [in]ChannelMask ��EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableUpCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			 ��ȡ���ϱȽ��жϱ�־λ
 ** \param [in] ChannelNum:EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5 
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetUpCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			 ������ϱȽ��жϱ�־λ
 ** \param [in] ChannelNum:EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ClearUpCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			 ��ȡ���±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetDownCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			 ������±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ClearDownCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_EnablePeriodInt
 **			 ���������ж�
 ** \param [in] ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_EnablePeriodInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisablePeriodInt
 **			 �ر������ж�
 ** \param [in]  ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_DisablePeriodInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			 ��ȡ�����жϱ�־λ 
 ** \param [in]  ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   0�����жϲ���
 **           1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetPeriodIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			 ��������жϱ�־λ 
 ** \param [in]  ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_ClearPeriodIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in]  ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_EnableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableZeroInt
 **			 �ر�����ж� 
 ** \param [in]ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_DisableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_GetZeroIntFlag
 **			 ��ȡ����жϱ�־λ 
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   0�����жϲ���
 **           1�����жϲ���   
 ** \note   
 *****************************************************************************/
uint8_t EPWM_GetZeroIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_ClearZeroIntFlag
 **			 �������жϱ�־λ
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_ClearZeroIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 EPWM_EnableFaultBrakeInt	
 **			 ��������ɲ���ж� 
 ** \param [in]none
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_EnableFaultBrakeInt( void);
/*****************************************************************************
 ** \brief	 EPWM_DisableFaultBrakeInt	
 **			 �رչ���ɲ���ж� 
 ** \param [in]none
 ** \return  none
 ** \note 
*****************************************************************************/
void EPWM_DisableFaultBrakeInt(void);
/*****************************************************************************
 ** \brief	 EPWM_GetFaultBrakeIntFlag
 **			 ��ȡ����ɲ���жϱ�־λ
 ** \param [in] none
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note  
*****************************************************************************/
uint8_t EPWM_GetFaultBrakeIntFlag( void);
/*****************************************************************************
 ** \brief	 EPWM_ClearFaultBrakeIntFlag	
 ** 		 �������ɲ���жϱ�־λ 
 ** \param [in] none
 ** \return  none
 ** \note 
 *****************************************************************************/
void EPWM_ClearFaultBrakeIntFlag( void);
/*****************************************************************************
 ** \brief	 EPWM_TrigSoftwareBrake
 **			  �������ɲ��
 ** \param [in]	none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_TrigSoftwareBrake(void);
/*****************************************************************************
 ** \brief	 EPWM_DisableSoftwareBreake
 **			 �ر����ɲ��
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_DisableSoftwareBrake(void);
/*****************************************************************************
 ** \brief	 EPWM_EnableReverseOutput
 **			 �����������
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note  ����ģʽ�� EPWM ��ʼ�ӳ�ֵ��ʼ����ʱ��PWM��������Ϊ�͵�ƽ, 
 **	��EPWM����ֵ�����ϡ����¼���ƥ��ʱ�������ת
*****************************************************************************/
void  EPWM_EnableReverseOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_DisableReverseOutput
 **			 �رշ������
 ** \param [in]ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_DisableReverseOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 EPWM_ConfigFBBrake
 **			 ����FBɲ��
 ** \param [in] FBBrakeLevel : ��������(1)EPWM_BRK_FB_LOW
 **                           		    (2)EPWM_BRK_FB_HIGH	
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_ConfigFBBrake(uint8_t FBBrakeLevel);

/*****************************************************************************
 ** \brief	 EPWM_AllIntEnable
 **			 ʹ��EPWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_AllIntEnable(void);
/*****************************************************************************
 ** \brief	 EPWM_AllIntDisable
 **			 �ر�EPWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_AllIntDisable(void);

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

#endif /* __EPWM_H__ */







