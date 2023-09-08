#include "../User/All_include.h"

/****************[EPWM��ʼ��]****************/
void EPWM_Config(void)
{
    // ����EPWM����ģʽ
    EPWM_ConfigRunMode(EPWM_WFG_COMPLEMENTARY | EPWM_OC_INDEPENDENT | EPWM_OCU_SYMMETRIC | EPWM_COUNT_DOWN);

    // ����EPWM����ʱ��
    EPWM_ConfigChannelClk(EPWM0, EPWM_CLK_DIV_1);
    EPWM_ConfigChannelClk(EPWM2, EPWM_CLK_DIV_1);
    EPWM_ConfigChannelClk(EPWM4, EPWM_CLK_DIV_1);

    // ����EPWM����
    EPWM_ConfigChannelPeriod(EPWM0, 0x12c0);
    EPWM_ConfigChannelPeriod(EPWM2, 0x12c0);
    EPWM_ConfigChannelPeriod(EPWM4, 0x12c0);

    // ����EPWMռ�ձ�
    EPWM_ConfigChannelSymDuty(EPWM0, D50);
    EPWM_ConfigChannelSymDuty(EPWM2, D50);
    EPWM_ConfigChannelSymDuty(EPWM4, D50);

    // ����EPWM�ļ��ط�ʽ���Զ����أ�
    EPWM_EnableAutoLoadMode(EPWM_CH_4_MSK | EPWM_CH_2_MSK | EPWM_CH_0_MSK);

    // ����EPWM���������
    EPWM_DisableReverseOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK);

    // ����EPWM���
    EPWM_EnableOutput(EPWM_CH_0_MSK | EPWM_CH_1_MSK | EPWM_CH_2_MSK | EPWM_CH_3_MSK | EPWM_CH_4_MSK | EPWM_CH_5_MSK);

    // ����EPWM����
    EPWM_DisableDeadZone(EPWM0);
    EPWM_DisableDeadZone(EPWM2);
    EPWM_DisableDeadZone(EPWM4);

    // ����EPWM����ж�
    EPWM_EnableZeroInt(EPWM_CH_0_MSK);
    // ����EPWM���ж�
    EPWM_AllIntEnable();
    // �����ж����ȼ�
    IRQ_SET_PRIORITY(IRQ_PWM, IRQ_PRIORITY_HIGH);
    // �������ж�
    IRQ_ALL_ENABLE();

    // ����EPWM
    EPWM_Start(EPWM_CH_4_MSK | EPWM_CH_2_MSK | EPWM_CH_0_MSK);
}
/*******************************************/

/****************[����IO�ڵĸ���]****************/
void IO_Config(void)
{
    // ����EPWM���IO����
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_PG0);
    GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_PG2);
    GPIO_SET_MUX_MODE(P14CFG, GPIO_MUX_PG4);
    GPIO_SET_MUX_MODE(P15CFG, GPIO_MUX_PG1);
    GPIO_SET_MUX_MODE(P16CFG, GPIO_MUX_PG3);
    GPIO_SET_MUX_MODE(P17CFG, GPIO_MUX_PG5);
}
/**********************************************/

/****************[����������]****************/
void Lamp_Run(void)
{
    EPWM_Config();
    IO_Config();
}
/*******************************************/