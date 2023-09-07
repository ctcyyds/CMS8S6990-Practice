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
/** \file epwm.c
**
** 
**
**	History:
**	
*****************************************************************************/

/****************************************************************************/
/*	include files
*****************************************************************************/
#include "epwm.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros ('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions (declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions ('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions ('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes ('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/
/********************************************************************************
 ** \brief	 EPWM_ConfigRunMode
 **			 ����EPWM������ģʽ
 ** \param [in] EpwmRunModeMask: (1)EPWM_COUNT_UP_DOWN
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
 **			 ʹ�÷����ɲο�app_epwm.c
 ******************************************************************************/
void EPWM_ConfigRunMode( uint8_t EpwmRunModeMask)
{
	PWMCON = EpwmRunModeMask; 			/*ע��ֱ�Ӹ�ֵ*/
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelClk	
** \param [in] ChannelNum : EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				ClkDiv: (1)EPWM_CLK_DIV_1 
 **						(2)EPWM_CLK_DIV_2
 **						(3)EPWM_CLK_DIV_4
 **						(4)EPWM_CLK_DIV_8
 **						(5)EPWM_CLK_DIV_16
 **						(6)EPWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)����ΪPWM01PSC��ͬ����PWM0��PWM1ͨ�� �����Դ˺���ͳһ����PWMPSC=0x01
 **	����Ҫ�����ķ�Ƶ��������ԼĴ�����ֵ
 **	(2)EPWM ��Ƶ��Ϊ������PWMxPSC PWMnDIV 
 **	��һ����Ƶ(PWMxPSC)��0x00 Ԥ��Ƶֹͣ���Ҽ�����ֹͣ��ϵͳʱ�ӷ�Ƶϵ��PWMxPSC+1
 **	�ڶ�����Ƶ��PWMnDIV): 0x00 FEPWMPSC/2; 0x01 FEPWMPSC/4��0x02:FEPWMPSC/8��0x3 FEPWMPSC/16
 **	0x04 FEPWMPSC ; ���� Fsys 
 ** ��Ƶ������1~4096����Fsys=8M��EPWM��Ƶ�ʷ�Χ��1.95k ~ 8M	
*****************************************************************************/
void EPWM_ConfigChannelClk(uint8_t ChannelNum,uint8_t ClkDiv)
{
	switch(ChannelNum)
	{
		case EPWM0:
			 PWM01PSC = 0x01;
			 PWM0DIV = ClkDiv;
			break;
		case EPWM1:
			PWM01PSC = 0x01;
			PWM1DIV = ClkDiv;
			break;
		case EPWM2:
			 PWM23PSC = 0x01;
			 PWM2DIV = ClkDiv;
			 break;
		case EPWM3:
			 PWM23PSC = 0x01;
			 PWM3DIV = ClkDiv;
			 break;	
		case EPWM4:
			 PWM45PSC = 0x01;
			 PWM4DIV = ClkDiv;
			 break;				
		case EPWM5:
			 PWM45PSC = 0x01;
			 PWM5DIV = ClkDiv;
			 break;		
		default:
			break;
	}
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelPeriod
 **			 ����EPWMͨ����Ƶ���Լ�ռ�ձ�
 ** \param [in] ChannelNum : EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				Period: 16λ����ֵ
 ** \return none
 ** \note    
 ****************************************************************************/
void EPWM_ConfigChannelPeriod(uint8_t ChannelNum,uint16_t Period)
{	
	switch(ChannelNum)
	{
		case EPWM0:
			PWMP0H = Period>>8;
			PWMP0L = Period;
			PWMLOADEN |= EPWM_CH_0_MSK;
			break;
		case EPWM1:
			PWMP1H = Period>>8;
			PWMP1L = Period;
			PWMLOADEN |= EPWM_CH_1_MSK;
			break;
		case EPWM2:
			PWMP2H = Period>>8;
			PWMP2L = Period;
			PWMLOADEN |= EPWM_CH_2_MSK;
			break;
		case EPWM3:
			PWMP3H = Period>>8;
			PWMP3L = Period;
			PWMLOADEN |= EPWM_CH_3_MSK;
			break;	
		case EPWM4:
			PWMP4H = Period>>8;
			PWMP4L = Period;
			PWMLOADEN |= EPWM_CH_4_MSK;
			break;				
		case EPWM5:
			PWMP5H = Period>>8;
			PWMP5L = Period;
			PWMLOADEN |= EPWM_CH_5_MSK;
			break;		
		default:
			break;
	}	
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigChannelSymDuty
 **			 ����EPWMͨ���Գ�ģʽռ�ձ�
 ** \param [in] ChannelNum  :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				Duty: 16λռ�ձ�
 ** \return none
 ** \note   
 ****************************************************************************/
void EPWM_ConfigChannelSymDuty(uint8_t ChannelNum,uint16_t Duty)
{
	switch(ChannelNum)
	{
		case EPWM0:
			PWMD0H = Duty>>8;
			PWMD0L = Duty;
			PWMLOADEN |= EPWM_CH_0_MSK;
			break;
		case EPWM1:
			PWMD1H = Duty>>8;
			PWMD1L = Duty;
			PWMLOADEN |= EPWM_CH_1_MSK;
			break;
		case EPWM2:
			PWMD2H = Duty>>8;
			PWMD2L = Duty;
			PWMLOADEN |= EPWM_CH_2_MSK;
			break;
		case EPWM3:
			PWMD3H = Duty>>8;
			PWMD3L = Duty;
			PWMLOADEN |= EPWM_CH_3_MSK;
			break;	
		case EPWM4:
			PWMD4H = Duty>>8;
			PWMD4L = Duty;
			PWMLOADEN |= EPWM_CH_4_MSK;
			break;				
		case EPWM5:
			PWMD5H = Duty>>8;
			PWMD5L = Duty;
			PWMLOADEN |= EPWM_CH_5_MSK;
			break;		
		default:
			break;
	}		
}
 /*****************************************************************************
 ** \brief	 EPWM_ConfigChannelAsymDuty
 **			 ����EPWMͨ���ǶԳ�ģʽռ�ձ�
 ** \param [in] ChannelNum  :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 **				DownCmp: 16 bit ���±Ƚ�ֵ
 ** \return none
 ** \note    ֻ���������Ķ������(���¼���)ģʽ
 ****************************************************************************/
void EPWM_ConfigChannelAsymDuty(uint8_t ChannelNum,uint16_t UpCmp, uint16_t DowmCmp)
{
	switch(ChannelNum)
	{
		case EPWM0:
			PWMD0H = UpCmp>>8;
			PWMD0L = UpCmp;
			PWMDD0H = DowmCmp>>8;
			PWMDD0L = DowmCmp;	
			PWMLOADEN |= EPWM_CH_0_MSK;		
			break;
		case EPWM1:
			PWMD1H = UpCmp>>8;
			PWMD1L = UpCmp;
			PWMDD1H = DowmCmp>>8;
			PWMDD1L = DowmCmp;	
			PWMLOADEN |= EPWM_CH_1_MSK;
			break;
		case EPWM2:
			PWMD2H = UpCmp>>8;
			PWMD2L = UpCmp;
			PWMDD2H = DowmCmp>>8;
			PWMDD2L = DowmCmp;
			PWMLOADEN |= EPWM_CH_2_MSK;		
			break;
		case EPWM3:
			PWMD3H = UpCmp>>8;
			PWMD3L = UpCmp;
			PWMDD3H = DowmCmp>>8;
			PWMDD3L = DowmCmp;
			PWMLOADEN |= EPWM_CH_3_MSK;		
			break;	
		case EPWM4:
			PWMD4H = UpCmp>>8;
			PWMD4L = UpCmp;
			PWMDD4H = DowmCmp>>8;
			PWMDD4L = DowmCmp;	
			PWMLOADEN |= EPWM_CH_4_MSK;
			break;				
		case EPWM5:
			PWMD5H = UpCmp>>8;
			PWMD5L = UpCmp;
			PWMDD5H = DowmCmp>>8;
			PWMDD5L = DowmCmp;	
			PWMLOADEN |= EPWM_CH_5_MSK;
			break;		
		default:
			break;
	}		
}
/****************************************************************************
 ** \brief	 EPWM_EnableOneShotMode
 **			 ����One-Shotģʽ
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void EPWM_EnableOneShotMode(uint8_t ChannelMask)
{			
	PWMCNTM &= ~ChannelMask;	
}
/****************************************************************************
 ** \brief	 EPWM_EnableAutoLoadMode
 **			 �����Զ�����ģʽ
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void EPWM_EnableAutoLoadMode(uint8_t ChannelMask)
{			
	PWMCNTM |= ChannelMask;	
}

/****************************************************************************
 ** \brief	 EPWM_Start		
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note	
 ****************************************************************************/
void EPWM_Start( uint8_t ChannelMask)
{			
	PWMCNTE |= ChannelMask;		/*ʹ��PWMn������*/
}
/*****************************************************************************
 ** \brief	 EPWM_Stop
 **
 ** \param [in] ChannelMask  : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_Stop( uint8_t ChannelMask)
{
	PWMCNTE &= ~ ChannelMask;		/*ֹͣ����*/
}

/*****************************************************************************
 ** \brief	 EPWM_EnableOutput
 **			 ����EPWM���
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK   
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableOutput( uint8_t ChannelMask)
{
	PWMOE |= ChannelMask;		/*ʹ��PWM���*/	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableOutput
 **			 �ر�EPWM���
 ** \param [in]  ChannelMask   EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_DisableOutput( uint8_t ChannelMask)
{
	PWMOE &= ~(ChannelMask);		
}
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
void EPWM_EnableFaultBrake( uint8_t BrakeSource , uint8_t CountMode)
{
	uint8_t Temp=0;
	
	Temp = PWMFBKC;
	Temp &= ~(EPWM_PWMFBKC_PWMFBCCE_Msk);
	Temp |= CountMode;
	PWMFBKC = Temp;
	switch(BrakeSource)
	{
		case EPWM_BRK_FB:
			PWMFBKC |= EPWM_PWMFBKC_PWMFBEN_Msk;
			break;
		case EPWM_BRK_ACMP0:
			CNFBCON |= ACMP_CNFBCON_C0FBEN_Msk;
			break;
		case EPWM_BRK_ACMP1:
			CNFBCON |= ACMP_CNFBCON_C1FBEN_Msk;
			break;
		case EPWM_BRK_ADC:
			ADCMPC |= ADC_ADCMPC_ADFBEN_Msk;
			break;
		case EPWM_BRK_SOFTWARE:
			break;
		default:
			break;	
	}
}
/*****************************************************************************
 ** \brief	 EPWM_DisableFaultBrake
 **			 �ر�EPWMɲ��ģʽ
 ** \param [in] BrakeSource: [0]: EPWM_BRK_SOFTWARE		:���ɲ��
 **						   	[1]: EPWM_BRK_FB			:�ⲿӲ��ɲ��ͨ��
 **                        	[2]: EPWM_BRK_ACMP0			:�Ƚ���0ɲ��
 **                        	[3]: EPWM_BRK_ACMP1			:�Ƚ���1ɲ��
 ** 					   	[4]: EPWM_BRK_ADC			:ADCɲ��
 ** \return  none
 ** \note    
*****************************************************************************/
void EPWM_DisableFaultBrake( uint8_t BrakeSource)
{
	switch(BrakeSource)
	{
		case EPWM_BRK_FB:
			PWMFBKC &= ~(EPWM_PWMFBKC_PWMFBEN_Msk);
			break;
		case EPWM_BRK_ACMP0:
			CNFBCON &= ~(ACMP_CNFBCON_C0FBEN_Msk);
			break;
		case EPWM_BRK_ACMP1:
			CNFBCON &= ~(ACMP_CNFBCON_C1FBEN_Msk);
			break;
		case EPWM_BRK_ADC:
			ADCMPC &= ~(ADC_ADCMPC_ADFBEN_Msk);
			break;
		case EPWM_BRK_SOFTWARE:
			break;
		default:
			break;	
	}
}
/****************************************************************************
 ** \brief	 EPWM_ConfigChannelBrakeLevel
 **			 ����EPWMͨ��ɲ����ƽ
 ** \param [in]  ChannelMask�� EPWM_CH_0_MSK ~ EPWM_CH_5_MSK
 **		   		 BrakeLevel: FaultBreake���EPWMͨ����ƽ ��0/1(��/��)
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ConfigChannelBrakeLevel( uint8_t ChannelMask, uint8_t BrakeLevel)
{	
	if(1 == BrakeLevel)
	{
		PWMFBKD  |= ChannelMask;		
	}
	else
	{
		PWMFBKD  &= ~(ChannelMask);		
	}
}
/****************************************************************************
 ** \brief	 EPWM_EnableDeadZone
 **			 ��������
 ** \param [in] Channel: EPWM0��EPWM1....EPWM5		
 **			DeadTime : ����ʱ��( 0~0xFF) = DeadTime * Tepwm
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_EnableDeadZone( uint8_t Channel, uint8_t DeadTime)
{
	switch(Channel)
	{
		case EPWM0:
		case EPWM1:
			PWMDTE  |= EPWM_PWMDTE_PWM01DTE_Msk;
			PWM01DT = DeadTime;
			break;
		case EPWM2:
		case EPWM3:
			PWMDTE  |= EPWM_PWMDTE_PWM23DTE_Msk;
			PWM23DT = DeadTime;
			break;
		case EPWM4:
		case EPWM5:
			PWMDTE  |= EPWM_PWMDTE_PWM45DTE_Msk;
			PWM45DT = DeadTime;
			break;
		default:
			break;		
	}	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableDeadZone
 **			 �ر�EPWM����
 ** \param [in] Channel: EPWM0��EPWM1....EPWM5	
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_DisableDeadZone( uint8_t Channel)
{
	switch(Channel)
	{
		case EPWM0:
		case EPWM1:
			PWMDTE  &= ~(EPWM_PWMDTE_PWM01DTE_Msk);
			break;
		case EPWM2:
		case EPWM3:
			PWMDTE  &= ~(EPWM_PWMDTE_PWM23DTE_Msk);
			break;
		case EPWM4:
		case EPWM5:
			PWMDTE  &= ~(EPWM_PWMDTE_PWM45DTE_Msk);
			break;
		default:
			break;		
	}
}
/*****************************************************************************
 ** \brief	 EPWM_EnableMaskControl
 **			 ������ƿ���
 ** \param [in] ChannelMask:  EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	 	
 ** 	    	MaskLevel: ��������� :0/1(��/��)
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableMaskControl( uint8_t ChannelMask, uint8_t MaskLevel)
{
	if(1 == MaskLevel)
	{
		PWMMASKD  |= ChannelMask;		
	}
	else
	{
		PWMMASKD  &= ~(ChannelMask);		
	}
	
	PWMMASKE  |= ChannelMask;			/*ʹ�ܿ���λ*/	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableMaskControl
 **			 ������ƹر�
 ** \param [in] ChannelMask:  EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	 		
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableMaskControl( uint8_t ChannelMask)
{	
	PWMMASKE  &=~(ChannelMask);		
}
/*****************************************************************************
 ** \brief	 EPWM_EnableUpCmpInt
 **			 �������ϱȽ��ж�
 ** \param [in]  ChannelMask�� EPWM_CH_0_MSK ~ EPWM_CH_5_MSK		
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableUpCmpInt( uint8_t ChannelMask)
{
	PWMUIE |= ChannelMask ;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableUpCmptInt
 **			 �ر����ϱȽ��ж�
 ** \param [in]  ChannelMask ��EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableUpCmpInt( uint8_t ChannelMask)
{
	PWMUIE &= ~ChannelMask ;
}
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			 ��ȡ���ϱȽ��жϱ�־λ
 ** \param [in] ChannelNum:EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetUpCmpIntFlag( uint8_t ChannelNum)
{
	return(PWMUIF & (1<<ChannelNum)? 1:0);

}
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			 ������ϱȽ��жϱ�־λ
 ** \param [in] ChannelNum:EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ClearUpCmpIntFlag( uint8_t ChannelNum)
{
	PWMUIF = 0xff & (~(1<<ChannelNum));
}
/*****************************************************************************
 ** \brief	 EPWM_EnableDownCmpInt
 **			 �������±Ƚ��ж�
 ** \param [in]ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_EnableDownCmpInt( uint8_t ChannelMask)
{
	PWMDIE  |= ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableDownCmpInt
 **			 �ر����±Ƚ��ж�
 ** \param [in]  ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_DisableDownCmpInt( uint8_t ChannelMask)
{
	PWMDIE  &= ~ChannelMask;	
}
/*****************************************************************************
 ** \brief	 EPWM_GetUpCmpIntFlag
 **			 ��ȡ���±Ƚ��жϱ�־λ
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetDownCmpIntFlag( uint8_t ChannelNum)
{
	return(PWMDIF & (1<<ChannelNum)? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearUpCmpIntFlag
 **			 ������±Ƚ��жϱ�־λ
 ** \param [in]  ChannelNum :EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void EPWM_ClearDownCmpIntFlag( uint8_t ChannelNum)
{
	PWMDIF = 0xff & (~(1<<ChannelNum));
}
/*****************************************************************************
 ** \brief	 EPWM_EnablePeriodInt
 **			 ���������ж�
 ** \param [in]  ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_EnablePeriodInt( uint8_t ChannelMask)
{
	PWMPIE |= ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_DisablePeriodInt
 **			 �ر������ж�
 ** \param [in]ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_DisablePeriodInt( uint8_t ChannelMask)
{
	PWMPIE &= ~ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			 ��������жϱ�־λ 
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_ClearPeriodIntFlag( uint8_t ChannelNum)
{
	PWMPIF = 0xff & (~(1<<ChannelNum));
}
/*****************************************************************************
 ** \brief	 EPWM_ClearPeriodIntFlag
 **			 ��ȡ�����жϱ�־λ 
 ** \param [in] ChannelNum: 0~5
 ** \return   0�����жϲ���
 **           1�����жϲ���
 ** \note   
*****************************************************************************/
uint8_t EPWM_GetPeriodIntFlag( uint8_t ChannelNum)
{
	return(PWMPIF & (1<<ChannelNum)? 1:0);
}

/*****************************************************************************
 ** \brief	 EPWM_EnableZeroInt
 **			 ��������ж�
 ** \param [in] ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_EnableZeroInt( uint8_t ChannelMask)
{
	PWMZIE |= ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableZeroInt
 **			 �ر�����ж� 
 ** \param [in]ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_DisableZeroInt( uint8_t ChannelMask)
{
	PWMZIE &= ~ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_ClearZeroIntFlag
 **			 �������жϱ�־λ
 ** \param [in]  ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void EPWM_ClearZeroIntFlag( uint8_t ChannelNum)
{
	PWMZIF = 0xff & (~(1<<ChannelNum));
}
/*****************************************************************************
 ** \brief	 EPWM_GetZeroIntFlag
 **			 ��ȡ����жϱ�־λ 
 ** \param [in] ChannelNum: EPWM0,EPWM1,EPWM2,EPWM3,EPWM4,EPWM5
 ** \return   0�����жϲ���
 **           1�����жϲ���   
 ** \note   
 *****************************************************************************/
uint8_t EPWM_GetZeroIntFlag( uint8_t ChannelNum)
{
	return(PWMZIF & (1<<ChannelNum)? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_EnableFaultBrakeInt
 **			 ��������ɲ���ж� 
 ** \param [in] none
 ** \return  none
 ** \note  
*****************************************************************************/
void EPWM_EnableFaultBrakeInt( void)
{
	PWMFBKC  &=~(EPWM_PWMFBKC_PWMFBF_Msk);   /*��ɲ����־λ*/
	PWMFBKC  |= EPWM_PWMFBKC_PWMFBIE_Msk;   /*����ɲ���ж�*/
	
}
/*****************************************************************************
 ** \brief	 EPWM_DisableFaultBrakeInt	
 **			 �رչ���ɲ���ж� 
 ** \param [in]none
 ** \return  none
 ** \note 
*****************************************************************************/
void EPWM_DisableFaultBrakeInt(void)
{
	PWMFBKC  &= ~(EPWM_PWMFBKC_PWMFBIE_Msk);
}
/*****************************************************************************
 ** \brief	 EPWM_GetFaultBrakeIntFlag
 **			 ��ȡ����ɲ���жϱ�־λ
 ** \param [in] none
 ** \return  0: ���жϲ���
 **          1�����жϲ���
 ** \note  
*****************************************************************************/
uint8_t EPWM_GetFaultBrakeIntFlag(void)
{
	return((PWMFBKC & (EPWM_PWMFBKC_PWMFBF_Msk))? 1:0);
}
/*****************************************************************************
 ** \brief	 EPWM_ClearFaultBrakeIntFlag	
 ** 		 �������ɲ���жϱ�־λ 
 ** \param [in] none
 ** \return  none
 ** \note 
*****************************************************************************/
void EPWM_ClearFaultBrakeIntFlag( void)
{
	PWMFBKC  &= ~(EPWM_PWMFBKC_PWMFBF_Msk);   /*��ɲ����־λ*/
}

/*****************************************************************************
 ** \brief	 EPWM_EnableReverseOutput
 **			 �����������
 ** \param [in] ChannelMask : EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note  ����ģʽ�� EPWM ��ʼ�ӳ�ֵ��ʼ����ʱ��PWM��������Ϊ�͵�ƽ, 
 **	��EPWM����ֵ�����ϡ����¼���ƥ��ʱ�������ת
*****************************************************************************/
void  EPWM_EnableReverseOutput( uint8_t ChannelMask)
{
	PWMPINV |=ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableReverseOutput
 **			 �رշ������
 ** \param [in] ChannelMask: EPWM_CH_0_MSK ~ EPWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_DisableReverseOutput( uint8_t ChannelMask)
{
	PWMPINV &=~ChannelMask;
}
/*****************************************************************************
 ** \brief	 EPWM_TrigSoftwareBrake
 **			 �������ɲ��
 ** \param [in]	none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_TrigSoftwareBrake(void)
{
	PWMFBKC |= EPWM_PWMFBKC_PWMFBKSW_Msk;
}
/*****************************************************************************
 ** \brief	 EPWM_DisableSoftwareBreake
 **			 �ر����ɲ��
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_DisableSoftwareBrake(void)
{
	PWMFBKC &= ~(EPWM_PWMFBKC_PWMFBKSW_Msk);
}
/*****************************************************************************
 ** \brief	 EPWM_ConfigFBBrake
 **			 ����FBɲ��
 ** \param [in] FBBrakeLevel : ��������(1)EPWM_BRK_FB_LOW
 **                           		    (2)EPWM_BRK_FB_HIGH	
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_ConfigFBBrake(uint8_t FBBrakeLevel)
{
	uint8_t Temp=0;
	
	Temp = PWMFBKC;
	Temp &= ~(EPWM_PWMFBKC_PWMFBES_Msk);
	Temp |=  FBBrakeLevel;
	PWMFBKC = Temp;
}
/*****************************************************************************
 ** \brief	 EPWM_AllIntEnable
 **			 ʹ��EPWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  EPWM_AllIntEnable(void)
{
	EIE2 |= IRQ_EIE2_PWMIE_Msk;
}
/*****************************************************************************
 ** \brief	 EPWM_AllIntDisable
 **			 �ر�EPWM���ж�
 ** \param [in] none
 ** \return  none
 ** \note   
 ****************************************************************************/
void  EPWM_AllIntDisable(void)
{
	EIE2 &= ~(IRQ_EIE2_PWMIE_Msk);
}
