#include "../User/All_include.h"

/****************[ADC Init]****************/
/**
 * @brief ADC�Ļ�������
 */
void ADC_Config(void)
{

    // ����ADC������ģʽ������ADCʱ��Ϊϵͳ��16��Ƶ������룩
    ADC_ConfigRunMode(ADC_CLK_DIV_16, ADC_RESULT_LEFT);

    // ʹ��ADCת��ͨ��
    ADC_EnableChannel(ADC_CH_0);
    // ����IO�ڵĸ��ù���
    GPIO_SET_MUX_MODE(P00CFG, GPIO_P00_MUX_AN0);

    // ʹ��ADC��LDO
    ADC_EnableLDO();
    // ����ADC��VREF
    ADC_ConfigADCVref(ADC_VREF_3V);

    // ʹ��Ӳ������ADC
    ADC_EnableHardwareTrig();
    // ����Ӳ������ģʽ
    ADC_ConfigHardwareTrig(ADC_TG_ADET, ADC_TG_FALLING); // ADET���½��ش���

    // ����IO�ڵĸ��ù���
    GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);
    // GPIO�������ܿ���
    GPIO_ENABLE_UP(P2UP, GPIO_PIN_5); // ����P25Ϊ����
    // ���ö˿����빦�ܷ���
    GPIO_SET_PS_MODE(PS_ADET, GPIO_P25); // ����P25ΪADET����
    printf("%d\r\n", ADC_GetADCResult());

    // ʹ��ADC�ж�
    ADC_EnableInt();
    // �����ж����ȼ�
    IRQ_SET_PRIORITY(IRQ_ADC, IRQ_PRIORITY_HIGH);
    // ʹ�����ж�
    IRQ_ALL_ENABLE();

    // ����ADC
    ADC_Start();
}
/*****************************************/