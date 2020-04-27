#include "gear_motor.h"

float targetSpeed_L = 0;
float targetSpeed_R = 0;

void GearMotor_Config(void)
{		
	
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( GEARMOTOR_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
	
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

float PID_L (float Encoder,float Target)
{
	static float Bias,speed_bias,Integral_bias,Last_Bias;
	Bias=Target-Encoder;   
	Integral_bias+=Bias;	  
	speed_bias=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);
	Last_Bias=Bias;         
	return speed_bias; 
}

float PID_R (float Encoder,float Target)
{
	static float Bias,speed_bias,Integral_bias,Last_Bias;
	Bias=Target-Encoder;   
	Integral_bias+=Bias;	  
	speed_bias=Position_KP*Bias+Position_KI*Integral_bias+Position_KD*(Bias-Last_Bias);
	Last_Bias=Bias;         
	return speed_bias; 
}

void Set_TargetSpeed(float velocity_L,float velocity_R)
{
	// set Speed Limitation here
	targetSpeed_L = velocity_L;
	targetSpeed_R = velocity_R;
}
