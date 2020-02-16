#ifndef	__TIMER_H
#define	__TIMER_H

#include	"config.h"

#define	Timer0						0
#define	Timer1						1
#define	Timer2						2
#define	Timer3						3
#define	Timer4						4

#define	TIM_16BitAutoReload			0 
#define	TIM_16Bit					1
#define	TIM_8BitAutoReload			2
#define	TIM_16BitAutoReloadNoMask	3

#define	TIM_CLOCK_1T				0
#define	TIM_CLOCK_12T				1
#define	TIM_CLOCK_Ext				2

typedef struct
{
	u8	TIM_Mode;		//¹¤×÷Ä£Ê½,  	TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	u8	TIM_Polity;		//ÓÅÏÈ¼¶ÉèÖÃ	PolityHigh,PolityLow
	u8	TIM_Interrupt;	//ÖÐ¶ÏÔÊÐí		ENABLE,DISABLE
	u8	TIM_ClkSource;	//Ê±ÖÓÔ´		TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	u8	TIM_ClkOut;		//¿É±à³ÌÊ±ÖÓÊä³ö,	ENABLE,DISABLE
	u16	TIM_Value;		//×°ÔØ³õÖµ
	u8	TIM_Run;		//ÊÇ·ñÔËÐÐ		ENABLE,DISABLE
} TIM_InitTypeDef;

u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx);

#endif
