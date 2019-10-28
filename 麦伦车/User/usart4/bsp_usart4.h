#ifndef __USART_H
#define	__USART_H


#include "stm32f10x.h"
#include <stdio.h>



// 串口4-UART4
#define  DEBUG_USART4                   UART4
#define  DEBUG_USART4_CLK                RCC_APB1Periph_UART4
#define  DEBUG_USART4_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART4_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  DEBUG_USART4_GPIO_CLK           (RCC_APB2Periph_GPIOC)
#define  DEBUG_USART4_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART4_TX_GPIO_PORT         GPIOC   
#define  DEBUG_USART4_TX_GPIO_PIN          GPIO_Pin_10
#define  DEBUG_USART4_RX_GPIO_PORT       GPIOC
#define  DEBUG_USART4_RX_GPIO_PIN        GPIO_Pin_11

#define  DEBUG_USART4_IRQ                UART4_IRQn
#define  DEBUG_USART4_IRQHandler         UART4_IRQHandler





void USART4_Config(void);
void Usart4_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart4_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart4_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif /* __USART_H */
