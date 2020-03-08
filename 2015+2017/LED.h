#ifndef  __LED_H
#define  __LED_H

#include "STC15Fxxxx.h"

#define ON     1
#define OFF    0

#define LED_PORT0  GPIO_P1

#define LED0_Pin GPIO_Pin_0
#define LED1_Pin GPIO_Pin_1
#define LED2_Pin GPIO_Pin_2
#define LED3_Pin GPIO_Pin_3
#define LED4_Pin GPIO_Pin_4
#define LED5_Pin GPIO_Pin_5
#define LED6_Pin GPIO_Pin_6
#define LED7_Pin GPIO_Pin_7

#define LED_NUM_MODE0   8  
#define LED_NUM_MODE1   8 
#define LED_NUM_MODE2   4
#define LED_NUM_MODE3   4 

void LED_On(u8 led_port,u8 led_pin);
void LED_Off(u8 led_port,u8 led_pin);
void LED_LeftToRight(u8 Pinx);
void LED_RightToLeft(u8 Pinx);
void LED_SideToCenter(u8 Pinx);	
void LED_CenterToSide(u8 Pinx);
void LED_Close();
void LED_Toggle(bit mode , u8 LED_GPIO , u8 Pinx);

#endif