
#include "bsp_GeneralTim.h" 


int Servo_move(TIM_TypeDef* TIMx,uint8_t CCRx,u16 intend_angle,u32 us)//���������ֱ�Ϊ�����ʹ�õĶ�ʱ��/ͨ��/��Ҫ����ĽǶ�/�ӳ�us�����
{
	if(intend_angle>2500)//���ܳ������ڵ�ֵ
		intend_angle=2500;
	int last_angle=0;
	switch(CCRx)
	{
		case 1:
			last_angle=TIM_GetCapture1(TIMx);
				if (last_angle<=intend_angle)
				{
					while(last_angle<intend_angle)
						{
							TIM_SetCompare1(TIMx,last_angle++);
							delay_us(us);
						}
						TIM_SetCompare1(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
				}
				else if (last_angle>=intend_angle)
				{
					while(last_angle>intend_angle)
						{
							TIM_SetCompare1(TIMx,last_angle--);
							delay_us(us);
						}
						TIM_SetCompare1(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
				}
			break;
		case 2:
			last_angle=TIM_GetCapture2(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare2(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare2(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare2(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare2(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			break;
		case 3:
			last_angle=TIM_GetCapture3(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare3(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare3(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare3(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare3(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			break;
		case 4:
			last_angle=TIM_GetCapture4(TIMx);
		if (last_angle<=intend_angle)
			{
				while(last_angle<intend_angle)
					{
						TIM_SetCompare4(TIMx,last_angle++);
						delay_us(us);
					}
					TIM_SetCompare4(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			else if (last_angle>=intend_angle)
			{
				while(last_angle>intend_angle)
					{
						TIM_SetCompare4(TIMx,last_angle--);
						delay_us(us);
					}
					TIM_SetCompare4(TIMx,intend_angle);//�ٴ�ȷ��д���˸ýǶ�
			}
			break;
		default:
			return -1;//�������
	}

		return 1;//ok
}


void GENERAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
		/*-------------------------------------TIM3  GPIO��ʼ��----------------------------------------------------*/

//  // ����Ƚ�ͨ��1 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH1_GPIO_CLK, ENABLE);
////  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH1_PORT, &GPIO_InitStructure);
	
//	// ����Ƚ�ͨ��2 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH2_PORT, &GPIO_InitStructure);
	
//	// ����Ƚ�ͨ��3 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH3_PORT, &GPIO_InitStructure);
//	
//	// ����Ƚ�ͨ��4 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM3_CH4_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM3_CH4_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM3_CH4_PORT, &GPIO_InitStructure);
	
	/*-------------------------------------TIM4  GPIO��ʼ��----------------------------------------------------*/
	// ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH1_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH2_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH2_PORT, &GPIO_InitStructure);
	
	
	
//	/*-------------------------------------TIM5  GPIO��ʼ��----------------------------------------------------*/
//	// ����Ƚ�ͨ��1 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH1_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH1_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH1_PORT, &GPIO_InitStructure);
//	
//	// ����Ƚ�ͨ��2 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH2_PORT, &GPIO_InitStructure);
//	
//	// ����Ƚ�ͨ��3 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH3_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH3_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH3_PORT, &GPIO_InitStructure);
//	
//	// ����Ƚ�ͨ��4 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH4_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH4_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM5_CH4_PORT, &GPIO_InitStructure);
}


///*
// * ע�⣺TIM_TimeBaseInitTypeDef�ṹ��������5����Ա��TIM6��TIM7�ļĴ�������ֻ��
// * TIM_Prescaler��TIM_Period������ʹ��TIM6��TIM7��ʱ��ֻ���ʼ����������Ա���ɣ�
// * ����������Ա��ͨ�ö�ʱ���͸߼���ʱ������.
// *-----------------------------------------------------------------------------
// *typedef struct
// *{ TIM_Prescaler            ����
// *	TIM_CounterMode			     TIMx,x[6,7]û�У���������
// *  TIM_Period               ����
// *  TIM_ClockDivision        TIMx,x[6,7]û�У���������
// *  TIM_RepetitionCounter    TIMx,x[1,8,15,16,17]����
// *}TIM_TimeBaseInitTypeDef; 
// *-----------------------------------------------------------------------------
// */

/* ----------------   PWM�ź� ���ں�ռ�ձȵļ���--------------- */
// ARR ���Զ���װ�ؼĴ�����ֵ
// CLK_cnt����������ʱ�ӣ����� Fck_int / (psc+1) = 72M/(psc+1)
// PWM �źŵ����� T = ARR * (1/CLK_cnt) = ARR*(PSC+1) / 72M
// ռ�ձ�P=CCR/(ARR+1)

void GENERAL_TIM_Mode_Config(void)
{
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
//	//TIM3ʱ��
//	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM3_CLK,ENABLE);
	//TIM4ʱ��
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM4_CLK,ENABLE);
//	//TIM5ʱ��
//	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM5_CLK,ENABLE);
	

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM3, &TIM_TimeBaseStructure);
	TIM_TimeBaseInit(GENERAL_TIM5, &TIM_TimeBaseStructure);

//	/*--------------------����ȽϽṹ���ʼ����TIM3��-------------------*/	
//	// ռ�ձ�����
//	uint16_t CCR1_Val_3 = 0;
//	uint16_t CCR2_Val_3 = 0;
////	uint16_t CCR3_Val_3 = 0;
////	uint16_t CCR4_Val_3 = 0;
//	
//	TIM_OCInitTypeDef  TIM_OCInitStructure3;//TIM_OCInitStruct
//	// ����ΪPWMģʽ1
//	TIM_OCInitStructure3.TIM_OCMode = TIM_OCMode_PWM1;
//	// ���ʹ��
//	TIM_OCInitStructure3.TIM_OutputState = TIM_OutputState_Enable;
//	// ���ͨ����ƽ��������	
//	TIM_OCInitStructure3.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	// ����Ƚ�ͨ�� 1
//	TIM_OCInitStructure3.TIM_Pulse = CCR1_Val_3;
//	TIM_OC1Init(GENERAL_TIM3, &TIM_OCInitStructure3);
//	TIM_OC1PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
//	
//	// ����Ƚ�ͨ�� 2
//	TIM_OCInitStructure3.TIM_Pulse = CCR2_Val_3;
//	TIM_OC2Init(GENERAL_TIM3, &TIM_OCInitStructure3);
//	TIM_OC2PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
//	
////	// ����Ƚ�ͨ�� 3
////	TIM_OCInitStructure3.TIM_Pulse = CCR3_Val_3;
////	TIM_OC1Init(GENERAL_TIM3, &TIM_OCInitStructure3);
////	TIM_OC1PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
////	
////	// ����Ƚ�ͨ�� 4
////	TIM_OCInitStructure3.TIM_Pulse = CCR4_Val_3;
////	TIM_OC2Init(GENERAL_TIM3, &TIM_OCInitStructure3);
////	TIM_OC2PreloadConfig(GENERAL_TIM3, TIM_OCPreload_Enable);
	

//	
//	//		/*--------------------����ȽϽṹ���ʼ����TIM5��-------------------*/	
//	// ռ�ձ�����
//	uint16_t CCR1_Val_5 = 0;
//	uint16_t CCR2_Val_5 = 0;
//	uint16_t CCR3_Val_5 = 0;
//	uint16_t CCR4_Val_5 = 0;
//	
//	TIM_OCInitTypeDef  TIM_OCInitStructure5;
//	// ����ΪPWMģʽ1
//	TIM_OCInitStructure5.TIM_OCMode = TIM_OCMode_PWM1;
//	// ���ʹ��
//	TIM_OCInitStructure5.TIM_OutputState = TIM_OutputState_Enable;
//	// ���ͨ����ƽ��������	
//	TIM_OCInitStructure5.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	// ����Ƚ�ͨ�� 1
//	TIM_OCInitStructure5.TIM_Pulse = CCR1_Val_5;
//	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// ����Ƚ�ͨ�� 2
//	TIM_OCInitStructure5.TIM_Pulse = CCR2_Val_5;
//	TIM_OC2Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC2PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// ����Ƚ�ͨ�� 3
//	TIM_OCInitStructure5.TIM_Pulse = CCR3_Val_5;
//	TIM_OC3Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC3PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
//	
//	// ����Ƚ�ͨ�� 4
//	TIM_OCInitStructure5.TIM_Pulse = CCR4_Val_5;
//	TIM_OC4Init(GENERAL_TIM5, &TIM_OCInitStructure5);
//	TIM_OC4PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	

	

	
	/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	

	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM_Period_Run;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM_Prescaler_Run;	
	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM4, &TIM_TimeBaseStructure);
	/*-----------------------------------------------------------*/
	
	

/*--------------------����ȽϽṹ���ʼ����TIM4��-------------------*/	
	// ռ�ձ�����
	uint16_t CCR1_Val_4 = 0;
	uint16_t CCR2_Val_4 = 0;
	
	
	TIM_OCInitTypeDef  TIM_OCInitStructure2;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure2.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure2.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure2.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure2.TIM_Pulse = CCR1_Val_4;
	TIM_OC1Init(GENERAL_TIM4, &TIM_OCInitStructure2);
	TIM_OC1PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 2
	TIM_OCInitStructure2.TIM_Pulse = CCR2_Val_4;
	TIM_OC2Init(GENERAL_TIM4, &TIM_OCInitStructure2);
	TIM_OC2PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	
	
	
	
/*----------------------------------------------------------------------------------------------------------*/	
	// ʹ�ܼ�����
	TIM_Cmd(GENERAL_TIM3, ENABLE);
	TIM_Cmd(GENERAL_TIM4, ENABLE);
	TIM_Cmd(GENERAL_TIM5, ENABLE);
	
	
	
	
	
}

void LED_GPIO_Config(void)/*LDE��ʾ�Ƴ�ʼ��*/
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
	
	
	/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_ZUO_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_ZUO2_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		
		
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU1_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
		
		
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( LUN_YOU_GPIO_CLK , ENABLE);
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LUN_YOU2_GPIO_PIN;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LUN_GPIO_PORT, &GPIO_InitStructure);	
}


//����������
void sudu(u16 left,u16 right,u16 Fangxiang1,u16 Fangxiang2,u16 Fangxiang3,u16 Fangxiang4)//ǰ�����������ҵ���ٶ�  ��������������
{
	
	TIM_SetCompare2(TIM4,left);
	TIM_SetCompare1(TIM4,right);
	LUN_ZUO1(Fangxiang1);
	LUN_ZUO2(Fangxiang2);
	LUN_YOU1(Fangxiang3);
	LUN_YOU2(Fangxiang4);
}



//ת��
int ZhuanPan(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,1,intend_angle,us);
}

//1�Ŷ��
int DuoJi1(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,2,intend_angle,us);
}

//2�Ŷ��
int DuoJi2(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,3,intend_angle,us);
}

//3�Ŷ��
int DuoJi3(u16 intend_angle,u32 us)
{
	Servo_move(TIM5,4,intend_angle,us);
}

//צ��
int ZhaZi(u16 intend_angle,u32 us)
{
	Servo_move(TIM3,1,intend_angle,us);
}


/*********************************************END OF FILE**********************/
