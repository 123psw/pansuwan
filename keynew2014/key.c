#include "key.h"

bit key_detection(u8 GPIOx , u8 Pinx)
{
	 bit key_dn;
   static bit key_o = 1; //上一个按键状态
   bit key_n;               //当前按键状态
   if(GPIO_ReadPin(GPIOx , Pinx) != LOW)
     key_n = 1;
   else
     key_n = 0;
   key_dn = (key_n ^ key_o) & key_o;
	 key_o = key_n;
	 return key_dn;
}

