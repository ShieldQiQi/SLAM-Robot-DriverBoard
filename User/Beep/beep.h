/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#ifndef __BEEP_H
#define	__BEEP_H

#include "stm32f10x.h"

#define BEEP_GPIO_PORT    	GPIOE			              /* GPIO�˿� */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO�˿�ʱ�� */
#define BEEP_GPIO_PIN				GPIO_Pin_15			        /* ���ӵ�SCLʱ���ߵ�GPIO */

#define	digitalHi(p,i)		 {p->BSRR=i;}	 						//���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 						//����͵�ƽ

#define beep_ON		   			 digitalHi(BEEP_GPIO_PORT,BEEP_GPIO_PIN)
#define beep_OFF			     digitalLo(BEEP_GPIO_PORT,BEEP_GPIO_PIN)

void BEEP_Config(void);

#endif /* __BEEP_H */
