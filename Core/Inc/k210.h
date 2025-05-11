#ifndef __k210_H__
#define __k210_H__

#include "main.h"

// 可以调整选的是 USART1 / USART2
#define USART1

// 定义k210信息结构体

typedef struct k210_msg
{
	uint16_t start;
	uint16_t alert; // 0x01: 检测到手警报, 0x00: 没检测到不警报
	uint16_t crc;
	uint16_t end;
} k210;

// 备注: start符号$: 0x24, end符号#: 0x23, crc: 0x01

/********k210通信相关************/
void recv_k210msg(uint8_t recv_msg);
void deal_recvmsg(void);
void deal_data(uint8_t egnum);
extern k210 k210_msg;

// k210信息结构体: k210_msg, 结构体变量名: k210
// 用的时候导入这个头文件：#include "k210.h"
// 也可以直接复制定义结构体的部分到主程序里
// 使用之前char buff_com[30]; 可以调整适当的大小
// 然后可以使用，例如：
/* if (k210.alert != 0):
	sprintf("当前k210检测到手: ", k210.alert);
	k210.light =0; //接收到信息结构体后可以手动修改一些值来复位状态，指的是脱离警告状态
	USART2_Send_ArrayU8((uint8_t*)buff_com,strlen(buff_com));
*/

#endif