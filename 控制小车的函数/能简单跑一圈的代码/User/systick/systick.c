

#include "systick.h"

static __IO u32 TimingDelay;


////一微秒的定时器
//void SysTick_Dwelay_us( uint32_t us )
//{
//	uint32_t i;
//	SysTick_Config( 72 );
//	
//	for(i=0;i<us;i++)
//	{
//		while( !((SysTick->CTRL) &( 1 << 16 )) );
//	}
//	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
//}


////一毫秒的定时器
//void SysTick_Dwelay_ms( uint32_t ms )
//{
//	uint32_t i;
//	SysTick_Config( 72000 );
//	
//	for(i=0;i<ms;i++)
//	{
//		while( !((SysTick->CTRL) &( 1 << 16 )) );
//	}
//	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
//}
 
/*启动系统滴答定时器 SysTick*/
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms中断一次
	 * SystemFrequency / 100000	 10us中断一次
	 * SystemFrequency / 1000000 1us中断一次	*/
	if (SysTick_Config(SystemCoreClock / 1000000))while (1);	
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;// 关闭滴答定时器  
}

void delay_us(__IO u32 nTime)
{ 
	TimingDelay = nTime;		
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;// 使能滴答定时器  
	while(TimingDelay != 0);
}

/*** @brief  获取节拍程序
  * @attention  在 SysTick 中断函数 SysTick_Handler()调用  */
void TimingDelay_Decrement(void)
{
	if(TimingDelay != 0x00)TimingDelay--;
}









