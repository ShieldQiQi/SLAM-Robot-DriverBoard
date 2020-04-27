/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#include "AdvanceTim_PWM.h"

static void ADVANCE_TIM_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  // 输出比较通道 GPIO 初始化
	RCC_APB2PeriphClockCmd(ADVANCE_TIM1_GPIO_CLK|ADVANCE_TIM8_GPIO_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM_CH1_PIN|ADVANCE_TIM_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM1_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin =  ADVANCE_TIM8_CH1_PIN|ADVANCE_TIM8_CH2_PIN|ADVANCE_TIM8_CH3_PIN|ADVANCE_TIM8_CH4_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(ADVANCE_TIM8_PORT, &GPIO_InitStructure);
	
}

static void ADVANCE_TIM_Mode_Config(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	ADVANCE_TIM_APBxClock_FUN(ADVANCE_TIM_CLK|ADVANCE_TIM8_CLK,ENABLE);

	TIM_TimeBaseStructure.TIM_Period=ADVANCE_TIM_PERIOD;	
	TIM_TimeBaseStructure.TIM_Prescaler= ADVANCE_TIM_PSC;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;		
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;		
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;	
	
	//----------------------------TIM1------------------------------/
	
	TIM_TimeBaseInit(ADVANCE_TIM, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Disable; 
	TIM_OCInitStructure.TIM_Pulse = ADVANCE_TIM_PULSE;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCNPolarity_High;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Reset;
	
	TIM_OC1Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);
	TIM_OC4Init(ADVANCE_TIM, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(ADVANCE_TIM, TIM_OCPreload_Enable);

	TIM_Cmd(ADVANCE_TIM, ENABLE);	
	TIM_CtrlPWMOutputs(ADVANCE_TIM, ENABLE);
	
	//----------------------------TIM8------------------------------/
	
	TIM_TimeBaseInit(ADVANCE_TIM8, &TIM_TimeBaseStructure);
	
	TIM_OC1Init(ADVANCE_TIM8, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(ADVANCE_TIM8, TIM_OCPreload_Enable);
	TIM_OC2Init(ADVANCE_TIM8, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(ADVANCE_TIM8, TIM_OCPreload_Enable);
	TIM_OC3Init(ADVANCE_TIM8, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(ADVANCE_TIM8, TIM_OCPreload_Enable);
	TIM_OC4Init(ADVANCE_TIM8, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(ADVANCE_TIM8, TIM_OCPreload_Enable);

	TIM_Cmd(ADVANCE_TIM8, ENABLE);	
	TIM_CtrlPWMOutputs(ADVANCE_TIM8, ENABLE);
}

void Set_Speed(uint8_t channel,float speed)
{
	if(speed < 0)
		speed = 0;
	if(speed > 20000)
		speed = 20000;

	switch(channel)
	{
		case 1:
			TIM_SetCompare1(TIM8, (uint16_t)speed);
			break;
		case 2:
			TIM_SetCompare2(TIM8, (uint16_t)speed);
			break;
		case 3:
			TIM_SetCompare3(TIM8, (uint16_t)speed);
			break;
		case 4:
			TIM_SetCompare4(TIM8, (uint16_t)speed);
			break;
		case 5:
			TIM_SetCompare1(TIM8, (uint16_t)speed);
			TIM_SetCompare3(TIM8, (uint16_t)speed);
			TIM_SetCompare1(TIM1, (uint16_t)speed);
			break;
		case 6:
			TIM_SetCompare2(TIM8, (uint16_t)speed);
			TIM_SetCompare4(TIM8, (uint16_t)speed);
			TIM_SetCompare4(TIM1, (uint16_t)speed);
			break;		
	}

}

void ADVANCE_TIM_Init(void)
{
	ADVANCE_TIM_GPIO_Config();
	ADVANCE_TIM_Mode_Config();	

	Set_Speed(1,0);
	Set_Speed(2,0);
	Set_Speed(3,0);
	Set_Speed(4,0);
	Set_Speed(5,0);
	Set_Speed(6,0);	
}

/*********************************************END OF FILE**********************/
