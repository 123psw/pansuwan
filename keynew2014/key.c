#include "key.h"

bit key_detection(u8 GPIOx , u8 Pinx)
{
	 bit key_dn;
   static bit key_o = 1; //��һ������״̬
   bit key_n;               //��ǰ����״̬
   if(GPIO_ReadPin(GPIOx , Pinx) != LOW)
     key_n = 1;
   else
     key_n = 0;
   key_dn = (key_n ^ key_o) & key_o;
	 key_o = key_n;
	 return key_dn;
}

