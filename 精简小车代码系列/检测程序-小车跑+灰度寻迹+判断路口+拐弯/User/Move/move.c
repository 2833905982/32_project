#include "move.h"
#include "huidu.h"
#include "systick.h"
#include "usart.h"


void yan_shi(void);

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
//����
void Leftsudu(u16 L_speed,u16 L_DIR)//��һ�������ٶ�  �ڶ�����������
{
	
	TIM_SetCompare4(TIM3,L_speed);
	LUN_LEFT(L_DIR);
}


//����
void Rightsudu(u16 R_speed,u16 R_DIR)//��һ�������ٶ�  �ڶ�����������
{

	TIM_SetCompare3(TIM3,R_speed);
	LUN_RIGHT(R_DIR);
}

/********************�Ҷ�Ѱ��*****************************/
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


/**********************ǰ��***********************/
void qianjin(void)
{
	Leftsudu(10,1);//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(10,0);//����ߵ�ƽ��ʱ��Ϊ10��������ת
}	
/***********************���********************/
void turn_left(void)
{
	Leftsudu(10,0);//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
	Rightsudu(10,0);//����ߵ�ƽ��ʱ��Ϊ10��������ת
}

/***********************�ҹ�*********************/
void turn_right(void)
{
	Leftsudu(10,1);//����ߵ�ƽ��ʱ��Ϊ10��������ת
	Rightsudu(10,1);//����ߵ�ƽ��ʱ��Ϊ10�����ַ�ת
}
/************************ֹͣ*************************/
void stop(void)
{
	Leftsudu(0,1);//����ߵ�ƽ��ʱ��Ϊ0
	Rightsudu(0,1);//����ߵ�ƽ��ʱ��Ϊ0
}

/********************** �ж�·�� ****************************/
//����n��ʾҪ����·����
void lukou (uint8_t n)
{
	uint8_t i=0;
	while(1)
	{
		printf("ɵ��\n");
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
				printf("���\n");
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






