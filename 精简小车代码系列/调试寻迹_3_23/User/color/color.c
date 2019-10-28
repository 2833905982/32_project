#include "stm32f10x.h"
#include "color.h"
#include "systick.h"
#include "move.h"

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
	TCS32_LED2(1);delay_ms(100);
	for(i=0;i<10;i++)
	{
		r+=TCS230_Read_Num2(Red);
		delay_ms(10);
		b+=TCS230_Read_Num2(Blue);
		delay_ms(10);
		g+=TCS230_Read_Num2(Green);
		delay_ms(10);
	}
	r=r/12;b=b/10;g=g/10;
	TCS32_LED2(0);	
	if(r+g+b>80)
		return 2;//��
	else if(b>=r*2.08)
		return 5;//��	
	else if(r>=g*2)
		return 3;//��
	else if(g*1.2>b)
		return 1;//��	
	else if(r+g+b<=35)
		return 4;//��	
	else
		return 0;	
}

void color(void)
{
	TIM2_Configuration();
	TIM2_NVIC_Configuration();
	Color2_GPIO_Config();
	EXTI2_NVIC_Configuration();
	EXTI_PG2_Config();
	color_Init();
	TCS230_Start2();
	EXTI_PG2_Config_on();
	EXTI_PG2_Config_off();
	USART_Config();
	SysTick_Init();
}


/********************* ��ɫʶ�� ******************************/

/********************* ���CΪ��ɫ ***********************************/
void green(void)
{
	back_lukou(2);													//���˹�������·�ڣ��ص�����·��
	delay_s(2);                             //������·��ͣ������
	L_zhuanwan(2);													//��ת��ʹ�õ��ǻҶ� 8 
	delay_s(2);                             //ת���ͣ����
	qianjin_lukou1(2);                      //ǰ������·�ڵ��� A �����
	
	
	/* ���A����������ɫ */
	while(1)
	{
		if(TCS230_Distinguish2()==3)					//��� A ��Ϊ��ɫ
		{
			qianjin_lukou1(1);									//ǰ��һ��·�ڣ�������ɫ������
			delay_s(1);													//ͣһ��
			back_lukou(3);											//���ˣ�ʹ��С���ص����ֵ����룬�õĵڶ��ŻҶ�
			R_zhuanwan1(2);											//����ת����ʱ�õ��ǻҶ�6
			delay_s(1);   											//ͣ 1 ��
			qianjin_lukou1(3);									//ǰ��3��·�ڣ����Ե����ɫ
			delay_s(1);												  // ͣ1��
			back_lukou(3);											//����3��·�ڣ��õĵڶ��ŻҶ�
			R_zhuanwan2(2);											//����ת����·�ڣ��õĻҶ�9����ʼȥ�����ɫ
			delay_s(1);													//ͣ1��
			qianjin();													//ǰ��һ�ᣬĿ�����߹����֣�����˴��ĸ���
			qianjin();
			delay_ms(200);			
			qianjin_lukou1(2);									//ǰ��������·��
			delay_s(1);													//ͣ1��
			back_lukou(3);											//����3��·�ڻص�����
			turn_right();                       //����ת����äתһ�ᣬʹ��ת����ǰ������ѹ�ŵ���
			delay_ms(150);
			R_zhuanwan1(2);											//����ת���õĻҶ�6��ʹС����ʼ�������ǰ��
			delay_s(1);
			qianjin_lukou2(4);									//��ǰ���ĸ�·�ڣ���ʱ��ƨ�ɻ��ڳ���������
			qianjin();													//����ǰ��һ�㣬�ص�������
			delay_ms(300);
			stop();
			break;
		}
	}
}






