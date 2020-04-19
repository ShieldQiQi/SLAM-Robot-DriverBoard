/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

#define LED1_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define LED1_GPIO_PIN				GPIO_Pin_8			        /* 连接到SCL时钟线的GPIO */

#define LED2_GPIO_PORT    	GPIOE			              /* GPIO端口 */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOE		/* GPIO端口时钟 */
#define LED2_GPIO_PIN				GPIO_Pin_12			        /* 连接到SCL时钟线的GPIO */


#define ON  0
#define OFF 1

/* 使用标准的固件库控制IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)


/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态


/* 定义控制IO的宏 */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)


/* 基本混色，后面高级用法使用PWM可混出全彩颜色,且效果更好 */

//红
#define LED_RED  \
					LED1_ON;\
					LED2_OFF\

//绿
#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON\

//蓝
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF\

					
//黄(红+绿)					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON\
					
//紫(红+蓝)
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF\

//青(绿+蓝)
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON\
					
//白(红+绿+蓝)
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON\
					
//黑(全部关闭)
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF\

void LED_GPIO_Config(void);

#endif /* __LED_H */
