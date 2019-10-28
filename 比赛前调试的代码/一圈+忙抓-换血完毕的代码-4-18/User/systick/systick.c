#include "systick.h"

static __IO u32 TimingDelay;
 
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









