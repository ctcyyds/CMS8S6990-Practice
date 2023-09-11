#include "../User/All_include.h"

/****************[ADC Init]****************/
/**
 * @brief ADC的基本配置
 */
void ADC_Config(void)
{

    // 设置ADC的运行模式（设置ADC时钟为系统的16分频，左对齐）
    ADC_ConfigRunMode(ADC_CLK_DIV_16, ADC_RESULT_LEFT);

    // 使能ADC转换通道
    ADC_EnableChannel(ADC_CH_0);
    // 设置IO口的复用功能
    GPIO_SET_MUX_MODE(P00CFG, GPIO_P00_MUX_AN0);

    // 使能ADC的LDO
    ADC_EnableLDO();
    // 配置ADC的VREF
    ADC_ConfigADCVref(ADC_VREF_3V);

    // 使能硬件触发ADC
    ADC_EnableHardwareTrig();
    // 配置硬件触发模式
    ADC_ConfigHardwareTrig(ADC_TG_ADET, ADC_TG_FALLING); // ADET的下降沿触发

    // 设置IO口的复用功能
    GPIO_SET_MUX_MODE(P25CFG, GPIO_MUX_GPIO);
    // GPIO上拉功能开启
    GPIO_ENABLE_UP(P2UP, GPIO_PIN_5); // 设置P25为上拉
    // 设置端口输入功能分配
    GPIO_SET_PS_MODE(PS_ADET, GPIO_P25); // 设置P25为ADET功能
    printf("%d\r\n", ADC_GetADCResult());

    // 使能ADC中断
    ADC_EnableInt();
    // 设置中断优先级
    IRQ_SET_PRIORITY(IRQ_ADC, IRQ_PRIORITY_HIGH);
    // 使能总中断
    IRQ_ALL_ENABLE();

    // 开启ADC
    ADC_Start();
}
/*****************************************/