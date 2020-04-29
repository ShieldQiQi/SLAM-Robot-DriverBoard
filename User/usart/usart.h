#ifndef __USART_H
#define	__USART_H

#include "stm32f10x.h"
#include <stdio.h>

// RS485读写IO
#define RS485Ctrl_GPIO_PORT    		GPIOC	
#define RS485Ctrl_GPIO_CLK 	    	RCC_APB2Periph_GPIOC
#define RS485Ctrl_Pin							GPIO_Pin_12

#define	digitalHi(p,i)		 {p->BSRR=i;}	 						
#define digitalLo(p,i)		 {p->BRR=i;}

#define Write_Ena		   		 digitalHi(RS485Ctrl_GPIO_PORT,GPIO_Pin_12)
#define Read_Ena			     digitalLo(RS485Ctrl_GPIO_PORT,GPIO_Pin_12)

// 串口3-USART3
#define  TX2_USART3                     USART3
#define  DEBUG_USART_CLK                RCC_APB1Periph_USART3
#define  DEBUG_USART_APBxClkCmd         RCC_APB1PeriphClockCmd
#define  DEBUG_USART_BAUDRATE           115200

// USART GPIO 引脚宏定义
#define  DEBUG_USART_GPIO_CLK          (RCC_APB2Periph_GPIOB)
#define  DEBUG_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd
    
#define  DEBUG_USART_TX_GPIO_PORT       GPIOB   
#define  DEBUG_USART_TX_GPIO_PIN        GPIO_Pin_10
#define  DEBUG_USART_RX_GPIO_PORT       GPIOB
#define  DEBUG_USART_RX_GPIO_PIN        GPIO_Pin_11

#define  DEBUG_USART_IRQ                USART3_IRQn
#define  TX2_USART_IRQHandler   			  USART3_IRQHandler


void USART3_Config(void);
void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString( USART_TypeDef * pUSARTx, char *str);
void Usart_SendHalfWord( USART_TypeDef * pUSARTx, uint16_t ch);

#endif /* __USART_H */
