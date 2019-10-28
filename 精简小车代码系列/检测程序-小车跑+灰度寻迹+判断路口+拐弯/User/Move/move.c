#include "move.h"
#include "huidu.h"
#include "systick.h"
#include "usart.h"


void yan_shi(void);

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
//左轮
void Leftsudu(u16 L_speed,u16 L_DIR)//第一个参数速度  第二个参数方向
{
	
	TIM_SetCompare4(TIM3,L_speed);
	LUN_LEFT(L_DIR);
}


//右轮
void Rightsudu(u16 R_speed,u16 R_DIR)//第一个参数速度  第二个参数方向
{

	TIM_SetCompare3(TIM3,R_speed);
	LUN_RIGHT(R_DIR);
}

/********************灰度寻迹*****************************/
void xunji(void)
{
if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF && scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF))
	{
		Leftsudu(10,1);
		Rightsudu(0,0);
	}
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


/**********************前进***********************/
void qianjin(void)
{
	Leftsudu(10,1);//输出高电平的时间为10，左轮正转
	Rightsudu(10,0);//输出高电平的时间为10，右轮正转
}	
/***********************左拐********************/
void turn_left(void)
{
	Leftsudu(10,0);//输出高电平的时间为10，左轮反转
	Rightsudu(10,0);//输出高电平的时间为10，右轮正转
}

/***********************右拐*********************/
void turn_right(void)
{
	Leftsudu(10,1);//输出高电平的时间为10，左轮正转
	Rightsudu(10,1);//输出高电平的时间为10，右轮反转
}
/************************停止*************************/
void stop(void)
{
	Leftsudu(0,1);//输出高电平的时间为0
	Rightsudu(0,1);//输出高电平的时间为0
}

/********************** 判断路口 ****************************/
//参数n表示要过的路口数
void lukou (uint8_t n)
{
	uint8_t i=0;
	while(1)
	{
		printf("傻子\n");
//		yan_shi();
		xunji();
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			i++;
			printf("sbhq\n");
			printf("i=%d\n",i);
			delay_ms(200);
//			yan_shi();
			printf("nihao\n");
			while(1)
			{
				xunji();
//				yan_shi();
				printf("你好\n");
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
					break;
			}
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

void yan_shi(void)
{
	uint32_t i = 0;
	for(i=1000000;i>0;i--);
}






