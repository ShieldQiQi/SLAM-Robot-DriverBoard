/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#ifndef __GENENALTIME_H
#define __GENENALTIME_H


#include "stm32f10x.h"

//通用定时器2、3、4、5
#define            GENENAL_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd

#define            GENENAL_TIM2                   TIM2
#define            GENENAL_TIM2_CLK               RCC_APB1Periph_TIM2
#define            GENENAL_TIM3                   TIM3
#define            GENENAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENENAL_TIM4                   TIM4
#define            GENENAL_TIM4_CLK               RCC_APB1Periph_TIM4
#define            GENENAL_TIM5                   TIM5
#define            GENENAL_TIM5_CLK               RCC_APB1Periph_TIM5

//TIM2 输入捕获通道3、4
#define            GENENAL_TIM2_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENENAL_TIM2_CH3_PORT          GPIOA
#define            GENENAL_TIM2_CH3_PIN           GPIO_Pin_2
#define            GENENAL_TIM2_IC3PWM_CHANNEL    TIM_Channel_3
#define            GENENAL_TIM2_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENENAL_TIM2_CH4_PORT          GPIOA
#define            GENENAL_TIM2_CH4_PIN           GPIO_Pin_3
#define            GENENAL_TIM2_IC4PWM_CHANNEL    TIM_Channel_4

//TIM3 输入捕获通道3、4
#define            GENENAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM3_CH3_PORT          GPIOB
#define            GENENAL_TIM3_CH3_PIN           GPIO_Pin_0
#define            GENENAL_TIM3_IC3PWM_CHANNEL    TIM_Channel_3
#define            GENENAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM3_CH4_PORT          GPIOB
#define            GENENAL_TIM3_CH4_PIN           GPIO_Pin_1
#define            GENENAL_TIM3_IC4PWM_CHANNEL    TIM_Channel_4

//TIM4 输入捕获通道1、2
#define            GENENAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM4_CH1_PORT          GPIOB
#define            GENENAL_TIM4_CH1_PIN           GPIO_Pin_6
#define            GENENAL_TIM4_IC1PWM_CHANNEL    TIM_Channel_1
#define            GENENAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM4_CH2_PORT          GPIOB
#define            GENENAL_TIM4_CH2_PIN           GPIO_Pin_7
#define            GENENAL_TIM4_IC2PWM_CHANNEL    TIM_Channel_2

//TIM5 输入捕获通道1、2
#define            GENENAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM5_CH1_PORT          GPIOB
#define            GENENAL_TIM5_CH1_PIN           GPIO_Pin_0
#define            GENENAL_TIM5_IC1PWM_CHANNEL    TIM_Channel_1
#define            GENENAL_TIM5_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENENAL_TIM5_CH2_PORT          GPIOB
#define            GENENAL_TIM5_CH2_PIN           GPIO_Pin_1
#define            GENENAL_TIM5_IC2PWM_CHANNEL    TIM_Channel_2


void TIM_Encoder(void);


#endif	/* __GENENALTIME_H */








