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
#define he 1200
#define kai1 1400 
#define kai 2200
#define v_houtui 220

#define jiaozhun 40
#define qjiaozhun1 20
#define qjiaozhun2 25
#define qjiaozhun3 30
#define qjiaozhun4 35
#define qjiaozhun5 40

#define dingxin 100

#define tha 100
#define thb 100
#define thc 100
#define thd 100
#define the 100

#define tfa 100
#define tfb 100
#define tfc 100
#define tfd 100
#define tfe 100


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
	TCS32_LED2(1);
	delay_ms(100);
	for(i=0;i<10;i++)
	{
		r+=TCS230_Read_Num2(Red);
		delay_ms(10);
		b+=TCS230_Read_Num2(Blue);
		delay_ms(10);
		g+=TCS230_Read_Num2(Green);
		delay_ms(10);
	}
	printf("\n red:%d,blue:%d,green:%d\n ",r,b,g);	

	r/=13;
	b/=11;
	g/=9;
	TCS32_LED2(0);	
		
	if(r+g+b>170)
		return 2;//白
	else if(b>=r*1.2)
		return 5;//蓝	
	else if(r>=g*2.5) 
		return 3;//红
	else if(g>b*1.1)
		return 1;//绿	
	else if(r+g+b<=53)
		return 4;//黑	
	else 
		return 0;;
	}



void color_a(void)
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
	
	qianjin();
	delay_ms(200);

	zhuaqu_huidu();	
	h_houtuidelay(houtui);
	delay_s(1);
	
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
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
	delay_ms(200);

	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void a_f(int zhuazi,int houtui)//?a?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(1);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void c_g(int zhuazi,int houtui)//?c?g
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);

	mangzou_guolukou();
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
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
	delay_ms(200);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void c_c1(int zhuazi,int houtui)//?c?c1
{
	if(houtui != 0)
		houtui_delay(houtui);

	//turn180();
	//delay_s(1);

	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);

	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void e_h(int zhuazi,int houtui)//?e?h
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void e_f(int zhuazi,int houtui)//?e?h
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void e_e1(int zhuazi,int houtui)//?e?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	qianjin();
	delay_ms(200);

	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);

	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void e_a1(int zhuazi,int houtui)//?e?a1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	mangzou_guolukou();
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

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
	delay_ms(200);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void f_e1(int zhuazi,int houtui)//?f?e1
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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void f_a1(int zhuazi,int houtui)//?f?e1
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
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	h_houtuidelay(houtui);
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void f_e(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void f_a(int zhuazi,int houtui)//?f?e1
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void e1_a(int zhuazi,int houtui)//?e1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void a1_e(int zhuazi,int houtui)//?a1?e
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void a1_g(int zhuazi,int houtui)//?a1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void b1_f(int zhuazi,int houtui)//?b1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void b1_g(int zhuazi,int houtui)//?b1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(1);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void b1_a(int zhuazi,int houtui)//?b1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(3);
	delay_s(1);
	qianjin();
	
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void b1_e(int zhuazi,int houtui)//?b1?e
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void c1_f(int zhuazi,int houtui)//?c1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void c1_e(int zhuazi,int houtui)//?c1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void c1_g(int zhuazi,int houtui)//?c1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void c1_a(int zhuazi,int houtui)//?c1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void d1_f(int zhuazi,int houtui)//?d1?f
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);

	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void d1_e(int zhuazi,int houtui)//?d1?f
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(3);
	delay_s(1);

	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void d1_g(int zhuazi,int houtui)//?d1?g
 {
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(1);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void d1_a(int zhuazi,int houtui)//?d1?a
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);
	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);		
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}
void e1_g(int zhuazi,int houtui)//?d1?g
{
	if(houtui != 0)
		houtui_delay(houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);

	L_zhuanwan(2);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);

}

void h1_a1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(3);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	//h_houtuidelay(tha);
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
//	houtui();
//	delay_ms(300);
//	turn_180();
//	qianjin_lukou(1);
//	qianjin();
//	delay_ms(200);
//	mangzou_guolukou();
	
	
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void h1_b1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(2);
	delay_s(1);

	qianjin();
	delay_ms(200);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
	
}

void h1_c1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);

	qianjin();
	delay_ms(200);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void h1_d1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void h1_e1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);

	qianjin();
	delay_ms(200);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void a1_h1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	R_zhuanwan1(3);
	delay_s(1);

	qianjin_lukou2(1);	
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
	
}

void b1_h1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	R_zhuanwan1(2);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void c1_h1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	R_zhuanwan1(1);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void d1_h1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	
	S1down();//套筒下降
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void e1_h1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);
	
	qianjin();
	delay_ms(200);
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}


void f1_a1(int zhuazi,int houtui)
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
	
	//S1riseup();//套筒升起
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
	//h_houtuidelay(tfa);
	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)		
//	S1down();//套筒下降
//	TIM_SetCompare1(GENERAL_TIM5,he);	//（爪子再次夹紧）
//	S1riseup();//套筒上升
//	
//	qianjin();
//	delay_ms(200);
//	
//	zhuaqu_huidu();
//	delay_s(1);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//（爪子开一点）
//	S1down();//爪子下降
//	TIM_SetCompare1(GENERAL_TIM5,he);//（爪子合紧）
//	
//	h_houtuidelay(houtui);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void f1_b1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	mangzou_guolukou();
	delay_s(1);
	
	//S1riseup();//套筒升起
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();	
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
//	h_houtuidelay(tfb);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//(爪子开一点)		
//	S1down();//套筒下降
//	TIM_SetCompare1(GENERAL_TIM5,he);//（爪子再次夹紧）
//	S1riseup();//套筒上升
//	
//	qianjin();
//	delay_ms(200);
//	
//	zhuaqu_huidu();
//	delay_s(1);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//（爪子开一点）
//	S1down();//爪子下降
//	TIM_SetCompare1(GENERAL_TIM5,he);	//（爪子合紧）

//	h_houtuidelay(houtui);

	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void f1_c1(int zhuazi,int houtui)
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
	
	//S1riseup();//套筒升起
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
//	h_houtuidelay(tfc);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//(爪子开一点)		
//	S1down();//套筒下降
//	TIM_SetCompare1(GENERAL_TIM5,he);//（爪子再次夹紧）
//	S1riseup();//套筒上升
	
//	qianjin();
//	delay_ms(200);
//	
//	zhuaqu_huidu();
//	delay_s(1);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//（爪子开一点）
//	S1down();//爪子下降
//	TIM_SetCompare1(GENERAL_TIM5,he);//（爪子合紧）	
//	
//	h_houtuidelay(houtui);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void f1_d1(int zhuazi,int houtui)
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
	
	//S1riseup();//套筒升起
	qianjin_lukou2(1);
	qianjin();
	delay_ms(200);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
//	h_houtuidelay(tfd);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//(爪子开一点)		
//	S1down();//套筒下降
//	TIM_SetCompare1(GENERAL_TIM5,he);	//（爪子再次夹紧）
//	S1riseup();//套筒上升
	
//	qianjin();
//	delay_ms(200);
//	
//	zhuaqu_huidu();
//	delay_s(1);
	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//（爪子开一点）	
//	S1down();//爪子下降
//	TIM_SetCompare1(GENERAL_TIM5,he);	//（爪子合紧）	

//	h_houtuidelay(houtui);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void f1_e1(int zhuazi,int houtui)
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
	
	//S1riseup();//套筒升起
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai1);	//(爪子开一点)
	delay_ms(500);
	S1riseup();//套筒升起
	delay_ms(200);
	
//	h_houtuidelay(tfe);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//(爪子开一点)		
//	S1down();//套筒下降
//	TIM_SetCompare1(GENERAL_TIM5,he);//（爪子再次夹紧）
//	S1riseup();//套筒上升
//	
//	qianjin();
//	delay_ms(200);
	
//	zhuaqu_huidu();
//	delay_s(1);
//	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);//（爪子开一点）
//	S1down();//爪子下降
//	delay_s(1);
//	TIM_SetCompare1(GENERAL_TIM5,he);	//（爪子合紧）
//	delay_s(1);	
//	
//	h_houtuidelay(dingxin);
//	delay_s(1);
	
//	TIM_SetCompare1(GENERAL_TIM5,kai1);
//	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
	delay_s(1);
}

void a1_f1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();	
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void b1_f1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	
	S1down();//套筒下降
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();	
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void c1_f1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void d1_f1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	L_zhuanwan(2);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}

void e1_f1(int zhuazi,int houtui)
{
	if(houtui != 0)
		houtui_delay(houtui);
	
	turn_180();
	delay_s(1);
	
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	S1down();//套筒下降
	delay_s(1);
	
	L_zhuanwan(3);
	delay_s(1);
	
	qianjin_lukou2(1);
	zhuaqu_huidu();	
	delay_s(1);
	
	if(zhuazi != 0)
		TIM_SetCompare1(GENERAL_TIM5,zhuazi);
}


void a1_m(void)//?a1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(2);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);

}

void b1_m(void)//?b1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);

}

void c1_m(void)//?c1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai);

}

void d1_m(void)//?d1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);

}

void e1_m(void)//?d1???
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	qianjin_lukou2(1);
	
	qianjin();
	delay_ms(200);
	
	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(2);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);

}
void a_m(void)
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(2);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);
}
void b_m(void)
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	mangzou_guolukou();
	delay_s(1);
	
	R_zhuanwan1(1);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);
}
void c_m(void)
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);
	mangzou_guolukou();
	delay_s(1);
	
	TIM_SetCompare1(GENERAL_TIM5,kai);
}
void d_m(void)
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(1);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);
}
void e_m(void)
{
	houtui_delay(v_houtui);

	turn_180();
	delay_s(1);

	mangzou_guolukou();
	delay_s(1);
	
	L_zhuanwan(2);
	delay_s(1);

	TIM_SetCompare1(GENERAL_TIM5,kai);
}
void f1_zhua_a(void)
{
		TIM_SetCompare1(GENERAL_TIM5,kai);
		delay_ms(500);
		qianjin();
		delay_ms(100);
		stop();
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
		TIM_SetCompare4(GENERAL_TIM4,2300);
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1900);//上面的舵机程?
		houtui();
		delay_ms(500);
		stop();
	
		TIM_SetCompare4(GENERAL_TIM4,2250);
		delay_ms(50);
		TIM_SetCompare4(GENERAL_TIM4,2200);
		delay_ms(50);
		TIM_SetCompare4(GENERAL_TIM4,2150);
		delay_ms(50);
		TIM_SetCompare4(GENERAL_TIM4,2100);
		delay_ms(50);
		TIM_SetCompare4(GENERAL_TIM4,2050);
		delay_ms(50);
		TIM_SetCompare4(GENERAL_TIM4,2000);//下面的舵机程序
		delay_ms(500);
		
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		qianjin();
		delay_ms(300);
		stop();
		TIM_SetCompare1(GENERAL_TIM5,he);
		qianjin();
		zhuaqu_huidu2();
}
void f1_zhua_b(void)
{
		TIM_SetCompare1(GENERAL_TIM5,kai);
		delay_ms(500);
		qianjin();
		delay_ms(200);
		stop();
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
		TIM_SetCompare4(GENERAL_TIM4,2100);
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1900);//上面的舵机程?
		houtui();
		delay_ms(500);
		stop();
	
		TIM_SetCompare3(GENERAL_TIM4,1920);//上面的舵机程
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1940);//上面的舵机程
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1960);//上面的舵机程
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1980);//上面的舵机程
		delay_ms(500);
		TIM_SetCompare4(GENERAL_TIM4,2000);//下面的舵机程序
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		delay_ms(500);
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
		qianjin();
		delay_ms(350);
		TIM_SetCompare1(GENERAL_TIM5,he);
		qianjin();
		zhuaqu_huidu2();
}
void f1_zhua_c(void)
{
		TIM_SetCompare1(GENERAL_TIM5,kai);
		delay_ms(500);
	
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
		qianjin();
	
		delay_ms(450);
		stop();

		TIM_SetCompare4(GENERAL_TIM4,1900);//xia
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1900);//上面的舵机程?
		houtui();
		delay_ms(500);
		stop();
		TIM_SetCompare4(GENERAL_TIM4,2000);//下面的舵机程序
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		qianjin();
		delay_ms(280);
		stop();
		TIM_SetCompare1(GENERAL_TIM5,he);
		delay_ms(200);
		houtui();
		delay_ms(500);
		zhuaqu_huidu2();
}
void f1_zhua_d(void)
{
		TIM_SetCompare1(GENERAL_TIM5,kai);
		delay_ms(500);
		qianjin();
		delay_ms(500);
		stop();
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
	
		TIM_SetCompare4(GENERAL_TIM4,2100);//xia
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1900);//上面的舵机程?
		houtui();
		delay_ms(500);
		stop();	
	
		TIM_SetCompare4(GENERAL_TIM4,2000);//下面的舵机程序
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		stop();
		delay_ms(200);
		qianjin();
		delay_ms(350);
		TIM_SetCompare1(GENERAL_TIM5,he);
		houtui();
		delay_ms(500);
		zhuaqu_huidu2();
}
void f1_zhua_e(void)
{
		TIM_SetCompare1(GENERAL_TIM5,kai);
		delay_ms(500);
		qianjin();
		delay_ms(200);
		stop();
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);
	
	
		TIM_SetCompare4(GENERAL_TIM4,2400);//xia
		delay_ms(500);
		TIM_SetCompare3(GENERAL_TIM4,1900);//上面的舵机程?
		houtui();
		delay_ms(500);
		stop();
	
	
			TIM_SetCompare4(GENERAL_TIM4,2350);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2300);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2250);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2200);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2150);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2100);
			delay_ms(50);
			TIM_SetCompare4(GENERAL_TIM4,2000);
			delay_ms(500);
	
	
	
		TIM_SetCompare3(GENERAL_TIM4,1300);//上面的舵机程序
		delay_ms(500);
		
		TIM_SetCompare4(GENERAL_TIM4,2499);//下面的舵机程序
		delay_ms(500);

		qianjin();
		delay_ms(400);
		stop();
		TIM_SetCompare1(GENERAL_TIM5,he);
		qianjin();
		zhuaqu_huidu2();
}
int color1(void)
{
	int c1 = 0;
	
	 while(1)
	{
		c1 = TCS230_Distinguish2();
		if (c1 == 1||c1 == 2||c1 == 3||c1 == 4||c1 == 5)
			return c1;
	}
}

int color2(void)
{
	int c2 = 0;
	while(1)
	{
		c2 = TCS230_Distinguish2();
		if (c2 == 1||c2 == 2||c2 == 3||c2 == 4||c2 == 5)
			return c2;
	}
}

int color3(void)
{
	int c3 = 0;
	while(1)
	{
		c3 = TCS230_Distinguish2();
		if (c3 == 1||c3 == 2||c3 == 3||c3 == 4||c3 == 5)
			return c3;
	}
}

int color(void)
{
	int c = 0;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	while(1)
	{
		c1 = color1();
		
		delay_ms(500);
		c2 = color2();
		delay_ms(500);
		c3 = color3();
		delay_ms(500);
		
		if(c1==c2&&c2==c3)
		{
			c = c1;
			return c;
		}
}
	
}
//////////////////////////////////////////////////////////////////////
void re1(void)
{
	int c = 0;
	
	delay_s(1);
	c_c1(kai,0);
	delay_s(1);
	c1_a(he,1);
	delay_s(1);
	c = color();
	
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
	}
	/////////////////////////////////////////////////
	else if (c == wh)
	{
		a_b1(kai,0);
		b1_e(he,1);
		c =color(); 

		if(c == bu)
			{
				e_e1(kai,0);
				e1_m();
			}
		
		else if(c == gr)
			{
				e_a1(kai,0);
				a1_m();
			}
		
		else if(c == bl)
			{
				e_d1(kai,0);
				d1_m();
			}
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
	}

}
void wh1(void)
{
	int c = 0;

	c_b1(kai,0);
	b1_a(he,1);
	c = color();
	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_g(kai,0);
		g_e(he,1);
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
	}
}

void gr1(void)
{
	int c = 0;

	c_g(kai,0);
	g_a(he,1);
	c = color();
	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_f(kai,0);
		f_e(he,1);
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
				e1_g(he,1);
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
	}
}
void bu1(void)
{
	
	int c = 0;

	c_g(kai,0);
	g_e(he,1);
	c = color();
		
		/////////////////////////////////////////////////
	if (c == gr)
	{
		e_f(kai,0);
		f_a(he,1);
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
			a_d1(kai,0);
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
	}


}
void bl1(void)
{
	int c = 0;

	c_d1(kai,0);
	d1_a(he,1);
	c = color();

	/////////////////////////////////////////////////
	if (c == bu)
	{
		a_g(kai,0);
		g_e(he,1);
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
				e_b1(kai,0);
				b1_g(he,1);
				g_e1(kai,0);
				e1_m();
			}
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
		else if(c == wh)
			{
				e_b1(kai,0);
				b1_m();
			}
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
	}
}

void h_zhuaqvpanduan(void)
{
	int c = 0;
	c=color();
	
	if(c==3)  //红色 
	{
		h1_c1(kai,0);
		c1_h1(kai,1);
	}
  if(c==1)  //绿色
	{
		h1_a1(kai,0);
		a1_h1(kai,1);
	}
	if(c==5)  //蓝色 
	{
		h1_e1(kai,0);
		e1_h1(kai,1);
	}
	if(c==4)  //黑色
	{
		h1_d1(kai,0);
		d1_h1(kai,1);
	}
	if(c==2)  //白色 
	{
		h1_b1(kai,0);
		b1_h1(kai,1);
	}
}



void h_f1_zhuaqvpanduan(void)
{
	int c = 0;
	c=color();
	
	if(c==3)  //红色 
	{
		h1_c1(kai,0);
		c1_f1(kai,1);
	}
  if(c==1)  //绿色
	{
		h1_a1(kai,0);
		a1_f1(kai,1);		
	}
	if(c==5)  //蓝色 
	{
		h1_e1(kai,0);
		e1_f1(kai,1);
	}
	if(c==4)  //黑色
	{
		h1_d1(kai,0);
		d1_f1(kai,1);
	}
	if(c==2)  //白色 
	{
		h1_b1(kai,0);
		b1_f1(kai,1);
	}
}

void f_zhuaqvpanduan(void)
{
	int c = 0;
	c=color();
	
	if(c==3)  //红色 
	{
		f1_c1(kai,0);
		c1_f1(kai,1);
	}
  if(c==1)  //绿色
	{
		f1_a1(kai,0);
		a1_f1(kai,1);
	}
	if(c==5)  //蓝色 
	{
		f1_e1(kai,0);
		e1_f1(kai,1);
	}
	if(c==4)  //黑色
	{
		f1_d1(kai,0);
		d1_f1(kai,1);
	}
	if(c==2)  //白色 
	{
		f1_b1(kai,0);
		b1_f1(kai,1);
	}
}


void f_m_zhuaqvpanduan(void)
{
	int c = 0;
	c=color();
	
	if(c==3)  //红色 
	{
		f1_c1(kai,0);
		c1_m();
	}
  if(c==1)  //绿色
	{
		f1_a1(kai,0);
		a1_m();
	}
	if(c==5)  //蓝色 
	{
		f1_e1(kai,0);
		e1_m();
	}
	if(c==4)  //黑色
	{
		f1_d1(kai,0);
		d1_m();
	}
	if(c==2)  //白色 
	{
		f1_b1(kai,0);
		b1_m();
	}
}

/***************** 任务1 ********************/
void renwu1(void)
{
	int c =0;
	delay_s(1);
	c = color();
	switch (c)
	{
		case re : re1(); break;
		case gr : gr1(); break;
		case bu : bu1(); break;
		case bl : bl1(); break;
		case wh : wh1(); break;
	}

}
/***************** END **********************/


/***************** 任务2 ********************/
void renwu2_h(void)
{
	/*按照朱高磊的5个物块抓取顺序A-B-E-C-D*/
	
	//(舵机抓取B物块的函数)
	f1_zhua_a();
	h_zhuaqvpanduan();
	
	//舵机抓取A物块的函数
	f1_zhua_b();
	h_zhuaqvpanduan();
	
	//(舵机抓取E物块的函数)
	f1_zhua_e();
	h_zhuaqvpanduan();

	//(舵机抓取C物块的函数)
	f1_zhua_c();
	h_zhuaqvpanduan();
	
	//(舵机抓取D物块的函数)
	f1_zhua_d();	
	h_f1_zhuaqvpanduan();//到达了第二个五色区
}

void renwu2_f(void)
{
	//因为赛道的对称性，所以F区的抓取顺序为B-A-C-E-D对应1中的A-B-E-C-D


	//(舵机抓取A物块的函数)
	f1_zhua_a();
	f_zhuaqvpanduan();
	
	//(舵机抓取B物块的函数)
	f1_zhua_b();
	f_zhuaqvpanduan();
	
	//(舵机抓取e物块的函数)
	f1_zhua_e();
	f_zhuaqvpanduan();
	
	//(舵机抓取c物块的函数)
	f1_zhua_c();
	f_zhuaqvpanduan();
	
	//(舵机抓取D物块的函数)
	f1_zhua_d();
	f_m_zhuaqvpanduan();//到达了米字路口中心
	
}

/******************** END ***********************/







