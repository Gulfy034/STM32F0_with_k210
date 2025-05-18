#ifndef LED_H
#define LED_H

#include "main.h"

void led(LED_mode);

uint8_t LED_mode;

#define LED_R_ENABLE() HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET);
#define LED_R_DISABLE() HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET);
#define LED_G_ENABLE() HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
#define LED_G_DISABLE() HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET);
#define LED_B_ENABLE() HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
#define LED_B_DISABLE() HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);


#define LED_CLK_ENABLE() __GPIOB_CLK_ENABLE();

#endif