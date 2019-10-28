#include "systick.h"

//us
void delay_us(uint32_t us)
{
	uint32_t i;
	SysTick_Config(72);
	
	for(i=0;i<us;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


//ms
void delay_ms(uint32_t ms)
{
	uint32_t i;
	SysTick_Config(72000);
	
	for(i=0;i<ms;i++)
	{
		while( !((SysTick->CTRL) & (1<<16)) );             //�ȴ���1������1 ��1msʱ�䵽��
	}
	
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


