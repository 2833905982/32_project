#include "move.h"
#include "huidu.h"
#include "systick.h"
#include "usart.h"



//���ӷ���gpio����
void W_GPIO_Config(void)
{
	/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_LEFT_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_LEFT_GPIO_PIN;	
		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_RIGHT_GPIO_CLK, ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_RIGHT_GPIO_PIN;	
		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
}


//��0��1
/*********************����******************************/
void Leftsudu(u16 L_speed,u16 L_DIR)														//��һ�������ٶ�10    �ڶ�����������
{
	
	TIM_SetCompare4(TIM3,L_speed);
	LUN_LEFT(L_DIR);
}


/**********************����**********************************/
void Rightsudu(u16 R_speed,u16 R_DIR)														//��һ�������ٶ�  �ڶ�����������
{

	TIM_SetCompare3(TIM3,R_speed);
	LUN_RIGHT(R_DIR);
}

/********************ǰ���Ҷ�Ѱ��*****************************/
void qianjin_xunji(void)
{
	
	while(1)
	{
			//ǰ��
				Leftsudu(10,1);
				Rightsudu(10,0);
			
			
			/* ����ƫ */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON || scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON ))
			{
				Leftsudu(10,0);												
				Rightsudu(0,0);
			}
			
			/* ����ƫ */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON )&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF))
			{
				Leftsudu(0,1);
				Rightsudu(10,1);
			}
			
			
			/* ���·�� */
			if((scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON || scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON )&&\
				(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == ON && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == ON))
			{
				Leftsudu(0,1);
				Rightsudu(0,1);
				break;
			}

   }

}



/**********************ǰ��***********************/
void qianjin(u16 time)
{
	//ǰ��
	Leftsudu(10,1);		 //����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(10,0);   //����ߵ�ƽ��ʱ��Ϊ10��������ת
	
	delay_ms (time);
	
	//ͣ
	Leftsudu(0,1);		 //����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(0,0);   //����ߵ�ƽ��ʱ��Ϊ10��������ת
}	

///*********************����************************/
//void houtui(void)
//{
//	Leftsudu(10,0);
//	Rightsudu(10,1);
//}


/***********************ä�ա������********************/
void turn_left(u16 time)
{
	Leftsudu(10,1);														//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
	Rightsudu(10,1);													//����ߵ�ƽ��ʱ��Ϊ10��������ת
	
	delay_ms (time);
	
	//ͣ
	Leftsudu(0,1);		 //����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(0,0);   //����ߵ�ƽ��ʱ��Ϊ10��������ת
}

/***********************ä�ա����ҹ�*********************/
void turn_right(u16 time)
{
	Leftsudu(10,0);														//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(10,0);													//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
	
	delay_ms (time);
	
	//ͣ
	Leftsudu(0,1);		 //����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(0,0);   //����ߵ�ƽ��ʱ��Ϊ10��������ת
}


///************************ֹͣ*************************/
//void stop(void)
//{
//	Leftsudu(0,1);														//����ߵ�ƽ��ʱ��Ϊ0
//	Rightsudu(0,1);														//����ߵ�ƽ��ʱ��Ϊ0
//}

///**********************ǰ���ж�·�� ****************************/
////����n��ʾҪ����·����
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
///***********************�����ж�·��*************************ǰ�ڴ��룬�����ַ���Ӧ���ܱ��һ��*/
////��һ��
//void back_lukou(uint8_t m)															//��ߵ�һ���Ҷ��ж�·��
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
////�ڶ���
//}
////void back_lukou2(uint8_t m)																		//����߻Ҷ��ж�
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


///**********************����ת��****************************/
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
///********************** ����ת�� ****************************/
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
////void R_zhuanwan1(uint8_t k)																//��ߵڶ����Ҷȼ��
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
////void R_zhuanwan2(uint8_t k)																//��ߵڶ����Ҷȼ��
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


////���æ��һ������
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
