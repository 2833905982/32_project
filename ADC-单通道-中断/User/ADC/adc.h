#ifndef _ADC_H
#define _ADC_H


#include "stm32f10x.h"

											/*	ADC ���ѡ��   */
// ������ ADC1/2�����ʹ��ADC3���ж���ص�Ҫ�ĳ�ADC3��
#define    ADC_APBxClock_FUN             RCC_APB2PeriphClockCmd
#define    ADC_x                          ADC3
#define    ADC_CLK                       RCC_APB2Periph_ADC3


											/*	ADC GPIO�궨��  */
// ע�⣺����ADC�ɼ���IO����û�и��ã�����ɼ���ѹ����Ӱ��
#define    ADC_GPIO_APBxClock_FUN        RCC_APB2PeriphClockCmd
#define    ADC_GPIO_CLK                  RCC_APB2Periph_GPIOC  
#define    ADC_PORT                      GPIOA
#define    ADC_PIN                       GPIO_Pin_3

										/*		ADC ͨ���궨��   */
#define    ADC_CHANNEL                   ADC_Channel_3

									/*		ADC �ж���غ궨��  */
#define    ADC_IRQ                       ADC3_IRQn
#define    ADC_IRQHandler                ADC3_IRQHandler

void ADCx_Init(void);

#endif /* _ADC_H */


