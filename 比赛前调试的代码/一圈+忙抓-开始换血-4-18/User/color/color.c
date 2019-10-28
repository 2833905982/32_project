#include "stm32f10x.h"
#include "color.h"
#include "systick.h"
#include "move.h"
#include "TIM.h"
#include "usart.h"

#define re 3
#define gr 1
#define bu 5
#define bl 4
#define wh 2
#define kai 182
#define he 194
#define v_houtui 220

int n_color = 0;

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

void color1(void)
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


void a_a1(int zhuazi,int houtui)//?a?a1
{
	if(houtui != 0)
		houtui_delay(houtui);

	qianjin_lukou2(1);
	
	delay_s(1);

	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);
	delay_s(1);

}

void a_b1(int zhuazi,int houtui)//?a?b1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);
	
	qianjin();
	delay_ms(80);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void a_c1(int zhuazi,int houtui)//?a?c1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a_d1(int zhuazi,int houtui)//?a?d1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a_f(int zhuazi,int houtui)//?a?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	R_zhuanwan1(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a_g(int zhuazi,int houtui)//?a?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin();
	delay_ms(80);
	
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c_g(int zhuazi,int houtui)//?c?g
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);

	mangzou_guolukou();
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);
}

void c_b1(int zhuazi,int houtui)//?c?b1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);
	qianjin();
	delay_ms(80);
	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c_c1(int zhuazi,int houtui)//?c?c1
{
	if(houtui != 0)
		houtui_delay(houtui);

	//turn180();
	//delay_s(1);

	qianjin();
	delay_ms(200);
	qianjin_lukou2(1);
	delay_s(1);

	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c_d1(int zhuazi,int houtui)//?c?d1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_h(int zhuazi,int houtui)//?e?h
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void e_f(int zhuazi,int houtui)//?e?h
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_b1(int zhuazi,int houtui)//?e?b1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(1);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_c1(int zhuazi,int houtui)//?e?c1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_d1(int zhuazi,int houtui)//?e?d1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_e1(int zhuazi,int houtui)//?e?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	//turn180();
	//delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);

	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e_a1(int zhuazi,int houtui)//?e?a1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	mangzou_guolukou();
	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void g_e1(int zhuazi,int houtui)//?g?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	qianjin_lukou2(2);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void g_a1(int zhuazi,int houtui)//?g?a1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin_lukou2(1);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void g_a(int zhuazi,int houtui)//?g?a
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);
	qianjin();
	delay_ms(80);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void g_e(int zhuazi,int houtui)//?g?e
{
	delay_s(1);
//	if(houtui != 0)
		houtui_delay(v_houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	qianjin();
	delay_ms(200);//8888*********************************************************************************

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void f_e1(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);

	qianjin_lukou2(2);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void f_a1(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(2);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void f_e(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void f_a(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void e1_a(int zhuazi,int houtui)//?e1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin_lukou2(4);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a1_e(int zhuazi,int houtui)//?a1?e
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a1_g(int zhuazi,int houtui)//?a1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin();
	delay_ms(80);
	
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void b1_f(int zhuazi,int houtui)//?b1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void b1_g(int zhuazi,int houtui)//?b1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void b1_a(int zhuazi,int houtui)//?b1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);
	qianjin();
	delay_ms(80);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void b1_e(int zhuazi,int houtui)//?b1?e
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);
	
	qianjin();
	delay_ms(80);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void c1_f(int zhuazi,int houtui)//?c1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c1_e(int zhuazi,int houtui)//?c1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c1_g(int zhuazi,int houtui)//?c1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void c1_a(int zhuazi,int houtui)//?c1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	qianjin();
	delay_ms(200);
	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void d1_f(int zhuazi,int houtui)//?d1?f
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin_lukou2(3);
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void d1_e(int zhuazi,int houtui)//?d1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void d1_g(int zhuazi,int houtui)//?d1?g
  {
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void d1_a(int zhuazi,int houtui)//?d1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);
	qianjin();
	delay_ms(200);
	
	qianjin_lukou2(1);
		
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}
void e1_g(int zhuazi,int houtui)//?d1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin_lukou2(1);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(ADVANCE_TIM,zhuazi);

}

void a1_m()//?a1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(2);
	delay_s(1);

	TIM_SetCompare1(ADVANCE_TIM,kai);

}

void b1_m()//?b1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);

	TIM_SetCompare1(ADVANCE_TIM,kai);

}

void c1_m()//?c1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	TIM_SetCompare1(ADVANCE_TIM,kai);

}

void d1_m()//?d1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);

	TIM_SetCompare1(ADVANCE_TIM,kai);

}

void e1_m()//?d1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(2);
	delay_s(1);

	TIM_SetCompare1(ADVANCE_TIM,kai);

}
int color(void)
{
	int c = 0;
//	if (n_color ==0)
//	{n_color++;return 1;}
//	else if(n_color == 1)
//	{n_color++; return 2;}
//	else if (n_color == 2)
//	{						return 3;}
//	
	
	
	 while(1)
	{
		c = TCS230_Distinguish2();
		if (c == 1||c == 2||c == 3||c == 4||c == 5)
			return c;
	}
}
////////////////////////////////////////////////////////////////////////
void re1(void)
{
	int c = 0;
	while(1){
	
	delay_s(1);
	c_c1(kai,0);
	delay_s(1);
	c1_a(he,1);
	delay_s(1);
	c = color();
	///////////////////////////////////////////
	if (c == bu)
	{
		a_g(kai,0);
		g_e(he,1);
		c = color();
		/////////////////////////
		if(c == gr)
			{
			e_a1(kai,0);
			a1_g(he,1);
			g_e1(kai,0);
			e1_m();
			}
		///////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
		///////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == gr)
	{
		a_a1(kai,0);
		delay_s(1);
		a1_e(he,1);
		delay_s(1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_m();
			}
		////////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_m();
			}
		break;
	}
	/////////////////////////////////////////////////
	else if (c == wh)
	{
		a_b1(kai,0);
		b1_e(he,1);
		c =color(); 

		////////////////////
		if(c == bu)
			{
				e_e1(kai,0);
				e1_m();
			}
		///////////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		/////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_m();
			}
		break;
	}
	//////////////////////////////////////////
	else if (c == bl)
	{
		a_d1(kai,0);
		d1_e(he,1);
		c =color();
		///////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		//////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		//////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_m();
			}
		break;
	}


}//wlile???
}
///////////////////////////////////////////////////////////////////////////
void wh1(void)
{
	int c = 0;
	while(1){

	c_b1(kai,0);
	b1_a(he,1);
	c = color();
	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_g(0,kai);
		g_e(1,he);
		c = color();
		///////////////////////
		if(c == gr)
			{
			e_a1(kai,0);
			a1_g(he,1);
			g_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
		//////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == gr)
	{
		a_a1(kai,0);
		a1_e(he,1);
		c =color(); 
		//////////////////////
			if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_m();
			}
		////////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == re)
	{
		a_c1(kai,0);
		c1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		////////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == bl)
	{
		a_d1(kai,0);
		d1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_m();
			}
		////////////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		break;
	}


	}//while
}

void gr1(void)
{
	int c = 0;
	while(1){

	c_g(kai,0);
	g_a(he,1);
	c = color();
	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_f(0,kai);
		f_e(1,he);
		c = color();
		///////////////////////
		if(c == bl)
			{
				e_d1(kai,0);
				d1_f(he,1);
				f_e1(kai,0);
				e1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_f(he,1);
				f_e1(kai,0);
				e1_g(he,0);
			}
		//////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_f(he,1);
				f_e1(kai,0);
				e1_g(he,0);
			}
		g_a1(kai,0);
		a1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == bl)
	{
		a_d1(kai,0);
		d1_e(he,1);
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_g(he,0);
			}
		////////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_g(he,0);
			}
		g_a1(kai,0);
		a1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == re)
	{
		a_c1(kai,0);
		c1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_g(he,0);
			}
		/////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_g(he,0);
			}
		////////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_g(he,0);
			}
		g_a1(kai,0);
		a1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == wh)
	{
		a_b1(kai,0);
		b1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_g(he,0);
			}
		////////////////////////
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_g(he,0);
			}
		g_a1(kai,0);
		a1_m();
		break;
	}


	}//while
}
void bu1(void)
{
	
	int c = 0;
	while(1){

	c_g(kai,0);
	g_e(he,1);
	c = color();
	/////////////////////////////////////////////////
	if (c == gr)
	{
		e_f(0,kai);
		f_a(1,he);
		c = color();
		///////////////////////
		if(c == bl)
			{
			a_d1(kai,0);
			d1_f(he,1);
			f_a1(kai,0);
			a1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				a_c1(kai,0);
				c1_f(he,1);
				f_a1(kai,0);
				a1_g(he,0);
			}
		//////////////////////
		else if(c == wh)
			{
				a_b1(kai,0);
				b1_f(he,1);
				f_a1(kai,0);
				a1_g(he,0);
			}
		g_e1(kai,0);
		e1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == bl)
	{
		e_d1(kai,0);
		d1_a(he,1);
		c =color(); 
		//////////////////////
		if(c == gr)
			{
			a_a1(kai,0);
			a1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				a_c1(kai,0);
				c1_g(he,0);
			}
		////////////////////////
		else if(c == wh)
			{
				a_b1(kai,0);
				b1_g(he,0);
			}
		g_e1(kai,0);
		e1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == re)
	{
		e_c1(kai,0);
		c1_a(he,1);
		c = color(); 
		//////////////////////
		if(c == gr)
			{
			a_a1(kai,0);
			a1_g(he,0);
			}
		/////////////////////
		else if(c == bl)
			{
				a_d1(kai,0);
				d1_g(he,0);
			}
		////////////////////////
		else if(c == wh)
			{
				a_b1(kai,0);
				b1_g(he,0);
			}
		g_e1(kai,0);
		e1_m();
		break;
	}
	/////////////////////////////////////////////
	else if (c == wh)
	{
		e_b1(kai,0);
		b1_a(he,1);
		c =color(); 
		//////////////////////
		if(c == bl)
			{
			e_d1(kai,0);
			d1_g(he,0);
			}
		/////////////////////
		else if(c == re)
			{
				a_c1(kai,0);
				c1_g(he,0);
			}
		////////////////////////
		else if(c == gr)
			{
				a_a1(kai,0);
				a1_g(he,0);
			}
		g_e1(kai,0);
		e1_m();
		break;
	}


	}//while
}
void bl1(void)
{
	int c = 0;
	while(1){

	c_d1(kai,0);
	d1_a(he,1);
//	c = color();
		c=gr;
	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_g(0,kai);
		g_e(1,he);
		c = color();
		///////////////////////
		if(c == gr)
			{
			e_a1(kai,0);
			a1_g(he,1);
			g_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
		//////////////////////
		else if(c == wh)
			{
				a_b1(kai,0);
				b1_e(he,1);
				e_e1(kai,0);
				e1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == gr)
	{
		a_a1(kai,0);
		a1_e(he,1);
//		c =color();
		c=bu;
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_m();
			}
		////////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == re)
	{
		a_c1(kai,0);
		c1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		////////////////////////
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_m();
			}
		break;
	}
	/////////////////////////////////////////////
	else if (c == wh)
	{
		a_b1(kai,0);
		b1_e(he,1);
		c =color(); 
		//////////////////////
		if(c == bu)
			{
			e_e1(kai,0);
			e1_m();
			}
		/////////////////////
		else if(c == re)
			{
				e_c1(kai,0);
				c1_m();
			}
		////////////////////////
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		break;
	}


	}//while
}

void renwu1(void)
{
	int c =0;
	
	delay_s(1);
	c = color();
	c=bl;
	switch (c)
	{
		case re : re1(); break;
		case gr : gr1(); break;
		case bu : bu1(); break;
		case bl : bl1(); break;
		case wh : wh1(); break;
	}

//	delay_s(1);
//	c_c1(kai,0);
//	delay_s(1);
//	c1_a(he,1);
//	delay_s(10);
}






