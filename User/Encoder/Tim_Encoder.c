/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#include "Tim_Encoder.h" 

u32	Parameter = 15000;	//ÊäÈë±àÂëÆ÷ÏßÊý

static void GENENAL_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  GENENAL_TIM4_CH1_PIN|GENENAL_TIM4_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  GENENAL_TIM5_CH1_PIN|GENENAL_TIM5_CH2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

static void GENENAL_TIM_Mode_Config(void)
{

	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;
	
	GENENAL_TIM_APBxClock_FUN(GENENAL_TIM4_CLK|GENENAL_TIM5_CLK,ENABLE);

//  //--------------------TIM2-------------------/
//	
//	TIM_DeInit(GENENAL_TIM2);
//	TIM_TimeBaseStructure.TIM_Period= Parameter*4;	
//	TIM_TimeBaseStructure.TIM_Prescaler= 0;	
//	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
//	TIM_TimeBaseInit(GENENAL_TIM2, &TIM_TimeBaseStructure);

//	TIM_EncoderInterfaceConfig(GENENAL_TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
//	
//	TIM_ICInitStructure.TIM_ICFilter = 6;
//	TIM_ICStructInit(&TIM_ICInitStructure);
//	TIM_ICInit(GENENAL_TIM2, &TIM_ICInitStructure);	
//	GENENAL_TIM2->CNT = 0;
//  TIM_Cmd(GENENAL_TIM2, ENABLE);
//	
//	//--------------------TIM3-------------------/
//	
//	TIM_DeInit(GENENAL_TIM3);
//	TIM_TimeBaseStructure.TIM_Period= Parameter*4;	
//	TIM_TimeBaseStructure.TIM_Prescaler= 0;	
//	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
//	TIM_TimeBaseInit(GENENAL_TIM3, &TIM_TimeBaseStructure);

//	TIM_EncoderInterfaceConfig(GENENAL_TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
//	
//	TIM_ICInitStructure.TIM_ICFilter = 6;
//	TIM_ICStructInit(&TIM_ICInitStructure);
//	TIM_ICInit(GENENAL_TIM3, &TIM_ICInitStructure);	
//	GENENAL_TIM3->CNT = 0;
//  TIM_Cmd(GENENAL_TIM3, ENABLE);
	
	//--------------------TIM4-------------------/
	
	TIM_DeInit(GENENAL_TIM4);
	TIM_TimeBaseStructure.TIM_Period= Parameter*4;	
	TIM_TimeBaseStructure.TIM_Prescaler= 0;	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	TIM_TimeBaseInit(GENENAL_TIM4, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(GENENAL_TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
	
	TIM_ICInitStructure.TIM_ICFilter = 6;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInit(GENENAL_TIM4, &TIM_ICInitStructure);	
	GENENAL_TIM4->CNT = 30000;
  TIM_Cmd(GENENAL_TIM4, ENABLE);
	
	//--------------------TIM5-------------------/
	
	TIM_DeInit(GENENAL_TIM5);
	TIM_TimeBaseStructure.TIM_Period= Parameter*4;	
	TIM_TimeBaseStructure.TIM_Prescaler= 0;	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	TIM_TimeBaseInit(GENENAL_TIM5, &TIM_TimeBaseStructure);

	TIM_EncoderInterfaceConfig(GENENAL_TIM5, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising ,TIM_ICPolarity_Rising);
	
	TIM_ICInitStructure.TIM_ICFilter = 6;
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInit(GENENAL_TIM5, &TIM_ICInitStructure);	
	GENENAL_TIM5->CNT = 30000;
  TIM_Cmd(GENENAL_TIM5, ENABLE);

}

void TIM_Encoder(void)
{
	GENENAL_TIM_GPIO_Config();
	GENENAL_TIM_Mode_Config();	
}

/********************END OF FILE**********************/
