#ifndef __BREATHING_LAMP_H__
#define __BREATHING_LAMP_H__

#include "../User/All_include.h"

/****************[设置占空比]****************/
#define D0 0x00
#define D25 0x4B0
#define D50 0x960
#define D75 0xE10

/*******************************************/

/****************[API]****************/
// EPWM初始化
void EPWM_Config(void);

// 设置IO口的复用
void IO_Config(void);

// 开启呼吸灯
void Lamp_Run(void);
/*************************************/

#endif