#include "../User/All_include.h"

/****************[Timer Config]****************/
/**
 * @brief 初始化Timer
 */
void Timer_Config(void)
{
    // 设置Timer运行模式
    TMR_ConfigRunMode(TMR1, TMR_MODE_TIMING, TMR_TIM_16BIT);
    // 设置Timer运行时钟
    TMR_ConfigTimerClk(TMR1, TMR_CLK_DIV_12); /*Fsys = 24MHZ, Ftimer = 24MHZ, Ttmr = 0.5us*/
    // 设置Timer周期
    TMR_ConfigTimerPeriod(TMR1, (65536 - 200) >> 8, 65536 - 200);

    // 开启中断
    TMR_EnableOverflowInt(TMR1);
    // 设置Timer中断优先级
    IRQ_SET_PRIORITY(IRQ_TMR1, IRQ_PRIORITY_LOW);
    // 使能总中断
    IRQ_ALL_ENABLE();
    // 开启Timer
    TMR_Start(TMR1);
}
/**********************************/