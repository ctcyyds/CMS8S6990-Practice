#include "../User/All_include.h"

/****************[EPWM ��ʼ��]****************/
void EPWM_Config(void)
{
    // ����EPWM����ģʽ
    EPWM_ConfigRunMode(EPWM_WFG_COMPLEMENTARY | EPWM_OC_INDEPENDENT | EPWM_OCU_SYMMETRIC | EPWM_COUNT_UP_DOWN);
    // ����EPWM����ʱ��
    EPWM_ConfigChannelClk(EPWM0, EPWM_CLK_DIV_32);
    // ����EPWM����
    EPWM_ConfigChannelPeriod(EPWM0, 0xffff);
    // ����EPWMռ�ձ�
    EPWM_ConfigChannelSymDuty(EPWM0, 0x7960);
    // ����EPWM�ļ��ط�ʽΪ�Զ�����
    EPWM_EnableAutoLoadMode(EPWM_CH_0_MSK);
    // ����EPWM���������
    EPWM_DisableReverseOutput(EPWM_CH_0_MSK); // �رշ������
    // ����EPWM���
    EPWM_EnableOutput(EPWM_CH_0_MSK); // �������

    // ����EPWM����
    EPWM_DisableDeadZone(EPWM0);
    EPWM_DisableDeadZone(EPWM2);
    EPWM_DisableDeadZone(EPWM4);

    // EPWM�ж�
    EPWM_EnableZeroInt(EPWM_CH_0_MSK); // ����EPWM����ж�
    EPWM_AllIntEnable();               // ����EPWM���ж�

    // �����ж����ȼ�
    IRQ_SET_PRIORITY(IRQ_PWM, IRQ_PRIORITY_HIGH);
    // �������ж�
    IRQ_ALL_ENABLE();
    // ����EPWM���IO����
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_PG0);
    // ����EPWM
    EPWM_Start(EPWM_CH_0_MSK);
}
/**********************************/

/****************[�ⲿ�ж�����]****************/
void EXTINT_Config(void)
{
    EXTINT_ConfigInt(EXTINT0, EXTINT_TRIG_FALLING);
    GPIO_ENABLE_UP(P1UP, GPIO_PIN_3);
    GPIO_SET_PS_MODE(PS_INT0, GPIO_P13);
    EXTINT_EnableInt(EXTINT0);
    // �����ж����ȼ�
    IRQ_SET_PRIORITY(IRQ_EXINT0, IRQ_PRIORITY_HIGH);
    // ʹ�����ж�
    IRQ_ALL_ENABLE();
}
/**********************************/