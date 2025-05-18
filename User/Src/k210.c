#include "main.h"
#include "usart.h"
#include "k210.h"

void recv_k210msg(uint8_t recv_msg);
void deal_recvmsg(void);
void deal_data(uint8_t egnum);

int k210_receive(k210_stat)
{
  //  读取k210状态，若是接收到k210有人手就表示 alert=1
  if (k210_msg.crc == 0x00 && k210_msg.alert == 0x01)
  {
    printf("当前k210检测到手: ", k210_msg.alert);
    USART1_Send_ArrayU8((uint8_t *)buff_com, strlen(buff_com));
    return k210_stat = 1; // 检测到人手
  }
  else
  {
    return k210_stat = 0; // 未检测到人手
  }
}