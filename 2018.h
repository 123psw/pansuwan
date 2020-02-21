#include	"config.h"
#include	"GPIO.h"
#include  "timer.h"
#include  "LED.h"

#define MODE0_TIME    1000
#define MODE1_TIME    1000
#define MODE2_TIME    1000
#define MODE3_TIME    1000

#define MODE_0 0x00
#define MODE_1 0x01
#define MODE_2 0x02
#define MODE_3 0x03
#define BUZZER_OPEN  400     //蜂鸣器响应时间ms
#define BUZZER_CLOSE  400    //蜂鸣器停止时间ms


#define BUZZER   P25

#define FLASE   0  
#define TRUE    1 

bit  mode0_next = FLASE;  
bit  mode1_next = FLASE;
bit  mode2_next = FLASE;  
bit  mode3_next = FLASE;
bit  buzzer0 = FLASE;

u8 mode = MODE_0;
unsigned int cnt = 0; 
unsigned int buzzer_timers = 0; 
u8 i = 0;

void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//结构定义
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
	GPIO_InitStructure.Mode = GPIO_OUT_PP;		//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);
}

void	Timer_config(void)
{
	TIM_InitTypeDef		TIM_InitStructure;					//结构定义
	TIM_InitStructure.TIM_Mode      = TIM_8BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;//DISABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 5;		//初值,
	TIM_InitStructure.TIM_Run       = ENABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
}

void timer0_int (void) interrupt TIMER0_VECTOR
{  
	  cnt++;
	  buzzer_timers ++ ;
    if (cnt % MODE0_TIME == 0)  mode0_next = TRUE ;
    if (cnt % MODE1_TIME == 0)  mode1_next = TRUE ;
	  if (cnt % MODE2_TIME == 0)  mode2_next = TRUE ;
    if (cnt % MODE3_TIME == 0)  mode3_next = TRUE ;
	  if (buzzer_timers <= BUZZER_OPEN)  buzzer0 = TRUE ;
	  if (buzzer_timers > BUZZER_OPEN && buzzer_timers <=  (BUZZER_OPEN + BUZZER_CLOSE)) buzzer0 = FLASE ;
	  if (buzzer_timers == (BUZZER_OPEN + BUZZER_CLOSE)) buzzer_timers = 0;
    if (cnt % 60000 == 0) cnt = 0;
}


/******************** 主函数 **************************/
void main(void)
{
	GPIO_config();
	Timer_config();
	EA = 1;
	while(1)
	{
    switch (mode) 
    {
      case MODE_0:
      {
         if (mode0_next == TRUE)
         {
            mode0_next = FALSE;
            LED_LeftToRight(i);
            if( i >= LED_NUM_MODE0 + 1) 
            {
							i = 0;
              mode = MODE_1;
              break;
            } 
            i++;
         }
       }break;
      case MODE_1:
      {
				if (mode1_next == TRUE)
         {
            mode1_next = FALSE;
            LED_RightToLeft(i);
            if( i >= LED_NUM_MODE1 + 1) 
            {
							i = 0;
              mode = MODE_2;
              break;
            } 
            i++;
         }     
      }break;				
			case MODE_2:
      {
				if (mode2_next == TRUE)
         {
            mode2_next = FALSE;
            LED_SideToCenter(i);	
            if( i >= LED_NUM_MODE2 + 1) 
            {
							i = 0;
              mode = MODE_3;
              break;
            } 
            i++;
         }      			 
      }break;	
			case MODE_3:
      {
				if (mode3_next == TRUE)
         {
            mode3_next = FALSE;
            LED_CenterToSide(i);
            if( i >= LED_NUM_MODE3 + 1) 
            {
							i = 0;
              mode = MODE_0;
              break;
            } 
            i++;
         }  		 
      } break;		
    }	
		if(buzzer0 == TRUE) BUZZER = 1;
		if(buzzer0 == FLASE) BUZZER = 0;
	}
}




