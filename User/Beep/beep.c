/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 
  
#include "beep.h"   

void BEEP_Config(void)
{		
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd( BEEP_GPIO_CLK , ENABLE);

		GPIO_InitStructure.GPIO_Pin = BEEP_GPIO_PIN;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		GPIO_Init(BEEP_GPIO_PORT, &GPIO_InitStructure);	

		GPIO_ResetBits(BEEP_GPIO_PORT, BEEP_GPIO_PIN);
 
}

/*********************END OF FILE**********************/
