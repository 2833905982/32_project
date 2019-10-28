#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "pid_gpio.h"
#include "pid.h"

uint32_t time = 0; // ms 计时变量 

void PID_Init(void)
{
	pid.Sv=100;						//用户设定值为100
	pid.Kp=20;						//比例系数
	pid.T=1000;						//PID计算周期
	pid.Ti=5000;					//积分时间
	pid.Td=1200;					//微分时间
	pid.pwmcycle=1000;		//pwm 周期是1000微秒
}



int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
	PID_Init();
	PID_GPIO_Config();
	while(1)
	{
		PID_Calc();
	}
	
}


