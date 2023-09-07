#include "../User/All_include.h"

/****************[UART Config]****************/
/**
 * @brief UART��ʼ��
 *
 * @param UARTChose UART�˿�ѡ��UART0 UART1
 */
void UART_Config(uint8_t UARTChose)
{
#if BRT_UART
    /*ʹ��BRT��ΪUARTģ��Ĳ�����ʱ�ӷ�����*/
    uint16_t BRTValue = 0;
    uint32_t BaudRateVlue = 9600;

    // ����UART0������ģʽ
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_BRT);
    // ��������ģʽ
    UART_EnableReceive(UARTChose);

    // ����UART0�Ĳ�����
    UART_ConfigBRTClk(BRT_CLK_DIV_1);
    // ʹ��UART�����ʱ�Ƶģʽ
    UART_EnableDoubleFrequency(UARTChose);

    // ʹ�ù�ʽ���㶨ʱ���ļ���ֵ����Ҫ��Systemclock��ֵ��
#ifdef USE_FORMULA
    BRTValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    BRTValue = 65380; // ��Ӧ��ϵͳʱ�ӣ�24MHZ
#endif

    // ����BRTģ��ʱ�����ڣ�������װֵ��
    UART_ConfigBRTPeriod(BRTValue);
    // ʹ��BRTʱ��ģ�飨ʹ�ܶ�ʱ����
    UART_EnableBRT();

    // ����IO��
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR1_UART
    /*ʹ��Timer1��ΪUARTģ��Ĳ�����ʱ�ӷ�����*/
    uint8_t THxValue = 0;
    uint32_t BaudRateVlue = 9600;

    // ����UART0������ģʽ
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR1);
    // ��������ģʽ
    UART_EnableReceive(UARTChose);

    // ����UART0�Ĳ�����
    TMR_ConfigTimerClk(TMR1, TMR_CLK_DIV_4);
    // ����Timer����ģʽ
    TMR_ConfigRunMode(TMR1, TMR_MODE_TIMING, TMR_TIM_AUTO_8BIT);
    // ʹ��UART�����ʱ�Ƶģʽ
    UART_EnableDoubleFrequency(UARTChose);

    // ʹ�ù�ʽ���㶨ʱ���ļ���ֵ
#ifdef USE_FORMULA
    THxValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    THxValue = 217;
#endif

    // ����Timerģ��ʱ�����ڣ�������װֵ��
    TMR_ConfigTimerPeriod(TMR1, THxValue, THxValue);
    // ʹ��Timerģ�飨ʹ��Timer��ʱ����
    TMR_Start(TMR1);

    // ����IO��
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR2_UART
    /*ʹ��Timer2��ΪUARTģ��Ĳ�����ʱ�ӷ�����*/
    uint16_t TMR2Value = 0;
    uint32_t BaudRateVlue = 9600;

    // ����UART0������ģʽ
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR2);
    // ��������ģʽ
    UART_EnableReceive(UARTChose);

    // ����UART0�Ĳ�����
    TMR2_ConfigTimerClk(TMR2_CLK_DIV_12); // T2PS = 0
    // ����Timer����ģʽ
    TMR2_ConfigRunMode(TMR2_MODE_TIMING, TMR2_AUTO_LOAD);
    // ʹ��UART�����ʱ�Ƶģʽ
    UART_EnableDoubleFrequency(UARTChose);

    // ʹ�ù�ʽ���㶨ʱ���ļ���ֵ
#ifdef USE_FORMULA
    TMR2Value = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    TMR2Value = 65523;
#endif

    // ����Timerģ��ʱ�����ڣ�������װֵ��
    TMR2_ConfigTimerPeriod(TMR2Value);
    // ʹ��Timerģ�飨ʹ��Timer��ʱ����
    TMR2_Start();

    // ����IO��
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR4_UART
    /*ʹ��Timer4��ΪUARTģ��Ĳ�����ʱ�ӷ�����*/
    uint8_t THxValue = 0;
    uint32_t BaudRateVlue = 9600;

    // ����UART0����ģʽ
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR4);
    // ��������ģʽ
    UART_EnableReceive(UARTChose);

    // ����UART0�Ĳ�����
    TMR_ConfigTimerClk(TMR4, TMR_CLK_DIV_4);
    // ����Timer����ģʽ
    TMR_ConfigRunMode(TMR4, TMR_MODE_TIMING, TMR_TIM_AUTO_8BIT); // ����Ϊ8λ��װģʽ
    // ʹ��UART�����ʱ�Ƶģʽ
    UART_EnableDoubleFrequency(UARTChose);

    // ʹ�ù�ʽ���㶨ʱ���ļ���ֵ
#ifdef USE_FORMULA
    THxValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    THxValue = 217;
#endif

    // ����Timerģ��ʱ�����ڣ�������װֵ��
    TMR_ConfigTimerPeriod(TMR4, THxValue, THxValue);
    // ʹ��Timerģ�飨ʹ��Timer��ʱ����
    TMR_Start(TMR4);

    // ����IO��
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#endif
}
/**********************************/

/****************[����UART�ж�]****************/
/**
 * @brief ���ô����жϣ�ʹ��printf()��ʱ�򲻽��鿪���жϣ�
 *
 * @param UARTChose UART�˿�ѡ��UART0 UART1
 * @param IRQPN     �ж����ȼ�ģ����en_Priority_Module
 */
void UART_ISR_Config(uint8_t UARTChose, uint8_t IRQPN)
{
    // �����ж�
    UART_EnableInt(UARTChose);
    // �����ж����ȼ�
    IRQ_SET_PRIORITY(IRQPN, IRQ_PRIORITY_LOW);
    // ʹ�����ж�
    IRQ_ALL_ENABLE();
}
/**********************************/

/**
 * @brief ͨ��UART���͵����ַ�
 *
 * @param ch ���͵ĵ����ַ�
 * @return char
 */
char putchar(char ch)
{
    SBUF0 = ch;
    while (!(SCON0 & (1 << 1)))
        ;
    SCON0 &= ~(1 << 1);
    return 0;
}

/**
 * @brief ���͵��ַ�
 *
 * @return char
 */
char getchar(void)
{
    while (!(SCON0 & (1 << 0)))
        ;
    SCON0 &= ~(1 << 0);
    return SBUF0;
}

int puts(const char *s)
{
    while (*s)
    {
        putchar(*s);
        s++;
    }
    return 0;
}