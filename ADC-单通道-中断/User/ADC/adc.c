#include "adc.h"


static void ADCx_GPIO_Config(void)
{
	/* 初始化结构体变量 */
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/* 打开 ADC IO端口时钟 */
	ADC_GPIO_APBxClock_FUN ( ADC_GPIO_CLK, ENABLE );
	
	// 配置 ADC IO 引脚模式
	GPIO_InitStructure.GPIO_Pin = ADC_PIN;
	
	/* 配置GPIO的模式为输入模式   _AIN */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	/* 初始化 ADC IO */
	GPIO_Init(ADC_PORT, &GPIO_InitStructure);	
}

static void ADCx_Mode_Config(void)
{
	/* 定义一个结构体变量 */
	ADC_InitTypeDef ADC_InitStruct;
	
	/* 打开ADC时钟 */
	ADC_APBxClock_FUN ( ADC_CLK, ENABLE );
	
	/* 由于只用一个ADC，打开单通道模式 */
	ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
	
	/* 只用一个ADC，所以不用扫描 */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* 是否连续转换，选择：是 */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* 选择触发模式，不选择：None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC 选择右对齐 */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* 选择通道，为1个通道 */
	ADC_InitStruct.ADC_NbrOfChannel = 1;
	
	
	ADC_Init(ADC_x,&ADC_InitStruct);
	
	/* 调节时钟，设置为8分频 */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC 规则配置：有四个形参，第一个为确定使用那个ADC，第二个为使用哪个通道，第三个配置转换顺序，第四个选择采样周期。 */
	ADC_RegularChannelConfig( ADC_x , ADC_CHANNEL , 1 , ADC_SampleTime_55Cycles5 );
	
	/* 配置中断函数：第一个为那个ADC，第二个为那种类型的中断,为规则型中断 */
	ADC_ITConfig(ADC_x , ADC_IT_EOC , ENABLE);
	
	/* 使能ADC，开始转换 */
	ADC_Cmd(ADC_x , ENABLE);
	
		// ADC开始校准
	ADC_StartCalibration(ADC_x);
	
	// 等待校准完成
	while(ADC_GetCalibrationStatus(ADC_x));
	
	// 由于没有采用外部触发，所以使用软件触发ADC转换 
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
	
}

static void ADC_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	// 优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  // 配置中断优先级
  NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQ;
	
	/*  配置抢断优先级为1  */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	
	/* 配置子优先级为1 */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}


void ADCx_Init(void)
{
	ADC_NVIC_Config();
	ADCx_Mode_Config();
	ADCx_GPIO_Config();
}




















