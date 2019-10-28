#include "pid_gpio.h"
#include "pid.h"


void PID_GPIO_Config(void)																	//PID输出管脚设置
{
	GPIO_InitTypeDef GPIO_InitStruct;													//定义结构体变量。
	
	RCC_APB2PeriphClockCmd(PID_GPIO_CLK, ENABLE);							//rcc 打开时钟，设置APB2总线。
	GPIO_InitStruct.GPIO_Pin = PID_GPIO_PIN;									//定义IO口，设置PB端口。
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;							//设置输出方式，为推挽输出
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;						//设置速度为50MHZ.
	GPIO_Init(PID_GPIO_PORT, &GPIO_InitStruct);								//传IO口，和结构体变量的值。
}

void PID_out(void)			//输出 PID 运算结果到负载上-----每一毫秒被调用一次 																			
{
	static u16 pw;
	
	pw++;
	
	if(pw>=pid.pwmcycle)							
	{
		pw=0;
	}
	
	//0   ·    pid.pwmcycle-1
	if(pw<pid.OUT)
	{
		pwmout_0;				 //加热
	}
	else
	{
		pwmout_1;			  //停止加热
	}
}



