#include "../User/All_include.h"

/****************[EPWM 初始化]****************/
void EPWM_Config(void)
{
    // 设置EPWM运行模式
    EPWM_ConfigRunMode(EPWM_WFG_COMPLEMENTARY | EPWM_OC_INDEPENDENT | EPWM_OCU_SYMMETRIC | EPWM_COUNT_UP_DOWN);
    // 设置EPWM运行时钟
    EPWM_ConfigChannelClk(EPWM0, EPWM_CLK_DIV_32);
    // 设置EPWM周期
    EPWM_ConfigChannelPeriod(EPWM0, 0xffff);
    // 设置EPWM占空比
    EPWM_ConfigChannelSymDuty(EPWM0, 0x7960);
    // 设置EPWM的加载方式为自动加载
    EPWM_EnableAutoLoadMode(EPWM_CH_0_MSK);
    // 设置EPWM的输出极性
    EPWM_DisableReverseOutput(EPWM_CH_0_MSK); // 关闭反向输出
    // 设置EPWM输出
    EPWM_EnableOutput(EPWM_CH_0_MSK); // 开启输出

    // 设置EPWM死区
    EPWM_DisableDeadZone(EPWM0);
    EPWM_DisableDeadZone(EPWM2);
    EPWM_DisableDeadZone(EPWM4);

    // EPWM中断
    EPWM_EnableZeroInt(EPWM_CH_0_MSK); // 开启EPWM零点中断
    EPWM_AllIntEnable();               // 开启EPWM总中断

    // 设置中断优先级
    IRQ_SET_PRIORITY(IRQ_PWM, IRQ_PRIORITY_HIGH);
    // 开启总中断
    IRQ_ALL_ENABLE();
    // 设置EPWM输出IO复用
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_PG0);
    // 开启EPWM
    EPWM_Start(EPWM_CH_0_MSK);
}
/**********************************/

/****************[外部中端配置]****************/
void EXTINT_Config(void)
{
    EXTINT_ConfigInt(EXTINT0, EXTINT_TRIG_FALLING);
    GPIO_ENABLE_UP(P1UP, GPIO_PIN_3);
    GPIO_SET_PS_MODE(PS_INT0, GPIO_P13);
    EXTINT_EnableInt(EXTINT0);
    // 设置中断优先级
    IRQ_SET_PRIORITY(IRQ_EXINT0, IRQ_PRIORITY_HIGH);
    // 使能总中断
    IRQ_ALL_ENABLE();
}
/**********************************/