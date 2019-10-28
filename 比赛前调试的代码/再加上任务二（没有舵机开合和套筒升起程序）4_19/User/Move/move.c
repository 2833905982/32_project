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
	if((scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF))
	{
		Leftsudu(250,1);												
		Rightsudu(0,0);
	}
	/* 向左偏 */
	if((scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON ))
	{		
		Leftsudu(0,1);
		Rightsudu(250,0);
	}
	if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF && \
		scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF)
	{
		Leftsudu(250,1);
		Rightsudu(250,0);
	}
	if((scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON) && \
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON))
	{
		Leftsudu(250,1);
		Rightsudu(250,0);
	}

}


/**********************前进***********************/
void qianjin(void)
{
	Leftsudu(250,1);														//输出高电平的时间为10，左轮正转
	Rightsudu(250,0);													//输出高电平的时间为10，右轮正转
}	

/******************** 带有延时的前进 **********************/
void qianjin_time(uint16_t time)
{
	Leftsudu(250,1);
	Rightsudu(250,0);
	delay_ms(time);
}

/*********************后退************************/
void houtui(void)
{
	Leftsudu(250,0);
	Rightsudu(250,1);
}
void houtui_delay(int t)
{
	houtui();
	delay_ms(220);
}
/***********************左拐********************/
void turn_left(void)
{
	Leftsudu(250,1);														//输出高电平的时间为10，左轮反转
	Rightsudu(250,1);													//输出高电平的时间为10，右轮正转
}

/***********************右拐*********************/
void turn_right(void)
{
	Leftsudu(250,0);														//输出高电平的时间为10，左轮正转
	Rightsudu(250,0);													//输出高电平的时间为10，右轮反转
}
/************************停止*************************/
void stop(void)
{
	Leftsudu(0,1);														//输出高电平的时间为0
	Rightsudu(0,1);														//输出高电平的时间为0
}


//参数n表示要过的路口数
/*********************前进判断路口*********************/
void qianjin_lukou2(uint8_t n)
{
	uint8_t i=0;
	qianjin();
	delay_ms(250);
	while(1)
	{
		qianjin_xunji();
		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
		{
			i++;
			printf("%d",i);
			if(i>=n)
			{
				i=0;
				stop();
				//delay_s(2);
				break;
			}
			delay_ms(200);
			while(1)
			{
				qianjin();
				if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}



/**********************向左转弯****************************/
void L_zhuanwan(uint8_t m)
{
	uint8_t a = 0;
	turn_left();
	delay_ms(200);
	while(1)
	{
		turn_left();
		//delay_ms(60);
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			a++;
			if(a>=m)
			{
				stop();
				break;
			}		
			delay_ms(100);
			while(1)
			{
				if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}

///********************** 向右转弯1 ****************************/
//void R_zhuanwan1(uint8_t k)
//{
//	uint8_t b = 0;
//	turn_right();
//	delay_ms(200);
//	while(1)
//	{
//		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
//		{
//			b++;
//			if(b>=k)
//			{
//				stop();
//				break;
//			}		
//			delay_ms(100);
//			while(1)
//			{
//				if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}
//		}
//	}
//}

/********************** 向右转弯1 ****************************/
void R_zhuanwan1(uint8_t k)
{
	if(k == 1)
	{
		//向右盲转 45 度
		turn_right();
		delay_ms(335);
	  stop();		
	}
	else if(k == 2)
	{
		//向右盲转 90 度
		turn_right();
		delay_ms(670);
	  stop();		
	}
	else if(k == 3)
	{
		//向右盲转 135 度
		turn_right();
		delay_ms(1005);
	  stop();				
	}
}





///****************** 转180 *********************/
//void turn_180(void)
//{
//	while(1)
//	{
//		turn_left();
//		//delay_ms(60);
//		if(scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON)
//		{
//			while(1)
//			{
//				turn_left();
//				if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)
//				{
//					stop();
//					break;
//				}
//			}
//			break;
//		}
//	}
//}
/****************盲转 180 度**********************/
void turn_180()
{
	turn_left();
	delay_ms(1350);
	stop();
}

/***************************抓取灰度*********************************/
void zhuaqu_huidu(void)
{
	qianjin();
	delay_ms(200);
	while(1)
	{
		qianjin_xunji();
		if(scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == ON)
		{
			stop();
			break;
		}
	}
}
/**************************盲走过米字路口*****************************/
void mangzou_guolukou(void)
{
	qianjin();
	delay_ms(200);
	while(1)
	{
		qianjin_xunji();
			if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
			{
				uint32_t i=0,j=0;
				
				for(i=200;i>0;i--)
				{
					for(j=155;j>0;j--)
					{
						qianjin_xunji();
					}
				}
				stop();
				break;
			}
	}
}
