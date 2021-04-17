/**
  * @file ws2812.H
  *
  *  Created on: 2020-04-17
  *      Author: wuliZhao_ch
  *       brief: WS2812 Drive
  */
#ifndef __WS2812_H
#define __WS2812_H

#include "main.h"
#include "tim.h"

/* 灯珠的数量(目前60个) */
#define MY_WS2812_MAX_NUM   60

/* 复位脉冲 (Reset 大于 280us) 整个周期1.25us(0.8MHz=800KHz) 280us / 1.25us = 224 (这里我选择300脉冲) */
#define MY_WS2812_RET_NUM   300

/* 归零码 数据位 */
#define MY_WS2812_SET       59  // MY_WS2812_SET -> 1
#define MY_WS2812_RESET     29  // MY_WS2812_RESET -> 0


void MY_WS2812_Set(uint16_t num, uint8_t red, uint8_t green, uint8_t blue);     /* Sets the color of a one light */
void MY_WS2812_Set_All_OFF(void);       /* Turn off all lights    */
void MY_WS2812_Set_All_ON(void);        /* Turn on all the lights */
void MY_WS2812_Iint(void);              /* WS2812 Init            */




#endif



