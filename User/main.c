/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 

#include "stm32f10x.h"
#include "usart.h"
#include "blue_tooth.h"
#include "nvic.h"
#include "led.h"
#include "TiMbase.h"
#include "AdvanceTim_PWM.h"
#include "adc.h"
#include "beep.h"
#include "msg_queue.h"
#include "gear_motor.h"
#include "Tim_Encoder.h"

int main(void)
{	
	GearMotor_Config();
  USART3_Config();
	USART1_Config();
	LED_GPIO_Config();
	BASIC_TIM_Init();
	ADVANCE_TIM_Init();
	ADCx_Init();
	BEEP_Config();
  NVIC_Configuration();
	TIM_Encoder();
	Init_usartMsg_Queue();

	Read_Ena;
	while(1)
	{
		
	}
	
}


/*******************END OF FILE**********************/
