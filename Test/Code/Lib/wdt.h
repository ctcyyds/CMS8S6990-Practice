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
/** \file WDT.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __WDT_H__
#define __WDT_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **WDT ʱ�ӷ�Ƶ
/*---------------------------------------------------------------------------*/
#define WDT_CLK_131072 			(0x00)		/*���ʱ��= Tsys * 131072  (2^17 * Tsys)*/
#define WDT_CLK_262144 			(0x01)		/*���ʱ��= Tsys * 262144  (2^18 * Tsys)*/
#define WDT_CLK_524288 			(0x02)		/*���ʱ��= Tsys * 524288  (2^19 * Tsys)*/
#define WDT_CLK_1048576			(0x03)		/*���ʱ��= Tsys * 1048576  (2^20 * Tsys)*/
#define WDT_CLK_2097152 		(0x04)		/*���ʱ��= Tsys * 2097152  (2^21 * Tsys)*/
#define	WDT_CLK_4194304			(0x05)		/*���ʱ��= Tsys * 4194304  (2^22 * Tsys)*/
#define	WDT_CLK_16777216		(0x06)		/*���ʱ��= Tsys * 16777216 (2^24 * Tsys)*/
#define	WDT_CLK_67108864		(0x07)		/*���ʱ��= Tsys * 67108864 (2^26 * Tsys)*/



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
 ** \brief	 WDT_ConfigOverflowTime
 **			����WDT���ʱ��
 ** \param [in] TsysCoefficient : (1)WDT_CLK_131072 	
 **								  (2)WDT_CLK_262144 
 **								  (3)WDT_CLK_524288
 **								  (4)WDT_CLK_1048576 
 **								  (5)WDT_CLK_2097152 
 **								  (6)WDT_CLK_4194304 
 **								  (7)WDT_CLK_16777216 
 **								  (8)WDT_CLK_67108864 
 ** \return none 
 ** \note	��Fsys =16Mhz, ��     (1)WDT_CLK_131072  , ���ʱ��= Tsys * 131072 = 8.192ms
 **								  (2)WDT_CLK_262144 , ���ʱ��= Tsys * 262144 = 16.384ms
 **								  (3)WDT_CLK_524288 , ���ʱ��= Tsys * 524288 = 32.768ms
 **								  (4)WDT_CLK_1048576 , ���ʱ��= Tsys * 1048576 = 65.536ms
 **								  (5)WDT_CLK_2097152 , ���ʱ��= Tsys * 2097152 = 131.072ms
 **								  (6)WDT_CLK_4194304 , ���ʱ��= Tsys * 4194304 = 262.144ms
 **								  (7)WDT_CLK_16777216 , ���ʱ��= Tsys * 16777216 = 1.048s 
 **								  (8)WDT_CLK_67108864 , ���ʱ��= Tsys * 67108864 = 4.194s 
 *****************************************************************************/
void  WDT_ConfigOverflowTime(uint8_t TsysCoefficient);

/*****************************************************************************
 ** \brief	 WDT_ClearWDT
 **			���WDT������
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
void WDT_ClearWDT(void);

/*****************************************************************************
 ** \brief	 WDT_EnableOverflowInt
 **			 ʹ��WDT��������ж�
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WDT_EnableOverflowInt(void);
/*****************************************************************************
 ** \brief	 WDT_EnableOverflowInt
 **			 �ر�WDT��������ж�
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WDT_DisableOverflowInt(void);
/*****************************************************************************
 ** \brief	 WDT_GetOverflowIntFlag
 **			 ��ȡWDT��������жϱ�־
 ** \param [in] none
 **
 ** \return 0�����жϣ�1�����ж�
 ** \note
 *****************************************************************************/
uint8_t WDT_GetOverflowIntFlag(void);
/*****************************************************************************
 ** \brief	 WDT_ClearOverflowIntFlag
 **			 ���WDT��������жϱ�־
 ** \param [in] none
 **
 ** \return 0�����жϣ�1�����ж�
 ** \note
 *****************************************************************************/
void WDT_ClearOverflowIntFlag(void);



#endif /* __WDT_H__ */
