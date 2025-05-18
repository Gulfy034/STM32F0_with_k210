# STM32F0_with_k210
stm32f030c8t6 with kendryte-K210, LED and a GY614V3 temperature sensor.

as a master device and work with [STM32F4_with_MLX90640 project](https://github.com/Gulfy034/STM32F4_with_MLX90640).

> [!TIP]
> cmake and [STM32CubeCLT](https://www.st.com.cn/en/development-tools/stm32cubeclt.html) (version >= 6.14.1) needed.
>
> use [STM32CubeMX](https://www.st.com.cn/zh/development-tools/stm32cubemx.html) to open *.ioc project, and use the latest [STM32F0 MCU package](https://www.st.com.cn/zh/embedded-software/stm32cubef0.html#get-software) if you want.
> 
> this is not for Keil MDK project.

## Description

```
Kendryte-K210 => USART1 --> PA9:TX PA10:RX

LED_HW-478(RGB) => GPIO --> PB0:R PB1:G PB2:B

GY614V3 the temperature sensor => USART2 --> PA2:TX PA3:RX

slave board => SPI --> PA5:SCK, PA6:MISO, PA7:MOSI

```

## Gragh

```
board <-(detected data)- [k210 & GY614Y3]
  |  \
(DATA)\
  |    \-(RGB works)-> LED_HW-478
  V
(slave board) --> Do something.

```

## TODO:

- [ ] Speaker PWM code
- [ ] GY614V3 code
- [ ] master <--> slave boards code & test