#include "TIM.h"

static void TIM_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStructure);

  // 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH2_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH2_PORT, &GPIO_InitStructure);

	 // 输出比较通道3 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH3_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH3_PORT, &GPIO_InitStructure);

  // 输出比较通道4 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH4_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH4_PORT, &GPIO_InitStructure);

}

static void TIM_Mode(void)
{
	 // 开启定时器时钟,即内部时钟CK_INT=72M
	ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK,ENABLE);

	//时基结构体初始化
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=ADVANCE_TIM_PERIOD;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= ADVANCE_TIM_PSC;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);
	
/*--------------------输出比较结构体初始化-------------------*/	
	uint16_t CCR1_Val = 0;
	uint16_t CCR2_Val = 0;
	uint16_t CCR3_Val = 0;
	uint16_t CCR4_Val = 0;
	
	//输出比较结构体初始化		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// 配置为PWM模式1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	// 输出使能
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	// 互补输出使能
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	// 输出通道电平极性配置
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	// 设置占空比大小


//	// 互补输出通道电平极性配置
//	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
//	// 输出通道空闲电平极性配置(如果不用刹车功能可以不配置)
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
//	// 互补输出通道空闲电平极性配置(如果不用刹车功能可以不配置)
//	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);


	// 使能计数器
	TIM_Cmd(ADVANCE_TIM, ENABLE);	
//	
//	// 主输出使能，当使用的是通用定时器时，这句不需要
	TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
}

void TIM_Init(void)
{
	TIM_GPIO();
	TIM_Mode();
}


