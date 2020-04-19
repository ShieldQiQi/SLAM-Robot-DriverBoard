/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:six-axis manipulator
*****************************************/ 

#ifndef __BSP_ADVANCETIME_H
#define __BSP_ADVANCETIME_H

#include "stm32f10x.h"

//6路PWM通道
// PWM 信号的频率 F = TIM_CLK/{(ARR+1)*(PSC+1)}

#define            ADVANCE_TIM                   TIM1
#define            ADVANCE_TIM_APBxClock_FUN     RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM_CLK               RCC_APB2Periph_TIM1
#define            ADVANCE_TIM_PERIOD            (20000-1)
#define            ADVANCE_TIM_PSC               (72-1)
#define            ADVANCE_TIM_PULSE             1500

// TIM1 输出比较通道
#define            ADVANCE_TIM1_GPIO_CLK         RCC_APB2Periph_GPIOA
#define            ADVANCE_TIM1_PORT          	 GPIOA
#define            ADVANCE_TIM_CH1_PIN           GPIO_Pin_8

#define            ADVANCE_TIM_CH4_PIN           GPIO_Pin_11


#define            ADVANCE_TIM8                  TIM8
#define            ADVANCE_TIM8_APBxClock_FUN    RCC_APB2PeriphClockCmd
#define            ADVANCE_TIM8_CLK              RCC_APB2Periph_TIM8

#define            ADVANCE_TIM_PERIOD            (20000-1)
#define            ADVANCE_TIM_PSC               (72-1)
#define            ADVANCE_TIM_PULSE             1500

// TIM8 输出比较通道
#define            ADVANCE_TIM8_GPIO_CLK     		 RCC_APB2Periph_GPIOC
#define            ADVANCE_TIM8_PORT             GPIOC
#define            ADVANCE_TIM8_CH1_PIN          GPIO_Pin_6

#define            ADVANCE_TIM8_CH2_PIN          GPIO_Pin_7

#define            ADVANCE_TIM8_CH3_PIN          GPIO_Pin_8

#define            ADVANCE_TIM8_CH4_PIN          GPIO_Pin_9

/**************************函数声明*****************************/

void ADVANCE_TIM_Init(void);
void Set_Speed(uint8_t channel,float speed);


#endif	/* __BSP_ADVANCETIME_H */


