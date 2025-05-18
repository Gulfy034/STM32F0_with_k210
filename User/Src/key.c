#include "main.h"
#include "gpio.h"
#include "key.h"

void key_isPressed(pressed)
{
    //此处需要按住才能够实现
    pressed = KEY1_read_Stat();
    return pressed;
}