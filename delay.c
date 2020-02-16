#include	"delay.h"



//========================================================================
// º¯Êý: void  delay_ms(unsigned char ms)
// ÃèÊö: ÑÓÊ±º¯Êý¡£
// ²ÎÊý: ms,ÒªÑÓÊ±µÄmsÊý, ÕâÀïÖ»Ö§³Ö1~255ms. ×Ô¶¯ÊÊÓ¦Ö÷Ê±ÖÓ.
// ·µ»Ø: none.
// °æ±¾: VER1.0
// ÈÕÆÚ: 2013-4-1
// ±¸×¢: 
//========================================================================
//void  delay_ms(unsigned int ms)
//{
//     unsigned int i;
//	 do{
//	      i = MAIN_Fosc / 13000;
//		  while(--i)	;   //14T per loop
//     }while(--ms);
//}

void delay_ms(unsigned int ms)		//@11.0592MHz
{
	unsigned char i, j;
 while(ms--)
 {
	 _nop_();
	 i = 2;
	 j = 199;
	 do
	  {
		  while (--j);
	  } while (--i);
  }
}
