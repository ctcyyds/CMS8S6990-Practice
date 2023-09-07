#include "../User/All_include.h"

/****************[GPIO INIT]****************/
/**
 * @brief LED引脚初始化配置
 *
 * LED_L    P04
 * LED_R    P05
 */
void GPIO_Config(void)
{
    // 设置P04 P05为GPIO模式
    GPIO_SET_MUX_MODE(P04CFG, GPIO_MUX_GPIO);
    GPIO_SET_MUX_MODE(P05CFG, GPIO_MUX_GPIO);

    // 设置输入输出模式
    GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_4);
    GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_5);
}
/******************************************/

/****************[LED Run]****************/
/**
 * @brief LED亮灭逻辑
 * 0亮1灭
 */
void LED_Run(void)
{
    // LED引脚初始化配置
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