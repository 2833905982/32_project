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

/********************* ����Ѱ�� ******************************/
void back_xunji(void)
{
		/* �����ƫ */
	if((scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF && scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == OFF && scan (HUI14_GPIO_PORT,HUI14_GPIO_PIN) == OFF) &&\
		(scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON || scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == ON || scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == ON))
	{
		Leftsudu(250,0);
		Rightsudu(0,1);
	}
		/* ���Һ�ƫ */	
	if((scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON || scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == ON || scan (HUI14_GPIO_PORT,HUI14_GPIO_PIN) == ON) &&\
		(scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF && scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == OFF && scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == OFF))
	{
		Leftsudu(0,0);
		Rightsudu(250,1);
	}
	
	if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF && scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == OFF && scan (HUI14_GPIO_PORT,HUI14_GPIO_PIN) == OFF &&\
		scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF && scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == OFF && scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == OFF)
	{
		Leftsudu(250,0);
		Rightsudu(250,1);
	}
	if((scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON || scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == ON || scan (HUI14_GPIO_PORT,HUI14_GPIO_PIN) == ON) && \
		(scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == ON || scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == ON || scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == ON))
	{
		Leftsudu(250,0);
		Rightsudu(250,1);
	}
}


/**********************ǰ��***********************/
void qianjin(void)
{
	Leftsudu(250,1);														//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(250,0);													//����ߵ�ƽ��ʱ��Ϊ10��������ת
}	

/*********************����************************/
void houtui(void)
{
	Leftsudu(250,0);
	Rightsudu(250,1);
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

/**********************ǰ���ж�·��ǰ�� ****************************/
//����n��ʾҪ����·����
void qianjin_lukou1 (uint8_t n)
{
	uint8_t i=0;
	while(1)
	{
		qianjin_xunji();
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			i++;
			delay_ms(150);
			while(1)
			{
				qianjin_xunji();
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
				{
					break;
				}
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

/*********************ǰ���ж�·���м���*********************/
void qianjin_lukou2(uint8_t n)
{
	uint8_t i=0;
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
			delay_ms(150);
			while(1)
			{
				qianjin_xunji();
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
				{
					break;
				}
			}
		}
	}
}


/***********************�����ж�·��*************************/
void back_lukou(uint8_t m)
{
	uint8_t j=0;
	while(1)
	{
		houtui();
		if(j>=m)
		{
			j=0;
			stop();
			delay_s(2);
			break;
		}
	 	if(scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == ON)
		{
			j++;
			delay_ms(180);
//			while(1)
//			{
//				xunji();
//				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
//				{
//					break;
//				}
//			}
		}
		
	}
}


/**********************����ת��****************************/
void L_zhuanwan(uint8_t m)
{
	uint8_t a = 0;
	while(1)
	{
		turn_left();
		delay_ms(60);
		if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == ON)
		{
			a++;
			delay_ms(100);
			while(1)
			{
				if(scan (HUI8_GPIO_PORT,HUI8_GPIO_PIN) == OFF)
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

/********************** ����ת��1 ****************************/
void R_zhuanwan1(uint8_t k)
{
	uint8_t b = 0;
	while(1)
	{
		turn_right();
		delay_ms(60);
		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON)
		{
			b++;
			delay_ms(100);
			while(1)
			{
				if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF)
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


/********************* ����ת��2 *************************/
void R_zhuanwan2(uint8_t k)
{
	uint8_t b = 0;
	while(1)
	{
		turn_right();
		delay_ms(60);
		if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == ON)
		{
			b++;
			delay_ms(100);
			while(1)
			{
				if(scan (HUI9_GPIO_PORT,HUI9_GPIO_PIN) == OFF)
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



