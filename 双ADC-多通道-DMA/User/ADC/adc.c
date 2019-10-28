#include "adc.h"

__IO uint32_t ADC_ConvertedValue[NOFCHANEL] = {0};


static void ADCx_GPIO_Config(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// ADCx_1 GPIO 初始化
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_1_GPIO_CLK, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_1_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_1_PORT, &GPIO_InitStructure);

	// ADCx_2 GPIO 初始化
	ADCx_1_GPIO_APBxClock_FUN ( ADCx_2_GPIO_CLK, ENABLE );
	GPIO_InitStructure.GPIO_Pin = ADCx_2_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(ADCx_2_PORT, &GPIO_InitStructure);
}

static void ADCx_Mode_Config(void)
{
	
	DMA_InitTypeDef DMA_InitStructure;
	
/*---------------------------初始化DMA-------------------------------*/
		// 打开DMA时钟
	RCC_AHBPeriphClockCmd(ADC_DMA_CLK, ENABLE);
	
		// 复位DMA控制器
	DMA_DeInit(ADC_DMA_CHANNEL);
	
	// 配置 DMA 初始化结构体
	// 外设基址为：ADC 数据寄存器地址
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( uint32_t ) ( & ( ADCx_1->DR ) );
	
	// 存储器地址，实际上就是一个内部SRAM的变量
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)ADC_ConvertedValue;
	
	// 数据源来自外设
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	// 缓冲区大小为1，缓冲区的大小应该等于存储器的大小
	DMA_InitStructure.DMA_BufferSize = NOFCHANEL;
	
	// 外设寄存器只有一个，地址不用递增
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

	// 存储器地址固定
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; 
	
	// 外设数据大小为半字，即两个字节
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	
	// 存储器数据大小也为半字，跟外设数据大小相同
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	
	// 循环传输模式
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	

	// DMA 传输通道优先级为高，当使用一个DMA通道时，优先级设置不影响
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	
	// 禁止存储器到存储器模式，因为是从外设到存储器
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
	
	DMA_Cmd(ADC_DMA_CHANNEL , ENABLE);
	

	
	/*----------------------------------------------------*/
	
	
	/*-------------------ADC1初始化----------------------*/
	
		/* 定义一个结构体变量 */
	ADC_InitTypeDef ADC_InitStruct;
	
	/* 打开ADC时钟 */
	ADCx_1_APBxClock_FUN (ADCx_1_CLK, ENABLE );
	
	/* 由于只用一个ADC，打开单通道模式 */
	ADC_InitStruct.ADC_Mode = ADC_Mode_RegSimult;
	
	/* 只用一个ADC，所以不用扫描 */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* 是否连续转换，选择：是 */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* 选择触发模式，不选择：None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC 选择右对齐 */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* 选择通道，为1个通道 */
	ADC_InitStruct.ADC_NbrOfChannel = NOFCHANEL;
	
	
	ADC_Init(ADCx_1,&ADC_InitStruct);
	
	/* 调节时钟，设置为8分频 */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC 规则配置：有四个形参，第一个为确定使用那个ADC，第二个为使用哪个通道，第三个配置转换顺序，第四个选择采样周期。 */
	ADC_RegularChannelConfig(ADCx_1, ADCx_1_CHANNEL, 1, ADC_SampleTime_55Cycles5);
	
	/*----------------------------------------------------*/
	
	
	/*-------------------ADC2初始化----------------------*/


		/* 定义一个结构体变量 */
//	ADC_InitTypeDef ADC_InitStruct;

	/* 打开ADC时钟 */
	ADCx_2_APBxClock_FUN (ADCx_2_CLK, ENABLE );
	
	/* 由于只用一个ADC，打开单通道模式 */
	ADC_InitStruct.ADC_Mode = ADC_Mode_RegSimult;
	
	/* 只用一个ADC，所以不用扫描 */
	ADC_InitStruct.ADC_ScanConvMode = DISABLE;
	
	/* 是否连续转换，选择：是 */
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	
	/* 选择触发模式，不选择：None */
	ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	
	/* ADC 选择右对齐 */
	ADC_InitStruct.ADC_DataAlign  = ADC_DataAlign_Right;
	
	/* 选择通道，为1个通道 */
	ADC_InitStruct.ADC_NbrOfChannel = NOFCHANEL;
	
	
	ADC_Init(ADCx_2,&ADC_InitStruct);
	
	/* 调节时钟，设置为8分频 */
	RCC_ADCCLKConfig(RCC_PCLK2_Div8);
	
	/* ADC 规则配置：有四个形参，第一个为确定使用那个ADC，第二个为使用哪个通道，第三个配置转换顺序，第四个选择采样周期。 */
	ADC_RegularChannelConfig(ADCx_2, ADCx_2_CHANNEL, 1, ADC_SampleTime_55Cycles5);
	
	/*----------------------------------------------------*/


	/* ----------------ADCx_1 校准--------------------- */
	// 开启ADC ，并开始转换
	ADC_Cmd(ADCx_1, ENABLE);	
	// 初始化ADC 校准寄存器  
	ADC_ResetCalibration(ADCx_1);
	// 等待校准寄存器初始化完成
	while(ADC_GetResetCalibrationStatus(ADCx_1));	
	// ADC开始校准
	ADC_StartCalibration(ADCx_1);
	// 等待校准完成
	while(ADC_GetCalibrationStatus(ADCx_1));
	
  /* ----------------ADCx_2 校准--------------------- */
		// 开启ADC ，并开始转换
	ADC_Cmd(ADCx_2, ENABLE);	
	// 初始化ADC 校准寄存器  
	ADC_ResetCalibration(ADCx_2);
	// 等待校准寄存器初始化完成
	while(ADC_GetResetCalibrationStatus(ADCx_2));	
	// ADC开始校准
	ADC_StartCalibration(ADCx_2);
	// 等待校准完成
	while(ADC_GetCalibrationStatus(ADCx_2));
		/* 使能ADCx_2的外部触发转换 */
  ADC_ExternalTrigConvCmd(ADC2, ENABLE);
	
	// 由于没有采用外部触发，所以使用软件触发ADC转换 
	ADC_SoftwareStartConvCmd(ADCx_1, ENABLE);
	
}

void ADCx_Init(void)
{
	ADCx_Mode_Config();
	ADCx_GPIO_Config();
}




















