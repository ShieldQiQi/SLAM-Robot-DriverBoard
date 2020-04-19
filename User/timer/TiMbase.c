/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#include "TiMbase.h" 

void BASIC_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
	
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;
	
    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);
    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);

    TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);

    TIM_Cmd(BASIC_TIM, ENABLE);	
}

void BASIC_TIM_Init(void)
{
	BASIC_TIM_Mode_Config();
}
/*********************END OF FILE**********************/
