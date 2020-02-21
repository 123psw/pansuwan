#include "LED.h"
#include "GPIO.h"

u8 LED[] = {LED0_Pin,LED1_Pin,LED2_Pin,LED3_Pin,LED4_Pin,LED5_Pin,LED6_Pin,LED7_Pin};

void LED_On(u8 led_port,u8 led_pin )
{
  GPIO_WritePin(led_port ,led_pin , LOW);
}

void LED_Off(u8 led_port,u8 led_pin)
{
  GPIO_WritePin(led_port ,led_pin , HIGH);
}

void LED_Close()
{
	GPIO_WritePin(LED_PORT0 , GPIO_Pin_All , HIGH);
}

void LED_LeftToRight(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
    LED_On(LED_PORT0, LED[Pinx]);  
  }
  else if (Pinx >= LED_NUM_MODE0) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮右边的LED，再熄灭左边的
  {   
    LED_On(LED_PORT0, LED[Pinx]);
    Pinx--;
    LED_Off(LED_PORT0, LED[Pinx]);    
  }
}

void LED_RightToLeft(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
    LED_On(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);  
  }
  else if (Pinx >= LED_NUM_MODE1) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);
    Pinx--;
    LED_Off(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);    
  }
}

void LED_SideToCenter(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);  
  }
  else if (Pinx >= LED_NUM_MODE2) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[Pinx]);
    LED_Off(LED_PORT0, LED[LED_NUM_MODE1 - 1 - Pinx]);  
  }
}

void LED_CenterToSide(u8 Pinx)
{
  
  if (Pinx == 0) 
  {
		LED_On(LED_PORT0, LED[LED_NUM_MODE3 - 1 -  Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_MODE3 + Pinx]);  
  }
  else if (Pinx >= LED_NUM_MODE3) //熄灭所有LED
  {
    LED_Close();
  }
  else //先点亮左的LED，再熄灭右边的
  {   
    LED_On(LED_PORT0, LED[LED_NUM_MODE3 - 1 -  Pinx]); 
    LED_On(LED_PORT0, LED[LED_NUM_MODE3 + Pinx]);  
    Pinx--;
		LED_Off(LED_PORT0, LED[LED_NUM_MODE3 - 1 -  Pinx]);
    LED_Off(LED_PORT0, LED[LED_NUM_MODE3 + Pinx]);  
  }
}
