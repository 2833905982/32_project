#ifndef _COLOR_H
#define _COLOR_H


#include "stm32f10x.h"
#include "weidai.h"
#include "usart.h"


#define Red    1
#define Green  2
#define Blue   3

#define TCS32_S22(n)    PGout(4)=n
#define TCS32_S32(n)    PGout(6)=n
#define TCS32_LED2(n)   PGout(8)=n

void TIM2_Configuration(void);
void TIM2_NVIC_Configuration(void);

void Color2_GPIO_Config(void);
void EXTI2_NVIC_Configuration(void);
void EXTI_PG2_Config(void);
void color_Init(void);
void Colour2_Config(u8 Colour);
void TCS230_Start2(void);
void EXTI_PG2_Config_on(void);
void EXTI_PG2_Config_off(void);
u32 TCS230_Read_Num2(u8 Colour);
u8 TCS230_Distinguish2(void);
void renwu1(void);
void renwu2_f(void);
void renwu2_h(void);
void color_a(void);
void h_zhuaqvpanduan(void);
void h_f1_zhuaqvpanduan(void);
void f_zhuaqvpanduan(void);
void f_m_zhuaqvpanduan(void);
void e_f1(int zhuazi,int houtui);
void f1_zhua_a(void);
void f1_zhua_b(void);
void f1_zhua_c(void);
void f1_zhua_d(void);
void f1_zhua_e(void);
void a_h1(int zhuazi,int houtui);




#endif /*_BASE_H*/


