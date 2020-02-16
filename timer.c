#include	"timer.h"

/********************* Timer0ÖÐ¶Ïº¯Êý************************/
//void timer0_int (void) interrupt TIMER0_VECTOR
//{
//   P25 = ~P25;
//}

/********************* Timer1ÖÐ¶Ïº¯Êý************************/
void timer1_int (void) interrupt TIMER1_VECTOR
{
   P26 = ~P26;

}

/********************* Timer2ÖÐ¶Ïº¯Êý************************/
void timer2_int (void) interrupt TIMER2_VECTOR
{
	P10 = ~P10;
}


//========================================================================
// º¯Êý: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// ÃèÊö: ¶¨Ê±Æ÷³õÊ¼»¯³ÌÐò.
// ²ÎÊý: TIMx: ½á¹¹²ÎÊý,Çë²Î¿¼timer.hÀïµÄ¶¨Òå.
// ·µ»Ø: ³É¹¦·µ»Ø0, ¿Õ²Ù×÷·µ»Ø1,´íÎó·µ»Ø2.
// °æ±¾: V1.0, 2012-10-22
//========================================================================
u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
{
	if(TIM > Timer2)	return 1;	//¿Õ²Ù×÷

	if(TIM == Timer0)
	{
		TR0 = 0;		//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_Interrupt == ENABLE)		ET0 = 1;	//ÔÊÐíÖÐ¶Ï
		else									ET0 = 0;	//½ûÖ¹ÖÐ¶Ï
		if(TIMx->TIM_Polity == PolityHigh)		PT0 = 1;	//¸ßÓÅÏÈ¼¶ÖÐ¶Ï
		else									PT0 = 0;	//µÍÓÅÏÈ¼¶ÖÐ¶Ï
		if(TIMx->TIM_Mode >  TIM_16BitAutoReloadNoMask)	return 2;	//´íÎó
		TMOD = (TMOD & ~0x03) | TIMx->TIM_Mode;	//¹¤×÷Ä£Ê½,0: 16Î»×Ô¶¯ÖØ×°, 1: 16Î»¶¨Ê±/¼ÆÊý, 2: 8Î»×Ô¶¯ÖØ×°, 3: 16Î»×Ô¶¯ÖØ×°, ²»¿ÉÆÁ±ÎÖÐ¶Ï
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x80;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x80;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x04;	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ
		else										TMOD &= ~0x04;	//¶¨Ê±
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x01;	//Êä³öÊ±ÖÓ
		else							INT_CLKO &= ~0x01;	//²»Êä³öÊ±ÖÓ
		
		TH0 = (u8)(TIMx->TIM_Value);
		TL0 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR0 = 1;	//¿ªÊ¼ÔËÐÐ
		return	0;		//³É¹¦
	}

	if(TIM == Timer1)
	{
		TR1 = 0;		//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_Interrupt == ENABLE)		ET1 = 1;	//ÔÊÐíÖÐ¶Ï
		else									ET1 = 0;	//½ûÖ¹ÖÐ¶Ï
		if(TIMx->TIM_Polity == PolityHigh)		PT1 = 1;	//¸ßÓÅÏÈ¼¶ÖÐ¶Ï
		else									PT1 = 0;	//µÍÓÅÏÈ¼¶ÖÐ¶Ï
		if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//´íÎó
		TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//¹¤×÷Ä£Ê½,0: 16Î»×Ô¶¯ÖØ×°, 1: 16Î»¶¨Ê±/¼ÆÊý, 2: 8Î»×Ô¶¯ÖØ×°
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~0x40;	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  0x40;	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	TMOD |=  0x40;	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ
		else										TMOD &= ~0x40;	//¶¨Ê±
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x02;	//Êä³öÊ±ÖÓ
		else							INT_CLKO &= ~0x02;	//²»Êä³öÊ±ÖÓ
		
		TH1 = (u8)(TIMx->TIM_Value >> 8);
		TL1 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	TR1 = 1;	//¿ªÊ¼ÔËÐÐ
		return	0;		//³É¹¦
	}

	if(TIM == Timer2)		//Timer2,¹Ì¶¨Îª16Î»×Ô¶¯ÖØ×°, ÖÐ¶ÏÎÞÓÅÏÈ¼¶
	{
		AUXR &= ~(1<<4);	//Í£Ö¹¼ÆÊý
		if(TIMx->TIM_Interrupt == ENABLE)			IE2  |=  (1<<2);	//ÔÊÐíÖÐ¶Ï
		else										IE2  &= ~(1<<2);	//½ûÖ¹ÖÐ¶Ï
		if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
		if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	AUXR &= ~(1<<2);	//12T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		AUXR |=  (1<<2);	//1T
		if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	AUXR |=  (1<<3);	//¶ÔÍâ¼ÆÊý»ò·ÖÆµ
		else										AUXR &= ~(1<<3);	//¶¨Ê±
		if(TIMx->TIM_ClkOut == ENABLE)	INT_CLKO |=  0x04;	//Êä³öÊ±ÖÓ
		else							INT_CLKO &= ~0x04;	//²»Êä³öÊ±ÖÓ

		TH2 = (u8)(TIMx->TIM_Value >> 8);
		TL2 = (u8)TIMx->TIM_Value;
		if(TIMx->TIM_Run == ENABLE)	AUXR |=  (1<<4);	//¿ªÊ¼ÔËÐÐ
		return	0;		//³É¹¦
	}
	return 2;	//´íÎó
}
