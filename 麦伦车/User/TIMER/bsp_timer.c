//#include "bsp_timer.h"

//extern int Encoder_Left;
//extern int Encoder_Right;

//void TIM6_Int_Init(u16 arr,u16 psc)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE); //ʱ��ʹ��

//	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
// 
//	TIM_ITConfig(  //ʹ�ܻ���ʧ��ָ����TIM�ж�
//		TIM6, //TIM2
//		TIM_IT_Update ,
//		ENABLE  //ʹ��
//		);
//	NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;  //TIM6�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
//	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

//	TIM_Cmd(TIM6, ENABLE);  //ʹ��TIMx����
//							 
//}



//void TIM7_Int_Init(u16 arr,u16 psc)
//{
//  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;

//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE); //ʱ��ʹ��

//	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
//	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
//	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
//	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
// 
//	TIM_ITConfig(  //ʹ�ܻ���ʧ��ָ����TIM�ж�
//		TIM7, //TIM2
//		TIM_IT_Update ,
//		ENABLE  //ʹ��
//		);
//	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;  //TIM7�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //�����ȼ�3��
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
//	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���

//	TIM_Cmd(TIM7, ENABLE);  //ʹ��TIMx����
//							 
//}




//void TIM6_IRQHandler(void)   //TIM6�ж�
//{
//	if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
//		{
//		TIM_ClearITPendingBit(TIM6, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ 
//		Encoder_Left=(short)TIM1->CNT;
//		TIM1->CNT=0;	
//		}
//}

//void TIM7_IRQHandler(void)   //TIM7�ж�
//{
//	if (TIM_GetITStatus(TIM7, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
//		{
//		TIM_ClearITPendingBit(TIM7, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ 
//		Encoder_Right=(short)TIM8->CNT;
//		TIM8->CNT=0;	
//		}
//}
