#include "main.h"
#include "LED.h"

void led(LED_mode)
{
    if (LED_mode == 1) // 模式1，彩灯一亮一灭，处于正常情况下，无任何检测
    {
        LED_R_ENABLE();
        HAL_Delay(1000);
        LED_R_DISABLE();
        LED_G_ENABLE();
        HAL_Delay(1000);
        LED_G_DISABLE();
        LED_B_ENABLE();
        HAL_Delay(1000);
    }
    else if (LED_mode == 2) // 模式2，彩灯两亮两灭（混合色），检测到手但未触发报警
    {
        //黄色
        LED_R_ENABLE();
        LED_G_ENABLE();
        HAL_Delay(500);
        //紫色
        LED_G_DISABLE();
        LED_B_ENABLE();
        HAL_Delay(500);
        //青色
        LED_R_DISABLE();
        LED_G_ENABLE();
        HAL_Delay(500);
    }
    else if (LED_mode == 3) // 模式3，逐次点亮，然后逐次熄灭，按钮按下后手动停止电机
    {
        LED_R_ENABLE();
        HAL_Delay(300);
        LED_G_ENABLE();
        HAL_Delay(300);
        LED_B_ENABLE();
        HAL_Delay(500);
        LED_R_DISABLE();
        HAL_Delay(300);
        LED_G_DISABLE();
        HAL_Delay(300);
        LED_B_DISABLE();
        HAL_Delay(500);
    }
    else if (LED_mode == 4) //模式4，检测到手并且旋转电机停止中
    {
        LED_R_ENABLE();
        HAL_Delay(1000);
    }
    
}