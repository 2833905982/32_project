#include "motor.h"
#include "gpio.h"
#include "SysTick.h"

void A(uint16_t a1,uint16_t a2,uint16_t a3,uint16_t a4)
{
	switch(a1)
	{
		case 1: GPIO_ResetBits(motor1_GPIO_PORT,motor1_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor1_GPIO_PORT,motor1_GPIO_PIN);break;
	}
	switch(a2)
	{
		case 1: GPIO_ResetBits(motor2_GPIO_PORT,motor2_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor2_GPIO_PORT,motor2_GPIO_PIN);break;	
	}
	switch(a3)
	{
		case 1: GPIO_ResetBits(motor3_GPIO_PORT,motor3_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor3_GPIO_PORT,motor3_GPIO_PIN);break;
	}
	switch(a4)
	{
		case 1: GPIO_ResetBits(motor4_GPIO_PORT,motor4_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor4_GPIO_PORT,motor4_GPIO_PIN);break;	
	}
}

void B(uint16_t a1,uint16_t a2,uint16_t a3,uint16_t a4)
{
	switch(a1)
	{
		case 1: GPIO_ResetBits(motor5_GPIO_PORT,motor5_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor6_GPIO_PORT,motor6_GPIO_PIN);break;
	}
	switch(a2)
	{
		case 1: GPIO_ResetBits(motor6_GPIO_PORT,motor6_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor6_GPIO_PORT,motor6_GPIO_PIN);break;	
	}
	switch(a3)
	{
		case 1: GPIO_ResetBits(motor7_GPIO_PORT,motor7_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor7_GPIO_PORT,motor7_GPIO_PIN);break;
	}
	switch(a4)
	{
		case 1: GPIO_ResetBits(motor8_GPIO_PORT,motor8_GPIO_PIN);break;
		case 0: GPIO_SetBits(motor8_GPIO_PORT,motor8_GPIO_PIN);break;	
	}
}

void A_qian_jin(void)
{
	A(0,1,1,1);
	SysTick_Dwelay_us(5000);
	A(1,0,1,1);
	SysTick_Dwelay_us(5000);
	A(1,1,0,1);
	SysTick_Dwelay_us(5000);
	A(1,1,1,0);
	SysTick_Dwelay_us(5000);
}
void A_hou_tui(void)
{
	A(1,1,1,0);
	SysTick_Dwelay_us(100);
	A(1,1,0,1);
	SysTick_Dwelay_us(100);
	A(1,0,1,1);
	SysTick_Dwelay_us(100);
	A(0,1,1,1);
	SysTick_Dwelay_us(100);
}
void B_qian_jin(void)
{
	A(0,1,1,1);
	SysTick_Dwelay_us(100);
	A(1,0,1,1);
	SysTick_Dwelay_us(100);
	A(1,1,0,1);
	SysTick_Dwelay_us(100);
	A(1,1,1,0);
	SysTick_Dwelay_us(100);
}
void B_hou_tui(void)
{
	A(1,1,1,0);
	SysTick_Dwelay_us(100);
	A(1,1,0,1);
	SysTick_Dwelay_us(100);
	A(1,0,1,1);
	SysTick_Dwelay_us(100);
	A(0,1,1,1);
	SysTick_Dwelay_us(100);
}
void motor_Init(void)
{
	A_qian_jin();
	A_hou_tui();
	B_qian_jin();
	B_hou_tui();
}




