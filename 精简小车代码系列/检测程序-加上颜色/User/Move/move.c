#include "move.h"
#include "huidu.h"
#include "systick.h"
#include "usart.h"



//轮子方向gpio定义
void W_GPIO_Config(void)
{
	/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_LEFT_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_LEFT_GPIO_PIN;	
		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		/*开启LED相关的GPIO外设时钟*/
		RCC_APB2PeriphClockCmd( LUN_RIGHT_GPIO_CLK, ENABLE);
		/*选择要控制的GPIO引脚*/
		GPIO_InitStructure.GPIO_Pin = LUN_RIGHT_GPIO_PIN;	
		/*调用库函数，初始化GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
}
/*********************左轮******************************/
void Leftsudu(u16 L_speed,u16 L_DIR)														//第一个参数速度  第二个参数方向
{
	
	TIM_SetCompare4(TIM3,L_speed);
	LUN_LEFT(L_DIR);
}


/**********************右轮**********************************/
void Rightsudu(u16 R_speed,u16 R_DIR)														//第一个参数速度  第二个参数方向
{

	TIM_SetCompare3(TIM3,R_speed);
	LUN_RIGHT(R_DIR);
}

/********************前进灰度寻迹*****************************/
void qianjin_xunji(void)
{
	/* 向右偏 */
	if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF && scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF))
	{
		Leftsudu(10,1);												
		Rightsudu(0,0);
	}
	/* 向左偏 */
	if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON || scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON))
	{
		Leftsudu(0,1);
		Rightsudu(10,0);
	}
	if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && \
		scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF && scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF)
	{
		Leftsudu(10,1);
		Rightsudu(10,0);
	}
	if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON) && \
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON || scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON))
	{
		Leftsudu(10,1);
		Rightsudu(10,0);
	}

}

/********************* 后退寻迹 ******************************/
void back_xunji(void)
{
		/* 向右后偏 */
	if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF && scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON)
	{
		Leftsudu(0,0);
		Rightsudu(10,1);
	}
		/* 向左后偏 */	
	if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON && scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF)
	{
		Leftsudu(10,0);
		Rightsudu(0,1);
	}
	if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON && scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON)
	{
		Leftsudu(10,0);
		Rightsudu(10,1);
	}
	if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF && scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF)
	{
		Leftsudu(10,0);
		Rightsudu(10,1);
	}
}


/**********************前进***********************/
void qianjin(void)
{
	Leftsudu(10,1);														//输出高电平的时间为10，左轮正转
	Rightsudu(10,0);													//输出高电平的时间为10，右轮正转
}	

/*********************后退************************/
void houtui(void)
{
	Leftsudu(10,0);
	Rightsudu(10,1);
}
/***********************左拐********************/
void turn_left(void)
{
	Leftsudu(10,1);														//输出高电平的时间为10，左轮反转
	Rightsudu(10,1);													//输出高电平的时间为10，右轮正转
}

/***********************右拐*********************/
void turn_right(void)
{
	Leftsudu(10,0);														//输出高电平的时间为10，左轮正转
	Rightsudu(10,0);													//输出高电平的时间为10，右轮反转
}
/************************停止*************************/
void stop(void)
{
	Leftsudu(0,1);														//输出高电平的时间为0
	Rightsudu(0,1);														//输出高电平的时间为0
}

/**********************前进判断路口 ****************************/
//参数n表示要过的路口数
void qianjin_lukou (uint8_t n)
{
	uint8_t i=0;
	while(1)
	{
		qianjin_xunji();
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			i++;
			delay_ms(200);
//			while(1)
//			{
//				xunji();
//				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}
		}
		if(i>=n)
		{
			i=0;
			stop();
			delay_s(2);
			break;
		}
	}
}

/***********************后退判断路口*************************/
void back_lukou(uint8_t m)
{
	uint8_t j=0;
	while(1)
	{
		back_xunji();
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			j++;
			delay_ms(200);
//			while(1)
//			{
//				xunji();
//				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}
		}
		if(j>=m)
		{
			j=0;
			stop();
			delay_s(2);
			break;
		}
	}
}


/**********************向左转弯****************************/
void L_zhuanwan(uint8_t m)
{
	uint8_t a = 0;
	while(1)
	{
		turn_left();
//		delay_ms(300);
		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
		{
			a++;
			delay_ms(100);
			while(1)
			{
				if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
		if(a>=m)
		{
			stop();
			break;
		}		
	}
}

/********************** 向右转弯 ****************************/
void R_zhuanwan(uint8_t k)
{
	uint8_t b;
	while(1)
	{
		turn_right();
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			b++;
			delay_ms(100);
			while(1)
			{
				if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
		if(b>=k)
		{
			stop();
			break;
		}		
	}
}




