/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#include "nvic.h"
#include "usart.h"
#include "blue_tooth.h"
#include "TIMbase.h"

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
	//����3�ж�����
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//����1 �������� �ж�����
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitStructure.NVIC_IRQChannel = DEBUG_USART1_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	//������ʱ������ʱ
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
	NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


/*******************END OF FILE**********************/
