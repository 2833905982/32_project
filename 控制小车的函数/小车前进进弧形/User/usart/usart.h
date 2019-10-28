#ifndef _USART_H
#define _USART_H

#include "stm32f10x.h"
#include <stdio.h>


//����1-USART1
#define DEBUG_USARTx                   USART1
#define DEBUG_USART_CLK                RCC_APB2Periph_USART1
#define DEBUG_USART_APBxClkCmd         RCC_APB2PeriphClockCmd
#define DEBUG_USART_BAUDRATE           115200                       //Ҳ���Ըĳ�9600��4800

//USART GPIO ���Ŷ���
#define DEBUG_USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)
#define DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd

#define DEBUG_USART_TX_GPIO_PORT       GPIOA
#define DEBUG_USART_TX_GPIO_PIN		     GPIO_Pin_9
#define DEBUG_USART_RX_GPIO_PORT       GPIOA
#define DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_10

#define DEBUG_USART_IRQ                USART1_IRQn
#define DEBUG_USART_IRQHandler         USART1_IRQHandler

void USART_Config(void);
void Usart_SendByte(USART_TypeDef* pUSARTx,uint8_t data);
void Usart_send(USART_TypeDef* pUSARTx,uint16_t data);
void Usart_send8(USART_TypeDef* pUSARTx,uint8_t *array,uint8_t num);
void Usart_sendstr(USART_TypeDef* pUSARTx,uint8_t *str);

#endif /*_USART_H*/



