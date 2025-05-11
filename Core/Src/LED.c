#include "main.h"
#include "ws2812.h"
#include "tim.h"

uint16_t ms_count10 = 0;
uint16_t ms_count500 = 0;
uint16_t ms_count1000 = 0;
uint32_t ws2812_color = 0x000000;

uint8_t LED_status1 = 0xFF;
uint8_t LED_status2 = 0xFF;
uint8_t LED_status4 = 0xFF;
uint8_t LED_mode = 1;
uint8_t LED_mode4_count = 0;
uint8_t LED_mode3_count = 0;
uint8_t LED_mode2_count = 0;

void LED(uint8_t pin);

void LED(uint8_t pin)
{
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (GPIO_PinState)(pin & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (GPIO_PinState)(pin & 0x02));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (GPIO_PinState)(pin & 0x04));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (GPIO_PinState)(pin & 0x08));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (GPIO_PinState)(pin & 0x10));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (GPIO_PinState)(pin & 0x20));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (GPIO_PinState)(pin & 0x40));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (GPIO_PinState)(pin & 0x80));
};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim3)
    {
        ms_count10++;
        ms_count500++;
        ms_count1000++;
    }
};

int led()
{
    if (ms_count500 >= 500) // 每隔500毫秒执行一次
    {
        if (LED_mode == 1) // 模式1，彩灯一亮一灭,从左向右移动
        {

            if (LED_status1 == 0xFF)
            {
                LED_status1 = LED_status1 >> 1;
            }
            else
            {
                LED_status1 = LED_status1 >> 1 | 0x80;
            }
            LED(LED_status1);
            if (LED_status1 == 0xFE)
            {
                LED_status1 = 0xFF;
                LED_mode = 2;
            }
        }
        else if (LED_mode == 2) // 模式2，彩灯两亮两灭，从左向右移动
        {

            if (LED_status2 == 0xFF)
            {
                LED_status2 = LED_status2 >> 2;
            }
            else
            {
                LED_status2 = LED_status2 >> 2 | 0xC0;
            }
            LED(LED_status2);
            LED_mode2_count++;
            if (LED_mode2_count == 5)
            {
                LED_status2 = 0xFF;
                LED_mode2_count = 0;
                LED_mode = 3;
            }
        }
        else if (LED_mode == 4) // 模式4，从1～8从左到右逐次点亮，然后逐次熄灭
        {

            if (LED_mode4_count <= 7)
            {
                LED_status4 = LED_status4 >> 1;
                LED(LED_status4);
                LED_mode4_count++;
            }
            else if (LED_mode4_count > 7 && LED_mode4_count < 16)
            {
                LED_status4 = LED_status4 >> 1 | 0x80;
                LED(LED_status4);
                LED_mode4_count++;
            }
            else if (LED_mode4_count == 16)
            {
                LED_mode4_count = 0;
                LED_mode = 1;
            }
        }
        ms_count500 = 0;
    }
    if (ms_count1000 >= 1000) // 每隔1秒执行一次
    {
        if (LED_mode == 3) // 模式3，四亮四灭，从左向右移动
        {

            if (LED_mode3_count == 0)
            {
                LED(0x0F);
            }
            else if (LED_mode3_count == 1)
            {
                LED(0xF0);
            }
            LED_mode3_count++;
            if (LED_mode3_count == 3)
            {
                LED_mode3_count = 0;
                LED_mode = 4;
            }
        }

        ms_count1000 = 0;
    }
}