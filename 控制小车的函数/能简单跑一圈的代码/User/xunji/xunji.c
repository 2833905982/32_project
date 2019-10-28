#include "xunji.h"
#include "jiaodu.h"
#include "huidu.h"

void xunji(void)
{
		
		//¼ì²â×ó»Ò¶È
		if(scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON && scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF)
		{
			turn_left(25);
		}
		//¼ì²âÓÒ»Ò¶È
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			turn_right(25);
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == OFF && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == OFF)
		{
			qian_jin();		
		}
		if(scan (HUI2_GPIO_PORT,HUI2_GPIO_PIN) == ON && scan (HUI1_GPIO_PORT,HUI1_GPIO_PIN) == ON)
		{
			qian_jin();	
		}
}
void back_xunji(void)
{
	//¼ì²â×ó»Ò¶È
	if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON && scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == OFF)
	{
		left_back(2);
	}
		//¼ì²âÓÒ»Ò¶È
	if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF && scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == ON)
	{
		right_back(2);		
	}
		if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == OFF && scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == OFF)
	{
		back();
	}
	if(scan (HUI6_GPIO_PORT,HUI6_GPIO_PIN) == ON && scan (HUI7_GPIO_PORT,HUI7_GPIO_PIN) == ON)
	{
		back();	
	}	
}



