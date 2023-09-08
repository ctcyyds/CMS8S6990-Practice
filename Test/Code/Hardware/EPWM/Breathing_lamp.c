#include "../User/All_include.h"

/****************[EPWM初始化]****************/
void EPWM_Config(void)
{
    // 设置EPWM运行模式
    EPWM_ConfigRunMode(EPWM_WFG_COMPLEMENTARY | EPWM_OC_INDEPENDENT | EPWM_OCU_SYMMETRIC | EPWM_COUNT_DOWN);

    // 设置EPWM运行时钟
    EPWM_ConfigChannelClk(EPWM0, EPWM_CLK_DIV_1);
    EPWM_ConfigChannelClk(EPWM2, EPWM_CLK_DIV_1);
    EPWM_ConfigChannelClk(EPWM4, EPWM_CLK_DIV_1);

    // 设置EPWM周期
    EPWM_ConfigChannelPeriod(EPWM0, 0x12c0);
    EPWM_ConfigChannelPeriod(EPWM2, 0x12c0);
    EPWM_ConfigChannelPeriod(EPWM4, 0x12c0);

    // 设置EPWM占空比
    EPWM_ConfigChannelSymDuty(EPWM0, D50);
    EPWM_ConfigChannelSymDuty(EPWM2, D50);
    EPWM_ConfigChannelSymDuty(EPWM4, D50);

    // 设置EPWM的加载方式（自动加载）
    EPWM_EnableAutoLoadMode(EPWM_CH_4_MSK | EPWM_CH_2_MSK | EPWM_CH_0_MSK);

    // 设置EPWM的输出极性
    EPWM_DisableReverseOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK);

    // 设置EPWM输出
    EPWM_EnableOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK);

    // 设置EPWM死区
    EPWM_DisableDeadZone(EPWM0);
    EPWM_DisableDeadZone(EPWM2);
    EPWM_DisableDeadZone(EPWM4);

    // 开启EPWM零点中断
    EPWM_EnableZeroInt(EPWM_CH_0_MSK);
    // 开启EPWM总中断
    EPWM_AllIntEnable();
    // 设置中断优先级
    IRQ_SET_PRIORITY(IRQ_PWM, IRQ_PRIORITY_HIGH);
    // 开启总中断
    IRQ_ALL_ENABLE();

    // 开启EPWM
    EPWM_Start(EPWM_CH_4_MSK | EPWM_CH_2_MSK | EPWM_CH_0_MSK);
}
/*******************************************/

/****************[设置IO口的复用]****************/
void IO_Config(void)
{
    // 设置EPWM输出IO复用
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_PG0);
    GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_PG2);
    GPIO_SET_MUX_MODE(P14CFG, GPIO_MUX_PG4);
    GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_PG1);
    GPIO_SET_MUX_MODE(P16CFG, GPIO_MUX_PG3);
    GPIO_SET_MUX_MODE(P17CFG, GPIO_MUX_PG5);
}
/**********************************************/

/****************[开启呼吸灯]****************/
void Lamp_Run(void)
{
    EPWM_Config();
    IO_Config();
}
/*******************************************/