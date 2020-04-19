#include "gear_motor.h"


void GearMotor_Config(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( GEARMOTOR_GPIO_CLK , ENABLE);

	GPIO_InitStructure.GPIO_Pin = GEARMOTOR_GPIO_PIN4 | GEARMOTOR_GPIO_PIN3 | GEARMOTOR_GPIO_PIN2;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GEARMOTOR_GPIO_PORT_1, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GEARMOTOR_GPIO_PIN1;	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GEARMOTOR_GPIO_PORT_2, &GPIO_InitStructure);
	
	FAST_STOP_L;
	FAST_STOP_R;
 
}
