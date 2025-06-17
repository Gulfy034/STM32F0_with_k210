#include "main.h"
#include "spi.h"
#include "send.h"

int send(send_buffer)
{
    SystemInit();
    HAL_SPI_Init(SPI1);
    if (SPI_CR1_BIDIMODE)
    {
        HAL_SPI_Transmit(SPI1, send_buffer, 8, HAL_MAX_DELAY); // 实现主机spi发送数据
    }
    else
    {
        // do noting
    }
}

// int debug(void)
// {
//     SystemInit();
//     while ()
//     {
//         // TODO: 此处为电脑串口发送调试数据的实现
//     }
// }