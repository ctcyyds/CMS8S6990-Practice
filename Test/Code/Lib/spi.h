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
/** \file spi.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __SPI_H__
#define __SPI_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms8s6990.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **SPI ʱ�ӷ�Ƶ
/*---------------------------------------------------------------------------*/
#define		SPI_CLK_DIV_4		(0x00)
#define		SPI_CLK_DIV_8		(0x1<< SPI_SPCR_SPRn_Pos)
#define		SPI_CLK_DIV_16		(0x2<< SPI_SPCR_SPRn_Pos)
#define		SPI_CLK_DIV_32		(0x3<< SPI_SPCR_SPRn_Pos)
#define		SPI_CLK_DIV_64		(0x1<< SPI_SPCR_SPR2_Pos)
#define		SPI_CLK_DIV_128		((0x1<< SPI_SPCR_SPR2_Pos) | (0x1<< SPI_SPCR_SPRn_Pos))
#define		SPI_CLK_DIV_256		((0x1<< SPI_SPCR_SPR2_Pos) | (0x2<< SPI_SPCR_SPRn_Pos))
#define		SPI_CLK_DIV_512		((0x1<< SPI_SPCR_SPR2_Pos) | (0x3<< SPI_SPCR_SPRn_Pos))

/*----------------------------------------------------------------------------
 **SPI ʱ�Ӽ���
/*---------------------------------------------------------------------------*/
#define		SPI_CLK_CPOL_LOW	(0x00) 						/*SPIʱ�ӿ���ʱΪ��*/
#define		SPI_CLK_CPOL_HIGH	(0x01<< SPI_SPCR_CPOL_Pos)	/*SPIʱ�ӿ���ʱΪ��*/

/*----------------------------------------------------------------------------
 **SPI ʱ����λ
/*---------------------------------------------------------------------------*/
#define		SPI_CLK_CPHA_0		(0x00)						/*SPI�ȷ������ٷ�ʱ�ӣ�����ʱ��ż���ز���*/
#define		SPI_CLK_CPHA_1		(0x01<< SPI_SPCR_CPHA_Pos)	/*SPI�ȷ�ʱ���ٷ����ݣ�����ʱ�������ز���*/
/*----------------------------------------------------------------------------
 **SPI ����ģʽNSSxƬѡ�ź�
 ** ע����SPI_NSS_AUTO_CONTROL�Զ�����ģʽ�У�дSPIBuffer�ͻ��Զ�����Ƭѡ(SSCR�е�����)+���ݣ���������1Byte���ݺ�SPI���Զ�����NSSx
/*---------------------------------------------------------------------------*/
#define		SPI_NSS_SSCR_CONTROL		(0x0)			/*NSSxһֱ����Ĵ���SSCR������*/
#define		SPI_NSS_AUTO_CONTROL		(0x01)			/*SPI����ʱNSSx����ߵ�ƽ��SPI����ʱ���SSCR������*/

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
 ** \brief	SPI_Start
 **			����SPIģ��
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_Start(void);
/*****************************************************************************
 ** \brief	SPI_Stop
 **			�ر�SPIģ��
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_Stop(void);
/*****************************************************************************
 ** \brief	SPI_ConfigClk
 **			����SPI����ʱ��
 ** \param [in] SPIClkDiv�� (1)SPI_CLK_DIV_4 ~ SPI_CLK_DIV_512
 ** \return  none
 ** \note	 Fspi = Fsys / SPIClkDiv;
*****************************************************************************/
void SPI_ConfigClk(uint8_t SPIClkDiv);
/*****************************************************************************
 ** \brief	SPI_ConfigRunMode
 **			����SPI����ģʽ
 ** \param [in] ClkPositive: ʱ�Ӽ���
 **							 (1)SPI_CLK_CPOL_LOW      ��SPIʱ�ӿ���ʱΪ��
 **							 (2)SPI_CLK_CPOL_HIGH	  ��SPIʱ�ӿ���ʱΪ��
 **				ClkPhash: ʱ����λ
 **							  (1)SPI_CLK_CPHA_0 SPI�ȷ������ٷ�ʱ�ӣ�����ʱ��ż���ز���
 **							  (2)SPI_CLK_CPHA_1:�SSPI�ȷ�ʱ���ٷ����ݣ�����ʱ�������ز���
 **				NSSMode: NSS�ſ���ѡ��(ֻ��������ģʽ)
 **							  (1)SPI_NSS_SSCR_CONTROL:NSSxһֱ����Ĵ���SSCR������
 **							  (2)SPI_NSS_AUTO_CONTROL:SPI����ʱNSSx����ߵ�ƽ��SPI����ʱ���SSCR������
 ** \return  none
 ** \note	
*****************************************************************************/
void SPI_ConfigRunMode(uint8_t ClkPositive, uint8_t ClkPhash, uint8_t NSSMode);

/*****************************************************************************
 ** \brief	SPI_EnableMasterMode
 **			ʹ������ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableMasterMode(void);
/*****************************************************************************
 ** \brief	SPI_DisableMasterMode
 **			�ر�����ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableMasterMode(void);
/*****************************************************************************
 ** \brief	SPI_EnableSlaveMode
 **			ʹ�ܴӻ�ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableSlaveMode(void);
/*****************************************************************************
 ** \brief	SPI_DisableSlaveMode
 **			�رմӻ�ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableSlaveMode(void);

/*****************************************************************************
 ** \brief	SPI_GetTransferIntFlag
 **			��ȡ��������жϱ�־λ
 ** \param [in] none
 ** \return  1:SPI�������  0:SPIδ�������
 ** \note	 
*****************************************************************************/
uint8_t SPI_GetTransferIntFlag(void);
/*****************************************************************************
 ** \brief	SPI_ClearTransferIntFlag
 **			�����������жϱ�־λ
 ** \param [in] none
 ** \return  note
 ** \note	 
*****************************************************************************/
void SPI_ClearTransferIntFlag(void);
/*****************************************************************************
 ** \brief	SPI_GetWriteErrorIntFlag
 **			��ȡд��ͻ�жϱ�־λ
 ** \param [in] none
 ** \return  1:SPI����д��ͻ  0:SPI��д��ͻ
 ** \note	 
*****************************************************************************/
uint8_t SPI_GetWriteErrorIntFlag(void);
/*****************************************************************************
 ** \brief	SPI_ClearWriteErrorIntFlag
 **			���д��ͻ�жϱ�־λ
 ** \param [in] none
 ** \return none
 ** \note	 
*****************************************************************************/
void SPI_ClearWriteErrorIntFlag(void);
/*****************************************************************************
 ** \brief	SPI_EnableIntFlag
 **			����SPI�ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableIntFlag(void);
/*****************************************************************************
 ** \brief	SPI_DisableIntFlag
 **			�ر�SPI�ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableIntFlag(void);




#endif /* __SPI_H__ */