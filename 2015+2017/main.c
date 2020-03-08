#include	"config.h"
#include	"GPIO.h"
#include  "timer.h"
#include  "key.h"
#include  "LED.h"

#define MODE0_TIME    22

#define FLASE   0  
#define TRUE    1 

bit  mode0_next = FLASE;  

bit LED0 = 0;
int cnt = 0;
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//结构定义
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
	GPIO_InitStructure.Mode = GPIO_PullUp;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);	//初始化
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);
}

void	Timer_config(void)
{
	TIM_InitTypeDef		TIM_InitStructure;					//结构定义
	TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;//DISABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 5;		//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
}

 void timer0_int (void) interrupt TIMER0_VECTOR
{
	 cnt++;
	 if((cnt % 22) == 0)  LED0 = key_detection(KEY_P2 , KEY7);	
	 if (cnt % MODE0_TIME == 0)  mode0_next = ~mode0_next;
	 if(cnt == 40000) cnt = 0;
}
void main(void)
{
	u8 m = 0;
	u8 i = 0;
	GPIO_config();
	Timer_config();
	EA = 1;
	while(1)
	{
		  if(LED0)  m = 1;
		  /*if(m) LED_Off(LED_PORT0,LED1_Pin );
			else 	LED_On(LED_PORT0,LED1_Pin );
		  2015年题目*/
		  if(m == 1) LED_Off(LED_PORT0,LED1_Pin );
		  else  LED_Toggle(mode0_next , LED_PORT0, LED1_Pin); //2017年题目
				
	}		
}




