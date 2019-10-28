#ifndef __ROBOTIC_ARM_FUNCTION_H
#define __ROBOTIC_ARM_FUNCTION_H


#include "stm32f10x.h"
#include "bsp_delay.h"
#include <Servo.h>
void Servo_init(void);
void Servo_up_Grab(int ms);
void Servo_left_Grab(int ms);
void Servo_right_Grab(int ms);
void Servo_up_Place(int ms);
void Servo_left_Place(int ms);
void Servo_right_Place(int ms);
void Servo_Scan(int ms);
void Servo_over(int ms);//任务执行完毕。舵机归位


#endif	/* __ROBOTIC_ARM_FUNCTION_H */


