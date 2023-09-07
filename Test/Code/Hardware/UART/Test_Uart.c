#include "../User/All_include.h"

/****************[UART Config]****************/
/**
 * @brief UART初始化
 *
 * @param UARTChose UART端口选择UART0 UART1
 */
void UART_Config(uint8_t UARTChose)
{
#if BRT_UART
    /*使用BRT作为UART模块的波特率时钟发生器*/
    uint16_t BRTValue = 0;
    uint32_t BaudRateVlue = 9600;

    // 设置UART0的运行模式
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_BRT);
    // 开启接收模式
    UART_EnableReceive(UARTChose);

    // 配置UART0的波特率
    UART_ConfigBRTClk(BRT_CLK_DIV_1);
    // 使能UART波特率倍频模式
    UART_EnableDoubleFrequency(UARTChose);

    // 使用公式计算定时器的加载值（需要对Systemclock赋值）
#ifdef USE_FORMULA
    BRTValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    BRTValue = 65380; // 对应的系统时钟：24MHZ
#endif

    // 配置BRT模块时钟周期（配置重装值）
    UART_ConfigBRTPeriod(BRTValue);
    // 使能BRT时钟模块（使能定时器）
    UART_EnableBRT();

    // 配置IO口
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR1_UART
    /*使用Timer1作为UART模块的波特率时钟发生器*/
    uint8_t THxValue = 0;
    uint32_t BaudRateVlue = 9600;

    // 设置UART0的运行模式
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR1);
    // 开启接收模式
    UART_EnableReceive(UARTChose);

    // 配置UART0的波特率
    TMR_ConfigTimerClk(TMR1, TMR_CLK_DIV_4);
    // 配置Timer运行模式
    TMR_ConfigRunMode(TMR1, TMR_MODE_TIMING, TMR_TIM_AUTO_8BIT);
    // 使能UART波特率倍频模式
    UART_EnableDoubleFrequency(UARTChose);

    // 使用公式计算定时器的加载值
#ifdef USE_FORMULA
    THxValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    THxValue = 217;
#endif

    // 配置Timer模块时钟周期（配置重装值）
    TMR_ConfigTimerPeriod(TMR1, THxValue, THxValue);
    // 使能Timer模块（使能Timer定时器）
    TMR_Start(TMR1);

    // 配置IO口
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR2_UART
    /*使用Timer2作为UART模块的波特率时钟发生器*/
    uint16_t TMR2Value = 0;
    uint32_t BaudRateVlue = 9600;

    // 设置UART0的运行模式
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR2);
    // 开启接收模式
    UART_EnableReceive(UARTChose);

    // 配置UART0的波特率
    TMR2_ConfigTimerClk(TMR2_CLK_DIV_12); // T2PS = 0
    // 配置Timer运行模式
    TMR2_ConfigRunMode(TMR2_MODE_TIMING, TMR2_AUTO_LOAD);
    // 使能UART波特率倍频模式
    UART_EnableDoubleFrequency(UARTChose);

    // 使用公式计算定时器的加载值
#ifdef USE_FORMULA
    TMR2Value = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    TMR2Value = 65523;
#endif

    // 配置Timer模块时钟周期（配置重装值）
    TMR2_ConfigTimerPeriod(TMR2Value);
    // 使能Timer模块（使能Timer定时器）
    TMR2_Start();

    // 配置IO口
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#elif TMR4_UART
    /*使用Timer4作为UART模块的波特率时钟发生器*/
    uint8_t THxValue = 0;
    uint32_t BaudRateVlue = 9600;

    // 设置UART0运行模式
    UART_ConfigRunMode(UARTChose, UART_MOD_ASY_8BIT, UART_BAUD_TMR4);
    // 开启接收模式
    UART_EnableReceive(UARTChose);

    // 配置UART0的波特率
    TMR_ConfigTimerClk(TMR4, TMR_CLK_DIV_4);
    // 配置Timer运行模式
    TMR_ConfigRunMode(TMR4, TMR_MODE_TIMING, TMR_TIM_AUTO_8BIT); // 设置为8位重装模式
    // 使能UART波特率倍频模式
    UART_EnableDoubleFrequency(UARTChose);

    // 使用公式计算定时器的加载值
#ifdef USE_FORMULA
    THxValue = UART_ConfigBaudRate(UARTChose, BaudRateVlue);
#else
    THxValue = 217;
#endif

    // 配置Timer模块时钟周期（配置重装值）
    TMR_ConfigTimerPeriod(TMR4, THxValue, THxValue);
    // 使能Timer模块（使能Timer定时器）
    TMR_Start(TMR4);

    // 配置IO口
    GPIO_SET_MUX_MODE(P23CFG, GPIO_MUX_TXD0);
    GPIO_SET_MUX_MODE(P22CFG, GPIO_MUX_RXD0);

#endif
}
/**********************************/

/****************[设置UART中断]****************/
/**
 * @brief 设置串口中断（使用printf()的时候不建议开启中断）
 *
 * @param UARTChose UART端口选择UART0 UART1
 * @param IRQPN     中断优先级模块编号en_Priority_Module
 */
void UART_ISR_Config(uint8_t UARTChose, uint8_t IRQPN)
{
    // 开启中断
    UART_EnableInt(UARTChose);
    // 设置中断优先级
    IRQ_SET_PRIORITY(IRQPN, IRQ_PRIORITY_LOW);
    // 使能总中断
    IRQ_ALL_ENABLE();
}
/**********************************/

/**
 * @brief 通过UART发送单个字符
 *
 * @param ch 发送的单个字符
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
 * @brief 发送的字符
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