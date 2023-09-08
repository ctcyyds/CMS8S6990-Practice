#ifndef __BREATHING_LAMP_H__
#define __BREATHING_LAMP_H__

#include "../User/All_include.h"

/****************[����ռ�ձ�]****************/
#define D0 0x00
#define D25 0x4B0
#define D50 0x960
#define D75 0xE10

/*******************************************/

/****************[API]****************/
// EPWM��ʼ��
void EPWM_Config(void);

// ����IO�ڵĸ���
void IO_Config(void);

// ����������
void Lamp_Run(void);
/*************************************/

#endif