#ifndef  __key_h
#define  __key_h

#include "config.h"
#include "GPIO.h"

#define KEY_P0  GPIO_P0
#define KEY_P1  GPIO_P1
#define KEY_P2  GPIO_P2
#define KEY_P3  GPIO_P3

#define KEY0  GPIO_Pin_0
#define KEY1  GPIO_Pin_1
#define KEY2  GPIO_Pin_2
#define KEY3  GPIO_Pin_3
#define KEY4  GPIO_Pin_4
#define KEY5  GPIO_Pin_5
#define KEY6  GPIO_Pin_6
#define KEY7  GPIO_Pin_7

bit key_detection(u8 GPIOx , u8 Pinx);

#endif