/**
  ******************************************************************************
  * @file    Servo.c
  * @version V3.2
  * @date    2018.10.6
  * @brief   使能舵机、并进行驱动
							修正switch(case)错误
  ******************************************************************************
  * @attention	只适用于大容量的开发板
  *
  * 实验平台		:野火stm32f103zet6 核心板
  * 版权所有		:河南理工大学机械创新设计部
  * 责任人			:王太杰
  *
  ******************************************************************************
  */ 
#include <Servo.h>
static void Servo_Delay_us(uint32_t us)//不精确的us计延时
{
	u8 i;//1us的时钟周期大概为80次
	while(us--)
	{
	 i=80;
		while(i--);
	}
}
static TIM_TypeDef* Get_Servo_TIMx(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin)//判断GPIOx、pinx是哪个定时器
{
	TIM_TypeDef* TIMx;
	if (Servo_GPIOx==GPIOA)//*******注意。如果复用。需要使能。
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
				TIMx=TIM1;
				break;
			case GPIO_Pin_9://TIM1_CH2
				TIMx=TIM1;
				break;
			case GPIO_Pin_10://TIM1_CH3
				TIMx=TIM1;
				break;
			case GPIO_Pin_11://TIM1_CH4
				TIMx=TIM1;
				break;
			case GPIO_Pin_0://TIM2_CH1
				TIMx=TIM2;
				break;
			case GPIO_Pin_1://TIM2_CH2
				TIMx=TIM2;
				break;
			case GPIO_Pin_2://TIM2_CH3
				TIMx=TIM2;
				break;
			case GPIO_Pin_3://TIM2_CH4
				TIMx=TIM2;
				break;
			case GPIO_Pin_6://TIM3_CH1
				TIMx=TIM3;
				break;
			case GPIO_Pin_7://TIM3_CH2
				TIMx=TIM3;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
				TIMx=TIM3;
				break;
			case GPIO_Pin_1://TIM3_CH4
				TIMx=TIM3;
				break;
			case GPIO_Pin_6://TIM4_CH1
				TIMx=TIM4;
				break;
			case GPIO_Pin_7://TIM4_CH2
				TIMx=TIM4;
				break;
			case GPIO_Pin_8://TIM4_CH3
				TIMx=TIM4;
				break;
			case GPIO_Pin_9://TIM4_CH4
				TIMx=TIM4;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
				TIMx=TIM8;
				break;
			case GPIO_Pin_7://TIM8_CH2
				TIMx=TIM8;
				break;
			case GPIO_Pin_8://TIM8_CH3
				TIMx=TIM8;
				break;
			case GPIO_Pin_9://TIM8_CH4
				TIMx=TIM8;
				break;
//			default:
//				return -1;
		}
	}
	return TIMx;
}

static int Get_Servo_CCRx(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin)//判断GPIOx、pinx是哪个通道
{
		int CCRx=0;
	if (Servo_GPIOx==GPIOA)//*******注意。如果复用。需要使能。
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
			CCRx=1;
				break;
			case GPIO_Pin_9://TIM1_CH2
			CCRx=2;
				break;
			case GPIO_Pin_10://TIM1_CH3
			CCRx=3;
				break;
			case GPIO_Pin_11://TIM1_CH4
			CCRx=4;
				break;
			case GPIO_Pin_0://TIM2_CH1
			CCRx=1;
				break;
			case GPIO_Pin_1://TIM2_CH2
			CCRx=2;
				break;
			case GPIO_Pin_2://TIM2_CH3
			CCRx=3;
				break;
			case GPIO_Pin_3://TIM2_CH4
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM3_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM3_CH2
			CCRx=2;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
			CCRx=3;
				break;
			case GPIO_Pin_1://TIM3_CH4
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM4_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM4_CH2
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM4_CH3
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM4_CH4
			CCRx=4;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM8_CH2
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM8_CH3
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM8_CH4
			CCRx=4;
				break;
		}
	}
	return CCRx;
}


int Servo_GPIO_Init(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin,uint16_t start_angle)
{
	uint16_t CCRx_VAL=1500;//先给个初始值
	if(start_angle>=Servo_angle_max)//防止程序猿写超了
		start_angle=Servo_angle_max;
	else if(start_angle<=Servo_angle_min)//防止写少了
		start_angle=Servo_angle_min;
	else 
	{CCRx_VAL=start_angle;}//通道初始数值获取
	GPIO_InitTypeDef GPIO_Servo;
	TIM_TimeBaseInitTypeDef  Servo_TimeBaseStructure;
	TIM_OCInitTypeDef  Servo_OCInitStructure;
	TIM_TypeDef* TIMx;
	uint32_t Servo_GPIO_CLK;
	uint32_t Servo_RCC_APBxPeriph_TIMx;
	
	u8 CCRx=0;//第几个通道
	if (Servo_GPIOx==GPIOA)//*******注意。如果复用。需要使能。
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOA;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=1;
				break;
			case GPIO_Pin_9://TIM1_CH2
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=2;
				break;
			case GPIO_Pin_10://TIM1_CH3
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=3;
				break;
			case GPIO_Pin_11://TIM1_CH4
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=4;
				break;
			case GPIO_Pin_0://TIM2_CH1
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=1;
				break;
			case GPIO_Pin_1://TIM2_CH2
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=2;
				break;
			case GPIO_Pin_2://TIM2_CH3
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=3;
				break;
			case GPIO_Pin_3://TIM2_CH4
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM3_CH1
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM3_CH2
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=2;
				break;
			default:
				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOB;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=3;
				break;
			case GPIO_Pin_1://TIM3_CH4
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM4_CH1
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM4_CH2
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM4_CH3
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM4_CH4
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=4;
				break;
			default:
				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOC;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM8_CH2
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM8_CH3
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM8_CH4
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=4;
				break;
			default:
				return -1;
		}
	}
	
	/*******pwm输出暂时用不到********/
//	else if (Servo_GPIOx==GPIOD)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOD;
//	}
//	else if (Servo_GPIOx==GPIOE)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOE;
//	}
//	else if (Servo_GPIOx==GPIOF)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOF;
//	}
//	else if (Servo_GPIOx==GPIOG)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOG;
//	}
	
	else 
		return -1;
	
  // 输出比较通道1 GPIO 初始化
	RCC_APB2PeriphClockCmd(Servo_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//复用使能
	GPIO_Servo.GPIO_Pin =  Servo_GPIO_Pin;
  GPIO_Servo.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出
  GPIO_Servo.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(Servo_GPIOx, &GPIO_Servo);
	if(TIMx==TIM1||TIMx==TIM8)
	{
		RCC_APB2PeriphClockCmd(Servo_RCC_APBxPeriph_TIMx, ENABLE); 
	}
	else if(TIMx==TIM2||TIMx==TIM3||TIMx==TIM4)
	{
		RCC_APB1PeriphClockCmd(Servo_RCC_APBxPeriph_TIMx, ENABLE); 
	}
	
	Servo_TimeBaseStructure.TIM_Period =20000-1;       //当定时器从0计数到19999，即为20000次，为一个定时周期
  Servo_TimeBaseStructure.TIM_Prescaler =72-1;	    //1MHz
  Servo_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//设置时钟分频系数：不分频(这里用不到)
  Servo_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
  TIM_TimeBaseInit(TIMx, &Servo_TimeBaseStructure);
	//***************************使能通道********************************//
	Servo_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //配置为PWM模式1
  Servo_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //当定时器计数值小于CCR1_Val时为高电平
  Servo_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	Servo_OCInitStructure.TIM_Pulse=CCRx_VAL;
	switch (CCRx)
	{
		case 1:
			TIM_OC1Init(TIMx, &Servo_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 2:
			TIM_OC2Init(TIMx, &Servo_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 3:
			TIM_OC3Init(TIMx, &Servo_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 4:
			TIM_OC4Init(TIMx, &Servo_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		default :
			return -2;
	}
			TIM_ARRPreloadConfig(TIMx, ENABLE);			 // 使能TIM3重载寄存器ARR
			TIM_Cmd(TIMx, ENABLE);                   //使能定时器3	
	return 1;//初始化成功
}

int Servo_Init(Servo Servox[],int array_length)//参数为结构体数组//array_length=sizeof(Servox)/(5*sizeof(uint16_t));
{
	int times=0;
	while(array_length--)
	{
	if(1!=Servo_GPIO_Init(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin,Servox[times].start_angle))//将结构成员的信息截取，并调用初始化函数，进行配置。
		return -1;//初始化错误
		times++;
	}
	return 1;//初始化成功。
}

int NServo_Write(Servo Servox[],uint32_t us,int array_length)//要进行操作的结构体数组、和延时
{
	int times=0;
	int CCRx[array_length];
	TIM_TypeDef* TIMx[array_length];
	for(times=0;times<array_length;++times)//获取当前通道的pwm输出，存入结构体的start_angle中，并判断是通道几、存入结构体中
	{
		TIMx[times]=Get_Servo_TIMx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin);
		if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==1)
		{
		Servox[times].start_angle=TIM_GetCapture1(TIMx[times]);//依次获取上次
		CCRx[times]=1;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==2)
		{
		Servox[times].start_angle=TIM_GetCapture2(TIMx[times]);//依次获取上次
		CCRx[times]=2;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==3)
		{
		Servox[times].start_angle=TIM_GetCapture3(TIMx[times]);//依次获取上次
		CCRx[times]=3;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==4)
		{
		Servox[times].start_angle=TIM_GetCapture4(TIMx[times]);//依次获取上次
		CCRx[times]=4;
		}
	}
	int intent_flag=0x0000;
	int flag=0x0000;
		for(times=0;times<array_length;++times)
  {
				intent_flag<<=1;
				intent_flag|=0x0001;
	}
	while(1)
	{
		int once=1;//pwm每次变化的值
	for(times=0;times<array_length;++times)//写入寄存器.并延时
	{
		if (Servox[times].start_angle==Servox[times].intent_angle)
		{
			flag|=(0x0001<<times);//标志位加一。
				if(flag==intent_flag)
				{return 1;}//如果循环了length次、即遍历了所有的Servo结构体。并且所有的成员的上次角度值等于目的角度值、则视为全部归位。
			continue;//继续处理下一个结构体的数据
		}
		else if(Servox[times].start_angle>Servox[times].intent_angle)
		{
			once=-1;//如果当前值大于目的值、则为减1
		}
		else if(Servox[times].start_angle<Servox[times].intent_angle)
		{
			once=1;//如果当前值小于目的值、则为加1
		}
		if(CCRx[times]==1)
		{
			TIM_SetCompare1(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==2)
		{
		TIM_SetCompare2(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==3)
		{
		TIM_SetCompare3(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==4)
		{
		TIM_SetCompare4(TIMx[times], Servox[times].start_angle+=once);
		}
	}
	Servo_Delay_us(us);//舵机的大概延时
}
	return 1;
}

