#include "rccclkconfig.h"

void HSE_SetSysCLK( uint32_t RCC_PLLMul_x )									//使用HSE高速外部晶振设置系统时钟。        //频率的大小，用RCC_PLLMul_x * 8来确定。
{
	ErrorStatus HSEStatus;																		//定义一个	ErrorStatus，类型的变量。	

	RCC_DeInit();																							//把RCC寄存器复位成复位值。
	
	RCC_HSEConfig( RCC_HSE_ON );															//使能 HSE 
	
	HSEStatus = RCC_WaitForHSEStartUp();
	
	if( HSEStatus == SUCCESS )
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);			//使能预取值
		FLASH_SetLatency(FLASH_Latency_2);													//等待有三中，分别是0，1，2，这里始值为2个等待。
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
		//锁相环配置
		//配置PLLCLK = HSE * RCC_PLLMul_x
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_x);				//如果想超频可以通过更改这里的数字实现。
		//使能PLL
    RCC_PLLCmd(ENABLE);
		//等待PLL时钟稳定
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET);
		//选择系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while( RCC_GetSYSCLKSource() != 0x08);
	}
	else
	{
		/*如果HSE 启动失败，用户可以在这里处理错误的代码。*/
	}
}

