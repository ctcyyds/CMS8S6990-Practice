#include "../User/All_include.h"

/****************[GPIO INIT]****************/
/**
 * @brief LED���ų�ʼ������
 *
 * LED_L    P04
 * LED_R    P05
 */
void GPIO_Config(void)
{
    // ����P04 P05ΪGPIOģʽ
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_GPIO);
    GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_GPIO);

    // �����������ģʽ
    GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_4);
    GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_5);
}
/******************************************/

/****************[LED Run]****************/
/**
 * @brief LED�����߼�
 * 0��1��
 */
void LED_Run(void)
{
    // LED���ų�ʼ������
    GPIO_Config();
    // printf("LED_L = %d\r\n", LED_L);
    // printf("LED_R = %d\r\n", LED_R);
    printf("Test!!!\r\n");
    while (1)
    {
        LED_L = 0;
        LED_R = 0;
        delay_ms(1000);
        LED_L = 1;
        LED_R = 1;
        delay_ms(1000);
    }
}
/**********************************/