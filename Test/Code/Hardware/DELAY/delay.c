#include "../User/All_include.h"

#if 0
void delay(unsigned int ms)
{
    unsigned int i;
    TH0 = 0x00;
    TL0 = 0x00;
    TMOD = 0x01;
    TR0 = 1;

    for (i = 0; i < ms; i++)
    {
        while (!TF0)
        {
            TF0 = 0;
            TH0 = 0xFC;
            TL0 = 0x38;
        }
        TR0 = 0;
    }
}
#else
/**
 * @brief 使用Timer0的延时函数
 * TH0  Timer0数据寄存器高位
 * TL0  Timer0数据寄存器低位
 * TR0  Timer0运行控制位（1启动 0关闭）
 * TF0  Timer0计数器溢出中断标志位（
 * 1 Timer0计数器溢出，进入中断服务程序时硬件自动清零，也可软件清零
 * 0 Timer0计数器无溢出
 * ）
 *
 * @param ms
 */
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
    {
        for (j = 0; j < 37; j++)
        {
            TH0 = 0xFC;
            TL0 = 0x18;
            TR0 = 1;
            while (!TF0)
                ;
            TR0 = 0;
            TF0 = 0;
        }
    }
}
#endif