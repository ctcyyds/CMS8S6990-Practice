#ifndef __TEST_LED_H__
#define __TEST_LED_H__

#include "../User/All_include.h"

#define LED_L P04
#define LED_R P05

/****************[API]****************/
// GPIO��ʼ��
void GPIO_Config(void);

// ����LED
void LED_Run(void);
/**********************************/

#endif