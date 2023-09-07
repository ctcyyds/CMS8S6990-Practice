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
 * @brief ʹ��Timer0����ʱ����
 * TH0  Timer0���ݼĴ�����λ
 * TL0  Timer0���ݼĴ�����λ
 * TR0  Timer0���п���λ��1���� 0�رգ�
 * TF0  Timer0����������жϱ�־λ��
 * 1 Timer0����������������жϷ������ʱӲ���Զ����㣬Ҳ���������
 * 0 Timer0�����������
 * ��
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