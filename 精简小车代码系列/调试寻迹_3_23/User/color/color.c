#include "stm32f10x.h"
#include "color.h"
#include "systick.h"
#include "move.h"

volatile u32 Colour_num1=0,Colour_num2=0,Colour_num3=0,Colour_num4=0;		// 用于颜色传感器脉冲计数u32
volatile u8  Time2_flag=0;    //定时器标志位


/***************************** 定时器 **************************************/
/*配置定时器2的中断优先级为11*/
void TIM2_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;     
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //选择组2												
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//中断源为TIM2  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;//抢占优先级0，
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;	//响应优先级0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//开启中断
    NVIC_Init(&NVIC_InitStructure);
}

/*初始化定时器2*/
void TIM2_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		
	/* 设置TIM2CLK 为 72MHZ */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);//使能定时器2的时钟
								//TIM_DeInit(TIM2);
	TIM2_NVIC_Configuration();//配置定时器2的中断优先级
	/* 自动重装载寄存器周期的值(计数值) */
    TIM_TimeBaseStructure.TIM_Period=1000;//1ms	
    /* 累计 TIM_Period个频率后产生一个更新或者中断 */	  
    TIM_TimeBaseStructure.TIM_Prescaler= 71;//时钟预分频数为72 	
	/* 对外部时钟进行采样的时钟分频,这里没有用到 */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;	
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计算模式
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);//清除中断标志位	
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);		
    TIM_Cmd(TIM2, ENABLE);																		  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);		/*先关闭等待使用*/    
}

/****************************** END ****************************************/


/******************************* 外部中断 *****************************************/

 void EXTI2_NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//选择组别，2位抢占优先级，2位响应优先级
  /* 配置中断源 */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


/****************************** END **************************************/


/**********************************************************************/

void EXTI_PG2_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG | RCC_APB2Periph_AFIO,ENABLE);
												
	EXTI2_NVIC_Configuration();

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // 上拉输入
  GPIO_Init(GPIOG, &GPIO_InitStructure);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
  EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); 
}



/************************************************************************
用于计算传感器OUT输出脉冲个数
***********************************************************************/

void Color2_GPIO_Config(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	/*开启LED的外设时钟*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOG, ENABLE); 
	/*设置引脚模式为通用推挽输出*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*设置引脚速率为50MHz */   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*选择要控制的GPIOA引脚*/															   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_8;	
	/*调用库函数，初始化GPIOB0*/
	GPIO_Init(GPIOG, &GPIO_InitStructure);		
}


void Colour2_Config(u8 Colour)
{
	switch(Colour)
	 {
	 	case Red  : TCS32_S22(0);TCS32_S32(0);break;
		case Blue : TCS32_S22(0);TCS32_S32(1);break;
		case Green: TCS32_S22(1);TCS32_S32(1);break;
		default    : break;
	 }
}

void EXTI_PG2_Config_on()//开外部中断
{
	EXTI_InitTypeDef EXTI_InitStructure2;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
	EXTI_InitStructure2.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure2.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
	EXTI_InitStructure2.EXTI_LineCmd =ENABLE;
	EXTI_Init(&EXTI_InitStructure2); 
}

void EXTI_PG2_Config_off()//关外部中断
{
	EXTI_InitTypeDef EXTI_InitStructure2;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
	EXTI_InitStructure2.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure2.EXTI_Trigger = EXTI_Trigger_Falling; //下降沿中断
	EXTI_InitStructure2.EXTI_LineCmd =DISABLE;
	EXTI_Init(&EXTI_InitStructure2); 
}

void TCS230_Start2(void)
{
	Colour_num2=0;												//	计数清零
	Time2_flag=0; 												// 定时器标志清零	
	EXTI_PG2_Config_on();								  //开外部中断
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);//开启TIM2时钟，开始计时
}

u32 TCS230_Read_Num2(u8 Colour)
{  
	Colour2_Config(Colour);								//配置TCS230的颜色滤波器	
	TCS230_Start2();											//初始化各变量 ，并开启定时器和外部中断                    
	while(Time2_flag==0);									//等待计数完
	EXTI_PG2_Config_off();								//关外部中断
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);//关定时器
	return Colour_num2;										// 返回计数个数
}



void color_Init()//颜色传感器初始化
{ 
	TIM2_Configuration();
	Color2_GPIO_Config();	
	EXTI_PG2_Config();
	TCS32_LED2(0);
}


 /*********函数功能：物体颜色判别************/
 

u8 TCS230_Distinguish2(void)
{
	u16 r=0,b=0,g=0,i=0;
	TCS32_LED2(1);delay_ms(100);
	for(i=0;i<10;i++)
	{
		r+=TCS230_Read_Num2(Red);
		delay_ms(10);
		b+=TCS230_Read_Num2(Blue);
		delay_ms(10);
		g+=TCS230_Read_Num2(Green);
		delay_ms(10);
	}
	r=r/12;b=b/10;g=g/10;
	TCS32_LED2(0);	
	if(r+g+b>80)
		return 2;//白
	else if(b>=r*2.08)
		return 5;//蓝	
	else if(r>=g*2)
		return 3;//红
	else if(g*1.2>b)
		return 1;//绿	
	else if(r+g+b<=35)
		return 4;//黑	
	else
		return 0;	
}

void color(void)
{
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	Color2_GPIO_Config();
	EXTI2_NVIC_Configuration();
	EXTI_PG2_Config();
	color_Init();
	TCS230_Start2();
	EXTI_PG2_Config_on();
	EXTI_PG2_Config_off();
	USART_Config();
	SysTick_Init();
}


/********************* 颜色识别 ******************************/

/********************* 如果C为绿色 ***********************************/
void green(void)
{
	back_lukou(2);													//后退过了两个路口，回到米字路口
	delay_s(2);                             //在米字路口停下两秒
	L_zhuanwan(2);													//此转弯使用的是灰度 8 
	delay_s(2);                             //转弯后停两秒
	qianjin_lukou1(2);                      //前进两个路口到达 A 检测区
	
	
	/* 检测A处的物块的颜色 */
	while(1)
	{
		if(TCS230_Distinguish2()==3)					//如果 A 处为红色
		{
			qianjin_lukou1(1);									//前进一个路口，到达绿色放置区
			delay_s(1);													//停一秒
			back_lukou(3);											//后退，使得小车回到米字的中央，用的第二排灰度
			R_zhuanwan1(2);											//向右转，此时用的是灰度6
			delay_s(1);   											//停 1 秒
			qianjin_lukou1(3);									//前进3个路口，可以到达红色
			delay_s(1);												  // 停1秒
			back_lukou(3);											//后退3个路口，用的第二排灰度
			R_zhuanwan2(2);											//向右转两个路口，用的灰度9，开始去检测蓝色
			delay_s(1);													//停1秒
			qianjin();													//前进一会，目的是走过米字，避免此处的干扰
			qianjin();
			delay_ms(200);			
			qianjin_lukou1(2);									//前进过两个路口
			delay_s(1);													//停1秒
			back_lukou(3);											//后退3个路口回到米字
			turn_right();                       //向右转，先盲转一会，使它转过当前可能正压着的线
			delay_ms(150);
			R_zhuanwan1(2);											//向右转，用的灰度6，使小车开始向出发区前进
			delay_s(1);
			qianjin_lukou2(4);									//向前走四个路口，此时车屁股还在出发区外面
			qianjin();													//再向前走一点，回到出发区
			delay_ms(300);
			stop();
			break;
		}
	}
}






