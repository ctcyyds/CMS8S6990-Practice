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
/** \file spi.c
**
** 
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "spi.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/
/*****************************************************************************
 ** \brief	SPI_Start
 **			����SPIģ��
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_Start(void)
{
	SPCR |= SPI_SPCR_SPEN_Msk;
}
/*****************************************************************************
 ** \brief	SPI_Stop
 **			�ر�SPIģ��
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_Stop(void)
{
	SPCR &= ~(SPI_SPCR_SPEN_Msk);
}
/*****************************************************************************
 ** \brief	SPI_ConfigClk
 **			����SPI����ʱ��
 ** \param [in] SPIClkDiv�� (1)SPI_CLK_DIV_4 ~ SPI_CLK_DIV_512
 ** \return  none
 ** \note	 Fspi = Fsys / SPIClkDiv;
*****************************************************************************/
void SPI_ConfigClk(uint8_t SPIClkDiv)
{
	uint8_t Temp=0;
	
	Temp = SPCR;
	Temp &= ~(SPI_SPCR_SPR2_Msk | SPI_SPCR_SPRn_Msk);
	Temp |= SPIClkDiv;
	SPCR = Temp;
}
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
void SPI_ConfigRunMode(uint8_t ClkPositive, uint8_t ClkPhash, uint8_t NSSMode)
{
	uint8_t Temp=0;
	
	Temp = SPCR;
	Temp &= ~(SPI_SPCR_CPOL_Msk | SPI_SPCR_CPHA_Msk);
	Temp |= (ClkPositive | ClkPhash);
	SPCR = Temp;
	
	Temp = SPSR;
	Temp &= ~(SPI_SPSR_SSCEN_Msk);
	Temp |= NSSMode;
	SPSR = Temp;	
}

/*****************************************************************************
 ** \brief	SPI_EnableMasterMode
 **			ʹ������ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableMasterMode(void)
{
	SPCR |= (SPI_SPCR_MSTR_Msk);
}
/*****************************************************************************
 ** \brief	SPI_DisableMasterMode
 **			�ر�����ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableMasterMode(void)
{
	SPCR &= ~(SPI_SPCR_MSTR_Msk);
}
/*****************************************************************************
 ** \brief	SPI_EnableSlaveMode
 **			ʹ�ܴӻ�ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableSlaveMode(void)
{
	SPCR &= ~(SPI_SPCR_MSTR_Msk);

}
/*****************************************************************************
 ** \brief	SPI_DisableSlaveMode
 **			�رմӻ�ģʽ
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableSlaveMode(void)
{
	SPCR |= (SPI_SPCR_MSTR_Msk);	
}


/*****************************************************************************
 ** \brief	SPI_GetTransferIntFlag
 **			��ȡ��������жϱ�־λ
 ** \param [in] none
 ** \return  1:SPI�������  0:SPIδ�������
 ** \note	 
*****************************************************************************/
uint8_t SPI_GetTransferIntFlag(void)

{
	return ((SPSR & SPI_SPSR_SPISIF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	SPI_ClearTransferIntFlag
 **			�����������жϱ�־λ
 ** \param [in] none
 ** \return  note
 ** \note	 
*****************************************************************************/
void SPI_ClearTransferIntFlag(void)
{
	uint8_t temp;
	temp = SPSR;
	temp = SPDR;
}
/*****************************************************************************
 ** \brief	SPI_GetWriteErrorIntFlag
 **			��ȡд��ͻ�жϱ�־λ
 ** \param [in] none
 ** \return  1:SPI����д��ͻ  0:SPI��д��ͻ
 ** \note	 
*****************************************************************************/
uint8_t SPI_GetWriteErrorIntFlag(void)
{
	return ((SPSR & SPI_SPSR_WCOL_Msk)? 1:0);	
}
/*****************************************************************************
 ** \brief	SPI_ClearWriteErrorIntFlag
 **			���д��ͻ�жϱ�־λ
 ** \param [in] none
 ** \return none
 ** \note	 
*****************************************************************************/
void SPI_ClearWriteErrorIntFlag(void)
{
	uint8_t temp;
	temp = SPSR;
	temp = SPDR;
}
/*****************************************************************************
 ** \brief	SPI_EnableIntFlag
 **			����SPI�ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_EnableIntFlag(void)
{
	EIE2 |= IRQ_EIE2_SPIIE_Msk;
}
/*****************************************************************************
 ** \brief	SPI_DisableIntFlag
 **			�ر�SPI�ж�
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SPI_DisableIntFlag(void)
{
	EIE2 &= ~(IRQ_EIE2_SPIIE_Msk);	
}







