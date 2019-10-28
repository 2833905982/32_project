/**
  ******************************************************************************
  * @file    Servo.c
  * @version V3.2
  * @date    2018.10.6
  * @brief   ʹ�ܶ��������������
							����switch(case)����
  ******************************************************************************
  * @attention	ֻ�����ڴ������Ŀ�����
  *
  * ʵ��ƽ̨		:Ұ��stm32f103zet6 ���İ�
  * ��Ȩ����		:��������ѧ��е������Ʋ�
  * ������			:��̫��
  *
  ******************************************************************************
  */ 
#include <Servo.h>
static void Servo_Delay_us(uint32_t us)//����ȷ��us����ʱ
{
	u8 i;//1us��ʱ�����ڴ��Ϊ80��
	while(us--)
	{
	 i=80;
		while(i--);
	}
}
static TIM_TypeDef* Get_Servo_TIMx(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin)//�ж�GPIOx��pinx���ĸ���ʱ��
{
	TIM_TypeDef* TIMx;
	if (Servo_GPIOx==GPIOA)//*******ע�⡣������á���Ҫʹ�ܡ�
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
				TIMx=TIM1;
				break;
			case GPIO_Pin_9://TIM1_CH2
				TIMx=TIM1;
				break;
			case GPIO_Pin_10://TIM1_CH3
				TIMx=TIM1;
				break;
			case GPIO_Pin_11://TIM1_CH4
				TIMx=TIM1;
				break;
			case GPIO_Pin_0://TIM2_CH1
				TIMx=TIM2;
				break;
			case GPIO_Pin_1://TIM2_CH2
				TIMx=TIM2;
				break;
			case GPIO_Pin_2://TIM2_CH3
				TIMx=TIM2;
				break;
			case GPIO_Pin_3://TIM2_CH4
				TIMx=TIM2;
				break;
			case GPIO_Pin_6://TIM3_CH1
				TIMx=TIM3;
				break;
			case GPIO_Pin_7://TIM3_CH2
				TIMx=TIM3;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
				TIMx=TIM3;
				break;
			case GPIO_Pin_1://TIM3_CH4
				TIMx=TIM3;
				break;
			case GPIO_Pin_6://TIM4_CH1
				TIMx=TIM4;
				break;
			case GPIO_Pin_7://TIM4_CH2
				TIMx=TIM4;
				break;
			case GPIO_Pin_8://TIM4_CH3
				TIMx=TIM4;
				break;
			case GPIO_Pin_9://TIM4_CH4
				TIMx=TIM4;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
				TIMx=TIM8;
				break;
			case GPIO_Pin_7://TIM8_CH2
				TIMx=TIM8;
				break;
			case GPIO_Pin_8://TIM8_CH3
				TIMx=TIM8;
				break;
			case GPIO_Pin_9://TIM8_CH4
				TIMx=TIM8;
				break;
//			default:
//				return -1;
		}
	}
	return TIMx;
}

static int Get_Servo_CCRx(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin)//�ж�GPIOx��pinx���ĸ�ͨ��
{
		int CCRx=0;
	if (Servo_GPIOx==GPIOA)//*******ע�⡣������á���Ҫʹ�ܡ�
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
			CCRx=1;
				break;
			case GPIO_Pin_9://TIM1_CH2
			CCRx=2;
				break;
			case GPIO_Pin_10://TIM1_CH3
			CCRx=3;
				break;
			case GPIO_Pin_11://TIM1_CH4
			CCRx=4;
				break;
			case GPIO_Pin_0://TIM2_CH1
			CCRx=1;
				break;
			case GPIO_Pin_1://TIM2_CH2
			CCRx=2;
				break;
			case GPIO_Pin_2://TIM2_CH3
			CCRx=3;
				break;
			case GPIO_Pin_3://TIM2_CH4
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM3_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM3_CH2
			CCRx=2;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
			CCRx=3;
				break;
			case GPIO_Pin_1://TIM3_CH4
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM4_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM4_CH2
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM4_CH3
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM4_CH4
			CCRx=4;
				break;
//			default:
//				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM8_CH2
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM8_CH3
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM8_CH4
			CCRx=4;
				break;
		}
	}
	return CCRx;
}


int Servo_GPIO_Init(GPIO_TypeDef* Servo_GPIOx, uint16_t Servo_GPIO_Pin,uint16_t start_angle)
{
	uint16_t CCRx_VAL=1500;//�ȸ�����ʼֵ
	if(start_angle>=Servo_angle_max)//��ֹ����Գд����
		start_angle=Servo_angle_max;
	else if(start_angle<=Servo_angle_min)//��ֹд����
		start_angle=Servo_angle_min;
	else 
	{CCRx_VAL=start_angle;}//ͨ����ʼ��ֵ��ȡ
	GPIO_InitTypeDef GPIO_Servo;
	TIM_TimeBaseInitTypeDef  Servo_TimeBaseStructure;
	TIM_OCInitTypeDef  Servo_OCInitStructure;
	TIM_TypeDef* TIMx;
	uint32_t Servo_GPIO_CLK;
	uint32_t Servo_RCC_APBxPeriph_TIMx;
	
	u8 CCRx=0;//�ڼ���ͨ��
	if (Servo_GPIOx==GPIOA)//*******ע�⡣������á���Ҫʹ�ܡ�
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOA;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_8://TIM1_CH1
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=1;
				break;
			case GPIO_Pin_9://TIM1_CH2
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=2;
				break;
			case GPIO_Pin_10://TIM1_CH3
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=3;
				break;
			case GPIO_Pin_11://TIM1_CH4
				TIMx=TIM1;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM1;
			CCRx=4;
				break;
			case GPIO_Pin_0://TIM2_CH1
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=1;
				break;
			case GPIO_Pin_1://TIM2_CH2
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=2;
				break;
			case GPIO_Pin_2://TIM2_CH3
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=3;
				break;
			case GPIO_Pin_3://TIM2_CH4
				TIMx=TIM2;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM2;
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM3_CH1
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM3_CH2
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=2;
				break;
			default:
				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOB)
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOB;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_0://TIM3_CH3
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=3;
				break;
			case GPIO_Pin_1://TIM3_CH4
				TIMx=TIM3;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM3;
			CCRx=4;
				break;
			case GPIO_Pin_6://TIM4_CH1
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM4_CH2
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM4_CH3
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM4_CH4
				TIMx=TIM4;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB1Periph_TIM4;
			CCRx=4;
				break;
			default:
				return -1;
		}
	}
	else if (Servo_GPIOx==GPIOC)
	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOC;
		switch (Servo_GPIO_Pin)
		{
			case GPIO_Pin_6://TIM8_CH1
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=1;
				break;
			case GPIO_Pin_7://TIM8_CH2
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=2;
				break;
			case GPIO_Pin_8://TIM8_CH3
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=3;
				break;
			case GPIO_Pin_9://TIM8_CH4
				TIMx=TIM8;
				Servo_RCC_APBxPeriph_TIMx=RCC_APB2Periph_TIM8;
			CCRx=4;
				break;
			default:
				return -1;
		}
	}
	
	/*******pwm�����ʱ�ò���********/
//	else if (Servo_GPIOx==GPIOD)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOD;
//	}
//	else if (Servo_GPIOx==GPIOE)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOE;
//	}
//	else if (Servo_GPIOx==GPIOF)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOF;
//	}
//	else if (Servo_GPIOx==GPIOG)
//	{Servo_GPIO_CLK=RCC_APB2Periph_GPIOG;
//	}
	
	else 
		return -1;
	
  // ����Ƚ�ͨ��1 GPIO ��ʼ��
	RCC_APB2PeriphClockCmd(Servo_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//����ʹ��
	GPIO_Servo.GPIO_Pin =  Servo_GPIO_Pin;
  GPIO_Servo.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
  GPIO_Servo.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(Servo_GPIOx, &GPIO_Servo);
	if(TIMx==TIM1||TIMx==TIM8)
	{
		RCC_APB2PeriphClockCmd(Servo_RCC_APBxPeriph_TIMx, ENABLE); 
	}
	else if(TIMx==TIM2||TIMx==TIM3||TIMx==TIM4)
	{
		RCC_APB1PeriphClockCmd(Servo_RCC_APBxPeriph_TIMx, ENABLE); 
	}
	
	Servo_TimeBaseStructure.TIM_Period =20000-1;       //����ʱ����0������19999����Ϊ20000�Σ�Ϊһ����ʱ����
  Servo_TimeBaseStructure.TIM_Prescaler =72-1;	    //1MHz
  Servo_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	//����ʱ�ӷ�Ƶϵ��������Ƶ(�����ò���)
  Servo_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
  TIM_TimeBaseInit(TIMx, &Servo_TimeBaseStructure);
	//***************************ʹ��ͨ��********************************//
	Servo_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    //����ΪPWMģʽ1
  Servo_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  //����ʱ������ֵС��CCR1_ValʱΪ�ߵ�ƽ
  Servo_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	Servo_OCInitStructure.TIM_Pulse=CCRx_VAL;
	switch (CCRx)
	{
		case 1:
			TIM_OC1Init(TIMx, &Servo_OCInitStructure);
			TIM_OC1PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 2:
			TIM_OC2Init(TIMx, &Servo_OCInitStructure);
			TIM_OC2PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 3:
			TIM_OC3Init(TIMx, &Servo_OCInitStructure);
			TIM_OC3PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		case 4:
			TIM_OC4Init(TIMx, &Servo_OCInitStructure);
			TIM_OC4PreloadConfig(TIMx, TIM_OCPreload_Enable);
			break;
		default :
			return -2;
	}
			TIM_ARRPreloadConfig(TIMx, ENABLE);			 // ʹ��TIM3���ؼĴ���ARR
			TIM_Cmd(TIMx, ENABLE);                   //ʹ�ܶ�ʱ��3	
	return 1;//��ʼ���ɹ�
}

int Servo_Init(Servo Servox[],int array_length)//����Ϊ�ṹ������//array_length=sizeof(Servox)/(5*sizeof(uint16_t));
{
	int times=0;
	while(array_length--)
	{
	if(1!=Servo_GPIO_Init(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin,Servox[times].start_angle))//���ṹ��Ա����Ϣ��ȡ�������ó�ʼ���������������á�
		return -1;//��ʼ������
		times++;
	}
	return 1;//��ʼ���ɹ���
}

int NServo_Write(Servo Servox[],uint32_t us,int array_length)//Ҫ���в����Ľṹ�����顢����ʱ
{
	int times=0;
	int CCRx[array_length];
	TIM_TypeDef* TIMx[array_length];
	for(times=0;times<array_length;++times)//��ȡ��ǰͨ����pwm���������ṹ���start_angle�У����ж���ͨ����������ṹ����
	{
		TIMx[times]=Get_Servo_TIMx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin);
		if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==1)
		{
		Servox[times].start_angle=TIM_GetCapture1(TIMx[times]);//���λ�ȡ�ϴ�
		CCRx[times]=1;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==2)
		{
		Servox[times].start_angle=TIM_GetCapture2(TIMx[times]);//���λ�ȡ�ϴ�
		CCRx[times]=2;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==3)
		{
		Servox[times].start_angle=TIM_GetCapture3(TIMx[times]);//���λ�ȡ�ϴ�
		CCRx[times]=3;
		}
		else if(Get_Servo_CCRx(Servox[times].Servo_GPIOx,Servox[times].Servo_GPIO_Pin)==4)
		{
		Servox[times].start_angle=TIM_GetCapture4(TIMx[times]);//���λ�ȡ�ϴ�
		CCRx[times]=4;
		}
	}
	int intent_flag=0x0000;
	int flag=0x0000;
		for(times=0;times<array_length;++times)
  {
				intent_flag<<=1;
				intent_flag|=0x0001;
	}
	while(1)
	{
		int once=1;//pwmÿ�α仯��ֵ
	for(times=0;times<array_length;++times)//д��Ĵ���.����ʱ
	{
		if (Servox[times].start_angle==Servox[times].intent_angle)
		{
			flag|=(0x0001<<times);//��־λ��һ��
				if(flag==intent_flag)
				{return 1;}//���ѭ����length�Ρ������������е�Servo�ṹ�塣�������еĳ�Ա���ϴνǶ�ֵ����Ŀ�ĽǶ�ֵ������Ϊȫ����λ��
			continue;//����������һ���ṹ�������
		}
		else if(Servox[times].start_angle>Servox[times].intent_angle)
		{
			once=-1;//�����ǰֵ����Ŀ��ֵ����Ϊ��1
		}
		else if(Servox[times].start_angle<Servox[times].intent_angle)
		{
			once=1;//�����ǰֵС��Ŀ��ֵ����Ϊ��1
		}
		if(CCRx[times]==1)
		{
			TIM_SetCompare1(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==2)
		{
		TIM_SetCompare2(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==3)
		{
		TIM_SetCompare3(TIMx[times], Servox[times].start_angle+=once);
		}
		else if(CCRx[times]==4)
		{
		TIM_SetCompare4(TIMx[times], Servox[times].start_angle+=once);
		}
	}
	Servo_Delay_us(us);//����Ĵ����ʱ
}
	return 1;
}

