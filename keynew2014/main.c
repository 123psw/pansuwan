#include	"config.h"
#include	"GPIO.h"
#include  "timer.h"
#include  "key.h"
#include  "LED.h"

#define MODE0_TIME    110
#define MODE1_TIME    11
#define MODE2_TIME    40

#define FLASE   0  
#define TRUE    1 

bit  mode0_next = FLASE;  
bit  mode1_next = FLASE;
bit  mode2_next = FLASE;  

bit LED0 = 0;
bit LED1 = 0;
bit LED2 = 0;
int cnt = 0;
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//�ṹ����
	GPIO_InitStructure.Pin  = GPIO_Pin_All;		//ָ��Ҫ��ʼ����IO, GPIO_Pin_0 ~ GPIO_Pin_7, �����
	GPIO_InitStructure.Mode = GPIO_PullUp;		//ָ��IO������������ʽ,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P2,&GPIO_InitStructure);	//��ʼ��
	GPIO_Inilize(GPIO_P1,&GPIO_InitStructure);
}

void	Timer_config(void)
{
	TIM_InitTypeDef		TIM_InitStructure;					//�ṹ����
	TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//ָ������ģʽ,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//ָ���ж����ȼ�, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = ENABLE;//DISABLE;				//�ж��Ƿ�����,   ENABLE��DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//ָ��ʱ��Դ,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = ENABLE;				//�Ƿ������������, ENABLE��DISABLE
	TIM_InitStructure.TIM_Value     = 5;		//��ֵ,
	TIM_InitStructure.TIM_Run       = ENABLE;				//�Ƿ��ʼ����������ʱ��, ENABLE��DISABLE
	Timer_Inilize(Timer0,&TIM_InitStructure);				//��ʼ��Timer0	  Timer0,Timer1,Timer2
}

 void timer0_int (void) interrupt TIMER0_VECTOR
{
	 cnt++;
	 if((cnt % 80) == 0)
	 {
		 LED0 = key_detection(KEY_P2 , KEY7);
		 LED1 = key_detection(KEY_P2 , KEY6);
		 LED2 = key_detection(KEY_P2 , KEY5);
	 }
	 if (cnt % MODE0_TIME == 0)  mode0_next = ~mode0_next;
   if (cnt % MODE1_TIME == 0)  mode1_next = ~mode1_next;
	 if (cnt % MODE2_TIME == 0)  mode2_next = ~mode2_next;
	 if(cnt == 40000) cnt = 0;
}
void main(void)
{
	u8 m = 3;
	GPIO_config();
	Timer_config();
	EA = 1;
	while(1)
	{
		  if(LED0) 
			{
				m = 0;
				LED_Close();
			}
		  if(LED1)
			{
				m = 1;
				LED_Close();
			}
		  if(LED2) 
			{
				m = 2;
				LED_Close();
			}
		  switch(m)
			 {
				case 0 : LED_Toggle(mode0_next,LED_PORT0,LED0_Pin); break;
				case 1 : LED_Toggle(mode1_next,LED_PORT0,LED1_Pin); break;
				case 2 : LED_Toggle(mode2_next,LED_PORT0,LED2_Pin); break; 
				default : LED_Close();
			 }
		  
	    
	    
	}		
}




