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
/*********************����******************************/
void Leftsudu(u16 L_speed,u16 L_DIR)														//��һ�������ٶ�  �ڶ�����������
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
	/* ����ƫ */
	if((scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON || scan (HUI3_GPIO_PORT,HUI3_GPIO_PIN) == ON)&&\
		(scan (HUI4_GPIO_PORT,HUI4_GPIO_PIN) == OFF && scan (HUI5_GPIO_PORT,HUI5_GPIO_PIN) == OFF))
	{
		Leftsudu(250,1);												
		Rightsudu(0,0);
	}
	/* ����ƫ */
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


/**********************ǰ��***********************/
void qianjin(void)
{
	Leftsudu(250,1);														//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(250,0);													//����ߵ�ƽ��ʱ��Ϊ10��������ת
}	

/******************** ������ʱ��ǰ�� **********************/
void qianjin_time(uint16_t time)
{
	Leftsudu(250,1);
	Rightsudu(250,0);
	delay_ms(time);
}

/*********************����************************/
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
/***********************���********************/
void turn_left(void)
{
	Leftsudu(250,1);														//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
	Rightsudu(250,1);													//����ߵ�ƽ��ʱ��Ϊ10��������ת
}

/***********************�ҹ�*********************/
void turn_right(void)
{
	Leftsudu(250,0);														//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(250,0);													//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
}
/************************ֹͣ*************************/
void stop(void)
{
	Leftsudu(0,1);														//����ߵ�ƽ��ʱ��Ϊ0
	Rightsudu(0,1);														//����ߵ�ƽ��ʱ��Ϊ0
}


//����n��ʾҪ����·����
/*********************ǰ���ж�·��*********************/
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



/**********************����ת��****************************/
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

///********************** ����ת��1 ****************************/
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

/********************** ����ת��1 ****************************/
void R_zhuanwan1(uint8_t k)
{
	if(k == 1)
	{
		//����äת 45 ��
		turn_right();
		delay_ms(335);
	  stop();		
	}
	else if(k == 2)
	{
		//����äת 90 ��
		turn_right();
		delay_ms(670);
	  stop();		
	}
	else if(k == 3)
	{
		//����äת 135 ��
		turn_right();
		delay_ms(1005);
	  stop();				
	}
}





///****************** ת180 *********************/
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
/****************äת 180 ��**********************/
void turn_180()
{
	turn_left();
	delay_ms(1350);
	stop();
}

/***************************ץȡ�Ҷ�*********************************/
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
/**************************ä�߹�����·��*****************************/
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
