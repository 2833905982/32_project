

#include "systick.h"

static __IO u32 TimingDelay;


////һ΢��Ķ�ʱ��
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


////һ����Ķ�ʱ��
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
 
/*����ϵͳ�δ�ʱ�� SysTick*/
void SysTick_Init(void)
{
	/* SystemFrequency / 1000    1ms�ж�һ��
	 * SystemFrequency / 100000	 10us�ж�һ��
	 * SystemFrequency / 1000000 1us�ж�һ��	*/
	if (SysTick_Config(SystemCoreClock / 1000000))while (1);	
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;// �رյδ�ʱ��  
}

void delay_us(__IO u32 nTime)
{ 
	TimingDelay = nTime;		
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;// ʹ�ܵδ�ʱ��  
	while(TimingDelay != 0);
}

/*** @brief  ��ȡ���ĳ���
  * @attention  �� SysTick �жϺ��� SysTick_Handler()����  */
void TimingDelay_Decrement(void)
{
	if(TimingDelay != 0x00)TimingDelay--;
}









