#include "TIM.h"

static void TIM_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH1_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH1_PORT, &GPIO_InitStructure);

  // ����Ƚ�ͨ��2 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH2_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH2_PORT, &GPIO_InitStructure);

	 // ����Ƚ�ͨ��3 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH3_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH3_PORT, &GPIO_InitStructure);

  // ����Ƚ�ͨ��4 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(ADVANCE_TIM_CH4_GPIO_CLK, ENABLE);              
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM_CH4_PORT, &GPIO_InitStructure);

}

static void TIM_Mode(void)
{
	 // ������ʱ��ʱ��,���ڲ�ʱ��CK_INT=72M
	ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK,ENABLE);

	//ʱ���ṹ���ʼ��
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	// �Զ���װ�ؼĴ�����ֵ���ۼ�TIM_Period+1��Ƶ�ʺ����һ�����»����ж�
	TIM_TimeBaseStructure.TIM_Period=ADVANCE_TIM_PERIOD;	
	// ����CNT��������ʱ�� = Fck_int/(psc+1)
	TIM_TimeBaseStructure.TIM_Prescaler= ADVANCE_TIM_PSC;	
	// ʱ�ӷ�Ƶ���� ����������ʱ��ʱ��Ҫ�õ�
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	// ����������ģʽ������Ϊ���ϼ���
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	// �ظ���������ֵ��û�õ����ù�
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	// ��ʼ����ʱ��
	TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);
	
/*--------------------����ȽϽṹ���ʼ��-------------------*/	
	uint16_t CCR1_Val = 0;
	uint16_t CCR2_Val = 0;
	uint16_t CCR3_Val = 0;
	uint16_t CCR4_Val = 0;
	
	//����ȽϽṹ���ʼ��		
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	// ����ΪPWMģʽ1
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
	// ���ʹ��
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	// �������ʹ��
//	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	// ���ͨ����ƽ��������
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	// ����ռ�ձȴ�С


//	// �������ͨ����ƽ��������
//	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
//	// ���ͨ�����е�ƽ��������(�������ɲ�����ܿ��Բ�����)
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
//	// �������ͨ�����е�ƽ��������(�������ɲ�����ܿ��Բ�����)
//	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	TIM_OCInitStructure.TIM_Pulse = CCR1_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = CCR2_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	
	TIM_OCInitStructure.TIM_Pulse = CCR3_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_Pulse = CCR4_Val;
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);


	// ʹ�ܼ�����
	TIM_Cmd(ADVANCE_TIM, ENABLE);	
//	
//	// �����ʹ�ܣ���ʹ�õ���ͨ�ö�ʱ��ʱ����䲻��Ҫ
	TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
}

void TIM_Init(void)
{
	TIM_GPIO();
	TIM_Mode();
}


