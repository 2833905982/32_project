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


//左0右1
/*********************左轮******************************/
void Leftsudu(u16 L_speed,u16 L_DIR)														//第一个参数速度10    第二个参数方向
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
	
	while(1)
	{
			//前进
				Leftsudu(10,1);
				Rightsudu(10,0);
			
			
			/* 向左偏 */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON ))
			{
				Leftsudu(10,0);												
				Rightsudu(0,0);
			}
			
			/* 向右偏 */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON )&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF))
			{
				Leftsudu(0,1);
				Rightsudu(10,1);
			}
			
			
			/* 检测路口 */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON )&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON))
			{
				Leftsudu(0,1);
				Rightsudu(0,1);
				break;
			}

   }

}



/**********************前进***********************/
void qianjin(u16 time)
{
	//前进
	Leftsudu(10,1);		 //输出高电平的时间为10，左轮正转
	Rightsudu(10,0);   //输出高电平的时间为10，右轮正转
	
	delay_ms (time);
	
	//停
	Leftsudu(0,1);		 //输出高电平的时间为10，左轮正转
	Rightsudu(0,0);   //输出高电平的时间为10，右轮正转
}	

///*********************后退************************/
//void houtui(void)
//{
//	Leftsudu(10,0);
//	Rightsudu(10,1);
//}


/***********************盲拐——左拐********************/
void turn_left(u16 time)
{
	Leftsudu(10,1);														//输出高电平的时间为10，左轮反转
	Rightsudu(10,1);													//输出高电平的时间为10，右轮正转
	
	delay_ms (time);
	
	//停
	Leftsudu(0,1);		 //输出高电平的时间为10，左轮正转
	Rightsudu(0,0);   //输出高电平的时间为10，右轮正转
}

/***********************盲拐——右拐*********************/
void turn_right(u16 time)
{
	Leftsudu(10,0);														//输出高电平的时间为10，左轮正转
	Rightsudu(10,0);													//输出高电平的时间为10，右轮反转
	
	delay_ms (time);
	
	//停
	Leftsudu(0,1);		 //输出高电平的时间为10，左轮正转
	Rightsudu(0,0);   //输出高电平的时间为10，右轮正转
}


///************************停止*************************/
//void stop(void)
//{
//	Leftsudu(0,1);														//输出高电平的时间为0
//	Rightsudu(0,1);														//输出高电平的时间为0
//}

///**********************前进判断路口 ****************************/
////参数n表示要过的路口数
//void qianjin_lukou (uint8_t n)
//{
//	uint8_t i=0;
//	qianjin();
//	delay_ms(300);
//	while(1)
//	{
//		qianjin_xunji();
//		if(scan (HUIP1_GPIO_PORT,HUIP1_GPIO_PIN) == ON)
//		{
//			i++;

////			while(1)
////			{
////				xunji();
////				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
//			if(i>=n)
//			{
//				i=0;
//				stop();
//				//delay_s(2);
//				break;
//			}
//			delay_ms(200);
//		}
//		
//	}
//}

////void qianjin_lukou2 (uint8_t n)
////{
////	uint8_t d=0;
////	while(1)
////	{
////		qianjin_xunji();
////		if(scan (HUIZ1_GPIO_PORT,HUIZ1_GPIO_PIN) == ON)
////		{
////			d++;
////			delay_ms(200);
//////			while(1)
//////			{
//////				xunji();
//////				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
//////				{
//////					break;
//////				}
//////			}
////		}
////		if(d>=n)
////		{
////			d=0;
////			stop();
////			delay_s(2);
////			break;
////		}
////	}
////}
///***********************后退判断路口*************************前期代码，这两种方法应该能变成一种*/
////第一种
//void back_lukou(uint8_t m)															//左边第一个灰度判断路口
//{
//	uint8_t j=0;
//	while(1)
//	{
//		back_xunji();
//		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
//		{
//			j++;
//			
////			while(1)
////			{
////				xunji();
////				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		}
//		if(j>=m)
//		{
//			j=0;
//			stop();
//			//delay_s(2);
//			break;
//		}
//			delay_ms(200);
//	}
//}
////第二种
//}
////void back_lukou2(uint8_t m)																		//侧左边灰度判断
////{
////	uint8_t x=0;
////	while(1)
////	{
////		back_xunji();
////		if(scan (HUICZ_GPIO_PORT,HUICZ_GPIO_PIN) == ON)
////		{
////			x++;
////			
//////			while(1)
//////			{
//////				xunji();
//////				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
//////				{
//////					break;
//////				}
//////			}
//////		}
////		if(x>=m)
////		{
////			x=0;
////			stop();
////			delay_s(2);
////			break;
////		}
////					delay_ms(200);
////	}
////}


///**********************向左转弯****************************/
//void L_zhuanwan(uint8_t m)
//{
//	uint8_t a = 0;
//	while(1)
//	{
//		turn_left();
////		delay_ms(300);
//		if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)
//		{
//			a++;
//		if(a>=m)
//		{
//			delay_ms(50);
//			a = 0;
//			stop();
//			break;
//		}	
//		delay_ms(200);
//			while(1)
//			{
//				if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}		
//	  }
//  }
//}
////void L_zhuanwan1(uint8_t m)
////{
////	uint8_t w = 0;
////	while(1)
////	{
////		turn_left();
//////		delay_ms(300);
////		if(scan (HUIZ3_GPIO_PORT,HUIZ3_GPIO_PIN) == ON)
////		{
////			w++;
////			
////			while(1)
////			{
////				if(scan (HUIZ3_GPIO_PORT,HUIZ3_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		
////		if(w>=m)
////		{
////			delay_ms(150);
////			w = 0;
////			stop();
////			break;
////		}	
////			delay_ms(200);		
////	}
////}
////	}
////void L_zhuanwan2(uint8_t m)
////{
////	uint8_t y = 0;
////	while(1)
////	{
////		turn_left();
//////		delay_ms(300);
////		if(scan (HUIY1_GPIO_PORT,HUIY1_GPIO_PIN) == ON)
////		{
////			y++;
////			
////			while(1)
////			{
////				if(scan (HUIY1_GPIO_PORT,HUIY1_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		
////		if(y>=m)
////		{
////			y = 0;
////			stop();
////			break;
////		}	
////			delay_ms(200);		
////	}
////}
////	}
///********************** 向右转弯 ****************************/
////void R_zhuanwan(uint8_t k)
////{
////	uint8_t b = 0;
////	while(1)
////	{
////		turn_right();
////		if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)
////		{
////			b++;
////			
////			while(1)
////			{
////				if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		
////		if(b>=k)
////		{
////			b = 0;
////			stop();
////			break;
////		}	
////			delay_ms(200);		
////	}
////}
////}

//void R_zhuanwan(uint8_t k)
//{
//	uint8_t b = 0;
//	while(1)
//	{
//		turn_right();
//////		delay_ms(300);
//		if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)
//		{
//			b++;
//			if(b>=k)
//			{
//				b = 0;
//				delay_ms(50);
//				stop();
//				break;
//			}	
//			delay_ms(200);
//			while(1)
//			{
//				if(scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}		
//	  }
//  }
//}
////void R_zhuanwan1(uint8_t k)																//左边第二个灰度检测
////{
////	uint8_t c = 0;
////	while(1)
////	{
////		turn_right();
////		if(scan (HUIZ3_GPIO_PORT,HUIZ3_GPIO_PIN) == ON)
////		{
////			c++;
////			
////			while(1)
////			{
////				if(scan (HUIZ3_GPIO_PORT,HUIZ3_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		
////		if(c>=k)
////		{
////			c = 0;
////			stop();
////			break;
////		}		
////					delay_ms(200);
////	}
////}
////}
////void R_zhuanwan2(uint8_t k)																//左边第二个灰度检测
////{
////	uint8_t z = 0;
////	while(1)
////	{
////		turn_right();
////		if(scan (HUIY1_GPIO_PORT,HUIY1_GPIO_PIN) == ON)
////		{
////			z++;
////			
////			while(1)
////			{
////				if(scan (HUIY1_GPIO_PORT,HUIY1_GPIO_PIN) == OFF)
////				{
////					break;
////				}
////			}
////		
////		if(z>=k)
////		{ 
////			z = 0;
////			stop();
////			break;
////		}		
////					delay_ms(200);
////	}
////}
////}
////void R_zhuanwan2(uint8_t k)
////{
////uint8_t e = 0;
////while(1)
////{
////	turn_right();
////	if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
////	{
////		e++;
////		delay_ms(100);
////		while(1)
////		{
////			if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
////			{
////				break;
////			}
////		}
////	}
////	if(e>=k)
////	{
////		stop();
////		break;
////	}		
////}
////}


////向后忙跑一定距离
////void houtui(unit8_t)
////{
////	
////}


void chufa(void)
{
	qianjin_xunji();
	qianjin(300);
	qianjin_xunji();
	qianjin(300);
	qianjin_xunji();
	qianjin(500);
	delay_ms(300);
}
