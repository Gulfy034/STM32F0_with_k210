#ifndef SNED_H
#define SEND_H

#include "main.h"

uint8_t send_buffer[8]; // 主机发送的数据为8，可以视情况修改

int send(send_buffer); // 需要在参数里输入1个8位16进制数，例如：00

#endif