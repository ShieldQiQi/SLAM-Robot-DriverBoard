/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#ifndef __BEEP_H
#define	__BEEP_H

#include "stm32f10x.h"

#define BEEP_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN				GPIO_Pin_15			        /* 连接到SCL时钟线的GPIO */

#define	digitalHi(p,i)		 {p->BSRR=i;}	 						//输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 						//输出低电平

#define beep_ON		   			 digitalHi(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define beep_OFF			     digitalLo(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_Config(void);

#endif /* __BEEP_H */
