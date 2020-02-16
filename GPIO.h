#ifndef	__GPIO_H
#define	__GPIO_H

#include	"config.h"

#define	GPIO_PullUp		0	//ÉÏÀ­×¼Ë«Ïò¿Ú
#define	GPIO_HighZ		1	//¸¡¿ÕÊäÈë
#define	GPIO_OUT_OD		2	//¿ªÂ©Êä³ö
#define	GPIO_OUT_PP		3	//ÍÆÍìÊä³ö

#define	GPIO_Pin_0		0x01	//IOÒý½Å Px.0
#define	GPIO_Pin_1		0x02	//IOÒý½Å Px.1
#define	GPIO_Pin_2		0x04	//IOÒý½Å Px.2
#define	GPIO_Pin_3		0x08	//IOÒý½Å Px.3
#define	GPIO_Pin_4		0x10	//IOÒý½Å Px.4
#define	GPIO_Pin_5		0x20	//IOÒý½Å Px.5
#define	GPIO_Pin_6		0x40	//IOÒý½Å Px.6
#define	GPIO_Pin_7		0x80	//IOÒý½Å Px.7
#define	GPIO_Pin_All	0xFF	//IOËùÓÐÒý½Å
	
#define	GPIO_P0			0		//
#define	GPIO_P1			1
#define	GPIO_P2			2
#define	GPIO_P3			3
#define	GPIO_P4			4
#define	GPIO_P5			5

#define  LOW   1
#define  HIGH  0

typedef struct
{
	u8	Mode;		//IOÄ£Ê½,  		GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	u8	Pin;		//ÒªÉèÖÃµÄ¶Ë¿Ú	
} GPIO_InitTypeDef;

u8	GPIO_Inilize(u8 GPIO, GPIO_InitTypeDef *GPIOx);
u8 GPIO_WritePin(u8 GPIO , u8 Pinx , bit Level);
#endif
