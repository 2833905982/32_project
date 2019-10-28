
#include "bsp_GeneralTim.h" 


int Servo_move(TIM_TypeDef* TIMx,uint8_t CCRx,u16 intend_angle,u32 us)//三个参数分别为舵机所使用的定时器/通道/所要到达的角度/延迟us级别的
{
	if(intend_angle>2500)//不能超出周期的值
		intend_angle=2500;
	int last_angle=0;
	switch(CCRx)
	{
		case 1:
			last_angle=TIM_GetCapture1(TIMx);
				if (last_angle<=intend_angle)
				{
					while(last_angle<intend_angle)
						{
							TIM_SetCompare1(TIMx,last_angle++);
							delay_us(us);
						}
						TIM_SetCompare1(TIMx,intend_angle);//再次确定写到了该角度
				}
				else if (last_angle>=intend_angle)
				{
					while(last_angle>intend_angle)
						{
							TIM_SetCompare1(TIMx,last_angle--);
							delay_us(us);
						}
						TIM_SetCompare1(TIMx,intend_angle);//再次确定写到了该角度
				}
			break;
		case 2:
			last_angle=TIM_GetCapture2(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare2(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare2(TIMx,intend_angle);//再次确定写到了该角度
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare2(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare2(TIMx,intend_angle);//再次确定写到了该角度
			}
			break;
		case 3:
			last_angle=TIM_GetCapture3(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare3(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare3(TIMx,intend_angle);//再次确定写到了该角度
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare3(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare3(TIMx,intend_angle);//再次确定写到了该角度
			}
			break;
		case 4:
			last_angle=TIM_GetCapture4(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare4(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare4(TIMx,intend_angle);//再次确定写到了该角度
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare4(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare4(TIMx,intend_angle);//再次确定写到了该角度
			}
			break;
		default:
			return -1;//输入错误
	}

		return 1;//ok
}


void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
		/*-------------------------------------TIM3  GPIO初始化----------------------------------------------------*/

//  // 输出比较通道1 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH1_GPIO_CLK, ENABLE);
////  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH1_PORT, &GPIO_InitStructure);
	
//	// 输出比较通道2 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH2_PORT, &GPIO_InitStructure);
	
//	// 输出比较通道3 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH3_PORT, &GPIO_InitStructure);
//	
//	// 输出比较通道4 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH4_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH4_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH4_PORT, &GPIO_InitStructure);
	
	/*-------------------------------------TIM4  GPIO初始化----------------------------------------------------*/
	// 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH1_PORT, &GPIO_InitStructure);
	
	// 输出比较通道2 GPIO 初始化
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH2_PORT, &GPIO_InitStructure);
	
	
	
//	/*-------------------------------------TIM5  GPIO初始化----------------------------------------------------*/
//	// 输出比较通道1 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH1_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH1_PORT, &GPIO_InitStructure);
//	
//	// 输出比较通道2 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH2_PORT, &GPIO_InitStructure);
//	
//	// 输出比较通道3 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH3_PORT, &GPIO_InitStructure);
//	
//	// 输出比较通道4 GPIO 初始化
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH4_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH4_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH4_PORT, &GPIO_InitStructure);
}


///*
// * 注意：TIM_TimeBaseInitTypeDef结构体里面有5个成员，TIM6和TIM7的寄存器里面只有
// * TIM_Prescaler和TIM_Period，所以使用TIM6和TIM7的时候只需初始化这两个成员即可，
// * 另外三个成员是通用定时器和高级定时器才有.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            都有
// *	TIM_CounterMode			     TIMx,x[6,7]没有，其他都有
// *  TIM_Period               都有
// *  TIM_ClockDivision        TIMx,x[6,7]没有，其他都有
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]才有
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM信号 周期和占空比的计算--------------- */
// ARR ：自动重装载寄存器的值
// CLK_cnt：计数器的时钟，等于 Fck_int / (psc+1) = 72M/(psc+1)
// PWM 信号的周期 T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// 占空比P=CCR/(ARR+1)

void GENERAL_TIM_Mode_Config(void)
{
  // 开启定时器时钟,即内部时钟CK_INT=72M
//	//TIM3时钟
//	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM3_CLK,ENABLE);
	//TIM4时钟
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM4_CLK,ENABLE);
//	//TIM5时钟
//	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM5_CLK,ENABLE);
	

/*--------------------时基结构体初始化-------------------------*/
	// 配置周期，这里配置为100K
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler;	
	// 时钟分频因子 ，配置死区时间时需要用到
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// 计数器计数模式，设置为向上计数
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// 重复计数器的值，没用到不用管
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM3, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(GENERAL_TIM5, &TIM_TimeBaseStructure);

//	/*--------------------输出比较结构体初始化（TIM3）-------------------*/	
//	// 占空比配置
//	uint16_t CCR1_Val_3 = 0;
//	uint16_t CCR2_Val_3 = 0;
////	uint16_t CCR3_Val_3 = 0;
////	uint16_t CCR4_Val_3 = 0;
//	
//	TIM_OCInitTypeDef  TIM_OCInitStructure3;//TIM_OCInitStruct
//	// 配置为PWM模式1
//	TIM_OCInitStructure3.TIM_OCMode = TIM_OCMode_PWM1;
//	// 输出使能
//	TIM_OCInitStructure3.TIM_OutputState = TIM_OutputState_Enable;
//	// 输出通道电平极性配置	
//	TIM_OCInitStructure3.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	// 输出比较通道 1
//	TIM_OCInitStructure3.TIM_Pulse = CCR1_Val_3;
//	TIM_OC1Init(GENERAL_TIM3, &TIM_OCInitStructure3);
//	TIM_OC1PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
//	
//	// 输出比较通道 2
//	TIM_OCInitStructure3.TIM_Pulse = CCR2_Val_3;
//	TIM_OC2Init(GENERAL_TIM3, &TIM_OCInitStructure3);
//	TIM_OC2PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
//	
////	// 输出比较通道 3
////	TIM_OCInitStructure3.TIM_Pulse = CCR3_Val_3;
////	TIM_OC1Init(GENERAL_TIM3, &TIM_OCInitStructure3);
////	TIM_OC1PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
////	
////	// 输出比较通道 4
////	TIM_OCInitStructure3.TIM_Pulse = CCR4_Val_3;
////	TIM_OC2Init(GENERAL_TIM3, &TIM_OCInitStructure3);
////	TIM_OC2PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
	

//	
//	//		/*--------------------输出比较结构体初始化（TIM5）-------------------*/	
//	// 占空比配置
//	uint16_t CCR1_Val_5 = 0;
//	uint16_t CCR2_Val_5 = 0;
//	uint16_t CCR3_Val_5 = 0;
//	uint16_t CCR4_Val_5 = 0;
//	
//	TIM_OCInitTypeDef  TIM_OCInitStructure5;
//	// 配置为PWM模式1
//	TIM_OCInitStructure5.TIM_OCMode = TIM_OCMode_PWM1;
//	// 输出使能
//	TIM_OCInitStructure5.TIM_OutputState = TIM_OutputState_Enable;
//	// 输出通道电平极性配置	
//	TIM_OCInitStructure5.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	// 输出比较通道 1
//	TIM_OCInitStructure5.TIM_Pulse = CCR1_Val_5;
//	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// 输出比较通道 2
//	TIM_OCInitStructure5.TIM_Pulse = CCR2_Val_5;
//	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// 输出比较通道 3
//	TIM_OCInitStructure5.TIM_Pulse = CCR3_Val_5;
//	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// 输出比较通道 4
//	TIM_OCInitStructure5.TIM_Pulse = CCR4_Val_5;
//	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	

	

	
	/*--------------------时基结构体初始化-------------------------*/
	// 配置周期，这里配置为100K
	

	// 自动重装载寄存器的值，累计TIM_Period+1个频率后产生一个更新或者中断
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_Run;	
	// 驱动CNT计数器的时钟 = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_Run;	
	
	// 初始化定时器
	TIM_TimeBaseInit(GENERAL_TIM4, &TIM_TimeBaseStructure);
	/*-----------------------------------------------------------*/
	
	

/*--------------------输出比较结构体初始化（TIM4）-------------------*/	
	// 占空比配置
	uint16_t CCR1_Val_4 = 0;
	uint16_t CCR2_Val_4 = 0;
	
	
	TIM_OCInitTypeDef  TIM_OCInitStructure2;
	// 配置为PWM模式1
	TIM_OCInitStructure2.TIM_OCMode = TIM_OCMode_PWM1;
	// 输出使能
	TIM_OCInitStructure2.TIM_OutputState = TIM_OutputState_Enable;
	// 输出通道电平极性配置	
	TIM_OCInitStructure2.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// 输出比较通道 1
	TIM_OCInitStructure2.TIM_Pulse = CCR1_Val_4;
	TIM_OC1Init(GENERAL_TIM4, &TIM_OCInitStructure2);
	TIM_OC1PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	// 输出比较通道 2
	TIM_OCInitStructure2.TIM_Pulse = CCR2_Val_4;
	TIM_OC2Init(GENERAL_TIM4, &TIM_OCInitStructure2);
	TIM_OC2PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	
	
	
	
/*----------------------------------------------------------------------------------------------------------*/	
	// 使能计数器
	TIM_Cmd(GENERAL_TIM3, ENABLE);
	TIM_Cmd(GENERAL_TIM4, ENABLE);
	TIM_Cmd(GENERAL_TIM5, ENABLE);
	
	
	
	
	
}

void LED_GPIO_Config(void)/*LDE显示灯初始化*/
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
	
	
	/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO2_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		
		
		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU1_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		
		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK , ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU2_GPIO_PIN;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
}


//控制两组电机
void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2,u16 Fangxiang3,u16 Fangxiang4)//前两个参数左右电机速度  后两个参数方向
{
	
	TIM_SetCompare2(TIM4,left);
	TIM_SetCompare1(TIM4,right);
	LUN_ZUO1(Fangxiang1);
	LUN_ZUO2(Fangxiang2);
	LUN_YOU1(Fangxiang3);
	LUN_YOU2(Fangxiang4);
}



//转盘
int ZhuanPan(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,1,intend_angle,us);
}

//1号舵机
int DuoJi1(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,2,intend_angle,us);
}

//2号舵机
int DuoJi2(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,3,intend_angle,us);
}

//3号舵机
int DuoJi3(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,4,intend_angle,us);
}

//爪子
int ZhaZi(u16 intend_angle,u32 us)
{
	Servo_move(TIM3,1,intend_angle,us);
}


/*********************************************END OF FILE**********************/
