#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
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




