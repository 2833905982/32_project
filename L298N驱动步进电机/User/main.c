#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "SysTick.h"
#include "motor.h"
#include "gpio.h"

int main(void)
{
	mortor_GPIO_Config();

	motor_Init();
	
	while(1)
	{
		A_qian_jin();
	}
}




