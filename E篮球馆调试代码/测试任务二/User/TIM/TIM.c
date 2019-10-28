#include "TIM.h"
#include "systick.h"
uint16_t i=0;
uint16_t j=0;

#define tongxia 1800
#define tongshang 680


static void GENERAL_TIM4_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH1_PORT, &GPIO_InitStructure);
	
//	// ����Ƚ�ͨ��2 GPIO ��ʼ��
//	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH2_GPIO_CLK, ENABLE);
//  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH2_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GENERAL_TIM4_CH2_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH3_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH3_PORT, &GPIO_InitStructure);
	
	// ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM4_CH4_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM4_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM4_CH4_PORT, &GPIO_InitStructure);
	
		/*-------------------------------------TIM5  GPIO��ʼ��----------------------------------------------------*/
	// ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(GENERAL_TIM5_CH1_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENERAL_TIM5_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GENERAL_TIM5_CH1_PORT, &GPIO_InitStructure);
	
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

static void GENERAL_TIM4_Mode_Config(void)
{
  // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM4_CLK,ENABLE);
		//TIM5ʱ��
	GENERAL_TIM_APBxClock_FUN(GENERAL_TIM5_CLK,ENABLE);

/*--------------------ʱ���ṹ���ʼ��-------------------------*/
	// �������ڣ���������Ϊ100K
	
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=GENERAL_TIM4_Period;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= GENERAL_TIM4_Prescaler;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(GENERAL_TIM4, &TIM_TimeBaseStructure);
		TIM_TimeBaseInit(GENERAL_TIM5, &TIM_TimeBaseStructure);

	/*--------------------����ȽϽṹ���ʼ��-------------------*/	
	// ռ�ձ�����
	uint16_t CCR1_Val = 0;
//	uint16_t CCR2_Val = 0;
	uint16_t CCR3_Val = 0;
	uint16_t CCR4_Val = 0;
	
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	TIM_OC1Init(GENERAL_TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
//	
//	// ����Ƚ�ͨ�� 2
//	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
//	TIM_OC2Init(GENERAL_TIM4, &TIM_OCInitStructure);
//	TIM_OC2PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 3
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	TIM_OC3Init(GENERAL_TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
	// ����Ƚ�ͨ�� 4
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	TIM_OC4Init(GENERAL_TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(GENERAL_TIM4, TIM_OCPreload_Enable);
	
		// ռ�ձ�����
	uint16_t CCR1_Val_5 = 0;
	
	TIM_OCInitTypeDef  TIM_OCInitStructure5;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure5.TIM_OCMode = TIM_OCMode_PWM1;
	// ���ʹ��
	TIM_OCInitStructure5.TIM_OutputState = TIM_OutputState_Enable;
	// ���ͨ����ƽ��������	
	TIM_OCInitStructure5.TIM_OCPolarity = TIM_OCPolarity_High;
	
	// ����Ƚ�ͨ�� 1
	TIM_OCInitStructure5.TIM_Pulse = CCR1_Val_5;
	TIM_OC1Init(GENERAL_TIM5, &TIM_OCInitStructure5);
	TIM_OC1PreloadConfig(GENERAL_TIM5, TIM_OCPreload_Enable);
	
	// ʹ�ܼ�����
	TIM_Cmd(GENERAL_TIM4, ENABLE);
		TIM_Cmd(GENERAL_TIM5, ENABLE);
}

void GENERAL_TIM4_Init(void)
{
	GENERAL_TIM4_GPIO_Config();
	GENERAL_TIM4_Mode_Config();		
}
/*****************************S1������Ͳ********************************/
void S1riseup(void)																										//��ֵ499��ĩֵ1499
{
//	TIM_SetCompare1(GENERAL_TIM4,1499);
//	 delay_ms(500);
	for(i = tongxia;i >= tongshang;i--)
	{	
		TIM_SetCompare1(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);
	}
}	
/**************************S1�½���Ͳ***********************************/
void S1down(void)
{
//	TIM_SetCompare1(GENERAL_TIM4,499);
//	delay_ms(500);
	for(i = tongshang;i <= tongxia;i++)
	{	
		TIM_SetCompare1(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);
	}
}
///**************************S2����Ͳ***********************************/
//void S2open(void)
//{
//	TIM_SetCompare2(GENERAL_TIM4,2499);
//	 delay_ms(500);
//	for(i = 2499;i >= 499;i--)
//	{	
//		TIM_SetCompare2(GENERAL_TIM4,i);//��Ӧ180��
//		delay_us(2000);
//	}
//}
///**************************S2�ر���Ͳ***********************************/
//void S2close(void)
//{
//	TIM_SetCompare2(GENERAL_TIM4,2499);
//	 delay_ms(500);
//	for(i = 2499;i >= 499;i--)
//	{	
//		TIM_SetCompare2(GENERAL_TIM4,i);//��Ӧ180��
//		delay_us(2000);
//	}
//}
/**************************S3���¿���***********************************/
void S3updown(uint16_t j,uint16_t b)									//��һ��������ǰλ�ã��ڶ���������Ҫ���Ƶ���λ��
{
	if(j > b)
 {
	TIM_SetCompare3(GENERAL_TIM4,j);
	 delay_ms(500);
	for(i = j;i >= b;i--)
	{	
		TIM_SetCompare3(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);																		  //������ʱ�ο��ƶ��ת������
	}
 }
 	if(j < b)
 {
	TIM_SetCompare3(GENERAL_TIM4,j);
	 delay_ms(500);
	for(i = j;i <= b;i++)
	{	
		TIM_SetCompare3(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);
	}
 }
 
}
/***************************S4���ҿ���*************************************/
void S4leftright(uint16_t k,uint16_t a)								//��һ��������ǰλ�ã��ڶ���������Ҫ���Ƶ���λ��
{
	if(k > a)
 {
	TIM_SetCompare4(GENERAL_TIM4,k);
	 delay_ms(500);
	for(i = k;i >= a;i--)
	{	
		TIM_SetCompare4(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);
	}
 }
 if(k < a)
 {
	 	TIM_SetCompare4(GENERAL_TIM4,k);
	 delay_ms(500);
	for(i = k;i <= a;i++)
	{	
		TIM_SetCompare4(GENERAL_TIM4,i);//��Ӧ180��
		delay_us(2000);
	}
 }
}

