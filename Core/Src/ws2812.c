/**
  * @file ws2812.c
  *
  *  Created on: 2020-04-17
  *      Author: wuliZhao_ch
  *       brief: WS2812 Drive
  */

#include "ws2812.h"


uint16_t MY_WS2812_RGB_BUFF[MY_WS2812_RET_NUM + MY_WS2812_MAX_NUM * 24] = {0};



/** 
  * @brief  Sets the color of a one light
  * @param  num   Select a one light
  * @param  red   Red intensity
  * @param  green Green intensity
  * @param  blue  Blue intensity
  * @retval None
  */
void MY_WS2812_Set(uint16_t num, uint8_t red, uint8_t green, uint8_t blue)
{
    uint32_t indexx = MY_WS2812_RET_NUM + (num * 24);
    for (uint8_t i = 0; i < 8; i++)
    {
        MY_WS2812_RGB_BUFF[i + indexx]      = (green << i) & 0x80 ? MY_WS2812_SET:MY_WS2812_RESET;
        MY_WS2812_RGB_BUFF[i + 8 + indexx]  = (red   << i) & 0x80 ? MY_WS2812_SET:MY_WS2812_RESET;
        MY_WS2812_RGB_BUFF[i + 16 + indexx] = (blue  << i) & 0x80 ? MY_WS2812_SET:MY_WS2812_RESET;
    }

}


/** 
  * @brief  Turn off all lights
  * @retval None
  */
void MY_WS2812_Set_All_OFF(void)
{
     
    for(uint16_t i=0;i<MY_WS2812_MAX_NUM;i++)
    {
       MY_WS2812_Set(i,0,0,0);
    }
}

/** 
  * @brief  Turn on all the lights
  * @retval None
  */
void MY_WS2812_Set_All_ON(void)
{
     
    for(uint16_t i=0;i<MY_WS2812_MAX_NUM;i++)
    {
       MY_WS2812_Set(i,255,255,255);
    }
}

/** 
  * @brief  WS2812 Init
  * @retval None
  */
void MY_WS2812_Iint(void)
{
    MY_WS2812_Set_All_OFF ();

    HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_4, (uint32_t *)MY_WS2812_RGB_BUFF, sizeof(MY_WS2812_RGB_BUFF)/sizeof(uint16_t));
}

