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

/********************* 后退寻迹 ******************************/
void back_xunji(void)
{
		/* 向左后偏 */
	if((scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF && scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == OFF) &&\
		(scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == ON || scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == ON))
	{
		Leftsudu(0,0);
		Rightsudu(250,1);
	}
		/* 向右后偏 */	
	if((scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON || scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == ON) &&\
		(scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == OFF && scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == OFF))
	{
		Leftsudu(250,0);
		Rightsudu(0,1);
	}
	
	if(scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF && scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == OFF &&\
		scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == OFF && scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == OFF)
	{
		Leftsudu(250,0);
		Rightsudu(250,1);
	}
	if((scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON || scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == ON) &&\
		(scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == OFF || scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == OFF))
	{
		Leftsudu(250,0);
		Rightsudu(250,1);
	}
}


/**********************前进***********************/
void qianjin(void)
{
	Leftsudu(250,1);														//输出高电平的时间为10，左轮正转
	Rightsudu(250,0);													//输出高电平的时间为10，右轮正转
}	

/*********************后退************************/
void houtui(void)
{
	Leftsudu(250,0);
	Rightsudu(250,1);
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

/**********************前进判断路口前排 ****************************/
//参数n表示要过的路口数
void qianjin_lukou1 (uint8_t n)
{
	uint8_t i=0;
	qianjin();
	delay_ms(200);
	while(1)
	{
		qianjin_xunji();
		if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON)
		{
			i++;
			if(i>=n)
			{
				i=0;
				stop();
				delay_s(2);
				break;
			}
			delay_ms(200);
			while(1)
			{
				qianjin_xunji();
				if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}

/*********************前进判断路口中间排*********************/
void qianjin_lukou2(uint8_t n)
{
	uint8_t i=0;
	qianjin();
	delay_ms(200);
	while(1)
	{
		qianjin_xunji();
		
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			i++;
			if(i>=n)
			{
				i=0;
				stop();
				delay_s(2);
				break;
			}
			delay_ms(200);
			while(1)
			{
				qianjin();
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}


/***********************后退判断路口1 灰度7*************************/
void back_lukou1(uint8_t m)
{
	uint8_t j=0;
	while(1)
	{
		back_xunji();
	 	if(scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == ON)
		{
			j++;
			if(j>=m)
			{
				j=0;
				stop();
				delay_s(1);
				break;
			}
			delay_ms(200);
			while(1)
			{
				houtui();
				if(scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == OFF)
					break;

			}
		}
		
	}
}


/**********************后退判断路口2 灰度8**************************/
void back_lukou2(uint8_t m)
{
	uint8_t j=0;
	while(1)
	{
		back_xunji();
	 	if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			j++;
			if(j>=m)
			{
				j=0;
				stop();
				delay_s(2);
				break;
			}
			delay_ms(100);
			while(1)
			{
				houtui();
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
					break;

			}
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
		//delay_ms(60);
		if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON)
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
				if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}

/********************** 向右转弯1 ****************************/
void R_zhuanwan1(uint8_t k)
{
	uint8_t b = 0;
	while(1)
	{
		turn_right();
		//delay_ms(60);
		if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON)
		{
			b++;
			if(b>=k)
			{
				stop();
				break;
			}		
			delay_ms(100);
			while(1)
			{
				if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}


/********************* 向右转弯2 *************************/
void R_zhuanwan2(uint8_t k)
{
	uint8_t b = 0;
	while(1)
	{
		turn_right();
		//delay_ms(60);
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			b++;
			if(b>=k)
			{
				stop();
				break;
			}		
			delay_ms(100);
			while(1)
			{
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}

/******************** 判断路口（三个灰度） **************************/
void lukou_3(uint8_t m)
{
	uint8_t i=0,j=0,k=0,n=0;								//i是记录第一个灰度路口，j是记录第二个灰度路口，k是记录第三个灰度路口，n是记录总路口数
	qianjin();
	while(1)																//进入循环开始记录路口
	{
			qianjin_xunji();
			if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON)
				i=1;
			if(scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON)
				j=1;
			if(scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == ON)
				k=1;
			if((i+j+k)==2 || (i+j+k)==3 )
			{
				n++;
				while(1)
				{
					qianjin_xunji();
					delay_ms(200);
				}
			}			
		if(n>=m)					//如果达到设定的路口数
			break;
	}
}
					/*关于这个程序的解释：
					    if成立只会执行一次，令传的参数为1，如果灰度9坏了
							（1）灰度9少计了一个路口：那么j，k会依旧记路口，对程序无影响 
							（2）灰度9多记了一个路口：（对于此程序，多记一个路口只有可能是灰度9在运动过程中抖动多记了路口）
																					那么j,k没有示数，if不成立）
							此程序的缺点：只能解决一个灰度坏了的情况
											优点：不会出现在线上多记了路口的情况，因为设定的参数始终为1
														经过实战发现，米字路口中间的空间完全容得下3个灰度

					注：此程序计数路口结束后停在的位置应该是过了灰度11的位置
										（其实感觉还有问题没有解决，就在调试中更改吧）*/









