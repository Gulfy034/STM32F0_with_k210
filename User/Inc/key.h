#ifndef KEY_H
#define KEY_H

#include "main.h"

#define KEY1_read_Stat() HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)

uint8_t pressed;// 按下key1为1，没按下为不为1（因为可能没有上拉电阻数值不可控，所以不确定为0）

#endif