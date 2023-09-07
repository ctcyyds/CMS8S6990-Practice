#include "../User/All_include.h"

/****************[Timer Config]****************/
/**
 * @brief ��ʼ��Timer
 */
void Timer_Config(void)
{
    // ����Timer����ģʽ
    TMR_ConfigRunMode(TMR1, TMR_MODE_TIMING, TMR_TIM_16BIT);
    // ����Timer����ʱ��
    TMR_ConfigTimerClk(TMR1, TMR_CLK_DIV_12); /*Fsys = 24MHZ, Ftimer = 24MHZ, Ttmr = 0.5us*/
    // ����Timer����
    TMR_ConfigTimerPeriod(TMR1, (65536 - 200) >> 8, 65536 - 200);

    // �����ж�
    TMR_EnableOverflowInt(TMR1);
    // ����Timer�ж����ȼ�
    IRQ_SET_PRIORITY(IRQ_TMR1, IRQ_PRIORITY_LOW);
    // ʹ�����ж�
    IRQ_ALL_ENABLE();
    // ����Timer
    TMR_Start(TMR1);
}
/**********************************/