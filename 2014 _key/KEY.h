#ifndef __KEY_H
#define __KEY_H

#include	"config.h"

#define LED0_SWITCH  0xdf
#define LED1_SWITCH  0Xbf 
#define LED2_SWITCH  0X7f

void delay(u8 t);
u8 GetKey(void);
u8 Select(void);

#endif