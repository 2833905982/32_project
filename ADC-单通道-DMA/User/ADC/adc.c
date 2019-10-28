#include "adc.h"

__IO uint16_t ADC_ConvertedValue;


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
	
	DMA_InitTypeDef DMA_InitStructure;
	
/*---------------------------初始化DMA-------------------------------*/
		// 打开DMA时钟
	RCC_AHBPeriphClockCmd(ADC_DMA_CLK, ENABLE);
	
		// 复位DMA控制器
	DMA_DeInit(ADC_DMA_CHANNEL);
	
	// 配置 DMA 初始化结构体
	// 外设基址为：ADC 数据寄存器地址
	DMA_InitStructure.DMA_PeripheralBaseAddr = ( uint32_t ) ( & ( ADC_x->DR ) );
	
	// 存储器地址，实际上就是一个内部SRAM的变量
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADC_ConvertedValue;
	
	// 数据源来自外设
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	
	// 缓冲区大小为1，缓冲区的大小应该等于存储器的大小
	DMA_InitStructure.DMA_BufferSize = 1;
	
	// 外设寄存器只有一个，地址不用递增
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;

	// 存储器地址固定
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable; 
	
	// 外设数据大小为半字，即两个字节
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	
	// 存储器数据大小也为半字，跟外设数据大小相同
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	
	// 循环传输模式
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;	

	// DMA 传输通道优先级为高，当使用一个DMA通道时，优先级设置不影响
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	
	// 禁止存储器到存储器模式，因为是从外设到存储器
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	
	DMA_Init(ADC_DMA_CHANNEL, &DMA_InitStructure);
	
	DMA_Cmd(ADC_DMA_CHANNEL , ENABLE);
	

	
	/*----------------------------------------------------*/
	
	
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
	
		 	// 使能ADC DMA 请求
	ADC_DMACmd(ADC_x, ENABLE);
	
	/* 使能ADC，开始转换 */
	ADC_Cmd(ADC_x , ENABLE);
	
		// ADC开始校准
	ADC_StartCalibration(ADC_x);
	
	// 等待校准完成
	while(ADC_GetCalibrationStatus(ADC_x));
	
	// 由于没有采用外部触发，所以使用软件触发ADC转换 
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
	
}

void ADCx_Init(void)
{
	ADCx_Mode_Config();
	ADCx_GPIO_Config();
}




















