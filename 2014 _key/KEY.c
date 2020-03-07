#include "KEY.h"
#include "LED.h"

u8 LED_MODE = 0;

void delay(u8 t)
{
	u8 i;
	while(t--)
		for(i = 0 ; i < 200 ; i ++ );
}

u8  GetKey(void)
{ 
	u8 key;
  u8  t;
	LED_Close();
  if((key=P2&0xff)==0xff) return 0xff;
  for(t=0;t<2;t++) delay(3);
  if((key=P2&0xff)==0xff) return 0xff;
    return key;	
}

u8 Select(void)
{
	u8 k;
	while(1)
	{
	  k=GetKey();
		if( k == 0xff)
			 return LED_MODE;
    else if(k==LED0_SWITCH)	
		{
			 LED_MODE = 1;
			 return LED_MODE;
		}
    else if(k == LED1_SWITCH)	
		{			
		 	 LED_MODE = 2;
			 return LED_MODE;
		}
		else if(k == LED2_SWITCH)
		{
		   LED_MODE = 3;
			 return LED_MODE;
		}
	}
}
