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
	if((scan (HUI10_GPIO_PORT,HUI10_GPIO_PIN) == OFF && scan (HUI11_GPIO_PORT,HUI11_GPIO_PIN) == OFF) &&\
		(scan (HUI12_GPIO_PORT,HUI12_GPIO_PIN) == ON || scan (HUI13_GPIO_PORT,HUI13_GPIO_PIN) == ON))
	{
		Leftsudu(0,0);
		Rightsudu(250,1);
	}
		/* ���Һ�ƫ */	
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

/*********************ǰ���ж�·���м���*********************/
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


/***********************�����ж�·��1 �Ҷ�7*************************/
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


/**********************�����ж�·��2 �Ҷ�8**************************/
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


/**********************����ת��****************************/
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

/********************** ����ת��1 ****************************/
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


/********************* ����ת��2 *************************/
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

/******************** �ж�·�ڣ������Ҷȣ� **************************/
void lukou_3(uint8_t m)
{
	uint8_t i=0,j=0,k=0,n=0;								//i�Ǽ�¼��һ���Ҷ�·�ڣ�j�Ǽ�¼�ڶ����Ҷ�·�ڣ�k�Ǽ�¼�������Ҷ�·�ڣ�n�Ǽ�¼��·����
	qianjin();
	while(1)																//����ѭ����ʼ��¼·��
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
		if(n>=m)					//����ﵽ�趨��·����
			break;
	}
}
					/*�����������Ľ��ͣ�
					    if����ֻ��ִ��һ�Σ���Ĳ���Ϊ1������Ҷ�9����
							��1���Ҷ�9�ټ���һ��·�ڣ���ôj��k�����ɼ�·�ڣ��Գ�����Ӱ�� 
							��2���Ҷ�9�����һ��·�ڣ������ڴ˳��򣬶��һ��·��ֻ�п����ǻҶ�9���˶������ж��������·�ڣ�
																					��ôj,kû��ʾ����if��������
							�˳����ȱ�㣺ֻ�ܽ��һ���ҶȻ��˵����
											�ŵ㣺������������϶����·�ڵ��������Ϊ�趨�Ĳ���ʼ��Ϊ1
														����ʵս���֣�����·���м�Ŀռ���ȫ�ݵ���3���Ҷ�

					ע���˳������·�ڽ�����ͣ�ڵ�λ��Ӧ���ǹ��˻Ҷ�11��λ��
										����ʵ�о���������û�н�������ڵ����и��İɣ�*/









