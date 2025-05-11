/*
 * ws2812.h
 *
 *  Created on: May 6, 2021
 *      Author: song'yu'long
 */

#ifndef INC_WS2812_H_
#define INC_WS2812_H_
#include <stdio.h>

#define COLOR_BLACK		(0x000000)
#define COLOR_WHITE		(0xffffff)
#define COLOR_RED		(0xff0000)
#define COLOR_GREEN		(0x00ff00)
#define COLOR_YELLOW	(0x0000ff)


void ws2812_onepixel(unsigned int color);
void ws2812_oneframe(void);

void ws2812_waterflow(void);
#endif /* INC_WS2812_H_ */
