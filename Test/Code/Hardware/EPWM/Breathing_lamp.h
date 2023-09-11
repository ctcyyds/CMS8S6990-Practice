#ifndef __BREATHING_LAMP_H__
#define __BREATHING_LAMP_H__

#include "../User/All_include.h"

/****************[����ռ�ձ�]****************/
#define D0 0x00     // Duty = %0
#define D25 0x4B0   // Duty = %25
#define D50 0x960   // Duty = 50%
#define D75 0xE10   // Duty = 75%
#define D100 0x12C0 // Duty = 100%
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