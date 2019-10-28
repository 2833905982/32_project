#include "stm32f10x.h"
#include "color.h"
#include "systick.h"

volatile u32 Colour_num1=0,Colour_num2=0,Colour_num3=0,Colour_num4=0;		// ������ɫ�������������u32
volatile u8  Time2_flag=0;    //��ʱ����־λ


/***************************** ��ʱ�� **************************************/
/*���ö�ʱ��2���ж����ȼ�Ϊ11*/
void TIM2_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure;     
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //ѡ����2												
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	//�ж�ԴΪTIM2  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;//��ռ���ȼ�0��
    NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;	//��Ӧ���ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//�����ж�
    NVIC_Init(&NVIC_InitStructure);
}

/*��ʼ����ʱ��2*/
void TIM2_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;		
	/* ����TIM2CLK Ϊ 72MHZ */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);//ʹ�ܶ�ʱ��2��ʱ��
								//TIM_DeInit(TIM2);
	TIM2_NVIC_Configuration();//���ö�ʱ��2���ж����ȼ�
	/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
    TIM_TimeBaseStructure.TIM_Period=1000;//1ms	
    /* �ۼ� TIM_Period��Ƶ�ʺ����һ�����»����ж� */	  
    TIM_TimeBaseStructure.TIM_Prescaler= 71;//ʱ��Ԥ��Ƶ��Ϊ72 	
	/* ���ⲿʱ�ӽ��в�����ʱ�ӷ�Ƶ,����û���õ� */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;	
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);//����жϱ�־λ	
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);		
    TIM_Cmd(TIM2, ENABLE);																		  
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);		/*�ȹرյȴ�ʹ��*/    
}

/****************************** END ****************************************/


/******************************* �ⲿ�ж� *****************************************/

 void EXTI2_NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//ѡ�����2λ��ռ���ȼ���2λ��Ӧ���ȼ�
  /* �����ж�Դ */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


/****************************** END **************************************/


/**********************************************************************/

void EXTI_PG2_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG | RCC_APB2Periph_AFIO,ENABLE);
												
	EXTI2_NVIC_Configuration();

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;       
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	 // ��������
  GPIO_Init(GPIOG, &GPIO_InitStructure);

  GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
  EXTI_InitStructure.EXTI_Line = EXTI_Line2;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure); 
}



/************************************************************************
���ڼ��㴫����OUT����������
***********************************************************************/

void Color2_GPIO_Config(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	/*����LED������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOG, ENABLE); 
	/*��������ģʽΪͨ���������*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	/*������������Ϊ50MHz */   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	/*ѡ��Ҫ���Ƶ�GPIOA����*/															   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_6|GPIO_Pin_8;	
	/*���ÿ⺯������ʼ��GPIOB0*/
	GPIO_Init(GPIOG, &GPIO_InitStructure);		
}


void Colour2_Config(u8 Colour)
{
	switch(Colour)
	 {
	 	case Red  : TCS32_S22(0);TCS32_S32(0);break;
		case Blue : TCS32_S22(0);TCS32_S32(1);break;
		case Green: TCS32_S22(1);TCS32_S32(1);break;
		default    : break;
	 }
}

void EXTI_PG2_Config_on()//���ⲿ�ж�
{
	EXTI_InitTypeDef EXTI_InitStructure2;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
	EXTI_InitStructure2.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure2.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
	EXTI_InitStructure2.EXTI_LineCmd =ENABLE;
	EXTI_Init(&EXTI_InitStructure2); 
}

void EXTI_PG2_Config_off()//���ⲿ�ж�
{
	EXTI_InitTypeDef EXTI_InitStructure2;
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG, GPIO_PinSource2); 
	EXTI_InitStructure2.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure2.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure2.EXTI_Trigger = EXTI_Trigger_Falling; //�½����ж�
	EXTI_InitStructure2.EXTI_LineCmd =DISABLE;
	EXTI_Init(&EXTI_InitStructure2); 
}

void TCS230_Start2(void)
{
	Colour_num2=0;												//	��������
	Time2_flag=0; 												// ��ʱ����־����	
	EXTI_PG2_Config_on();								  //���ⲿ�ж�
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);//����TIM2ʱ�ӣ���ʼ��ʱ
}

u32 TCS230_Read_Num2(u8 Colour)
{  
	Colour2_Config(Colour);								//����TCS230����ɫ�˲���	
	TCS230_Start2();											//��ʼ�������� ����������ʱ�����ⲿ�ж�                    
	while(Time2_flag==0);									//�ȴ�������
	EXTI_PG2_Config_off();								//���ⲿ�ж�
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , DISABLE);//�ض�ʱ��
	return Colour_num2;										// ���ؼ�������
}



void color_Init()//��ɫ��������ʼ��
{ 
	TIM2_Configuration();
	Color2_GPIO_Config();	
	EXTI_PG2_Config();
	TCS32_LED2(0);
}


 /*********�������ܣ�������ɫ�б�************/
 

u8 TCS230_Distinguish2(void)
{
	u16 r=0,b=0,g=0,i=0;
	TCS32_LED2(1);
	delay_ms(100);
	for(i=0;i<10;i++)
	{
		r+=TCS230_Read_Num2(Red);
		delay_ms(10);
		b+=TCS230_Read_Num2(Blue);
		delay_ms(10);
		g+=TCS230_Read_Num2(Green);
		delay_ms(10);
	}
	printf("\n red:%d,blue:%d,green:%d\n ",r,b,g);	

	TCS32_LED2(0);
	
	if(r>=350)
	{
		if(b>=800)
			return 2;//��
		else
			return 3;//��
	}
	else
	{
		if(r>=232)
			return 5;//��
		else
		{
			if(g>=255)
				return 1;//��
			else 
				return 4;//��
		}
	}

}
