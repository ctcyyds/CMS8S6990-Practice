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
/** \file i2c.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __I2C_H__
#define __I2C_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/


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
 ** \brief	I2C_ConfigCLK
 **			����I2C��ʱ��
 ** \param [in] I2CMtp: 0x0~0x7f
 ** \return  none
 ** \note	(1)I2CMtp = 0 ,SCL = 3*10*Tsys
 **			(2)I2CMtp != 0, SCL = 2*(1+I2CMtp)*10*Tsys
*****************************************************************************/
void I2C_ConfigCLK(uint8_t I2CMtp);

/*****************************************************************************
 ** \brief	I2C_EnableMasterMode
 **			ʹ������ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void I2C_EnableMasterMode(void);
/*****************************************************************************
 ** \brief	I2C_DisableMasterMode
 **			�ر�����ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void I2C_DisableMasterMode(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterSendAddrFlag
 **			��ȡ����ģʽѰַӦ���־
 ** \param [in] none
 ** \return 0: �ӻ���Ӧ��  1���ӻ���Ӧ��
 ** \note	 
*****************************************************************************/
uint8_t I2C_GetMasterSendAddrFlag(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterSendDataFlag
 **			��ȡ����ģ��������Ӧ���־
 ** \param [in] none
 ** \return 0: �ӻ���Ӧ��  1���ӻ���Ӧ��
 ** \note	 
*****************************************************************************/
uint8_t I2C_GetMasterSendDataFlag(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterBusArbitrationFlag
 **			��ȡ����ģ�����ٲñ�־
 ** \param [in] none
 ** \return 0: ����  1:��ʧ�����߿���Ȩ
 ** \note	 
*****************************************************************************/
uint8_t I2C_GetMasterBusArbitrationFlag(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterErrorFlag
 **			��ȡ����ģʽ�����־
 ** \param [in] none
 ** \return 0: �޴��� 1���д���
 ** \note	�����־����������(1)Ѱַ�ӻ���Ӧ�� (2)�������ݴӻ���Ӧ��
 **							  (3)I2C�����ٲó�ͻ
*****************************************************************************/
uint8_t I2C_GetMasterErrorFlag(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterBusyFlag
 **			��ȡ����ģ��Busy״̬��־
 ** \param [in] none
 ** \return  1�����ڷ���
 ** \note	
*****************************************************************************/
uint8_t I2C_GetMasterBusyFlag(void);

/*****************************************************************************
 ** \brief	I2C_GetMasterIdleFlag
 **			��ȡ����ģʽ����״̬��־
 ** \param [in] none
 ** \return 0: ���� 1������
 ** \note	
*****************************************************************************/
uint8_t I2C_GetMasterIdleFlag(void);
/*****************************************************************************
 ** \brief	I2C_GetBusBusyFlag
 **			��ȡ����æ״̬��־
 ** \param [in] none
 ** \return 0: ���� 1������æ
 ** \note	
*****************************************************************************/
uint8_t I2C_GetBusBusyFlag(void);

/*****************************************************************************
 ** \brief	I2C_EnableInt
 **			�����ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void I2C_EnableInt(void);
/*****************************************************************************
 ** \brief	I2C_DisableInt
 **			�ر��ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void I2C_DisableInt(void);
/*****************************************************************************
 ** \brief	I2C_GetMasterIntFlag
 **			��ȡ����ģʽ�µ��жϱ�־λ
 ** \param [in] none
 ** \return  0:���ж� 1�����ж�
 ** \note	 
*****************************************************************************/
uint8_t I2C_GetMasterIntFlag(void);
/*****************************************************************************
 ** \brief	I2C_ClearMasterIntFlag
 **			�������ģʽ�µ��жϱ�־λ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void I2C_ClearMasterIntFlag(void);











#endif /* __I2C_H__ */
