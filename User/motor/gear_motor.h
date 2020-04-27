#ifndef __GEAR_MOTOR_H
#define __GEAR_MOTOR_H

#include "stm32f10x.h"

#define GEARMOTOR_GPIO_PORT_1    		GPIOD		
#define GEARMOTOR_GPIO_PORT_2    		GPIOB
#define GEARMOTOR_GPIO_CLK 	    	  RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOB

#define GEARMOTOR_GPIO_PIN4				GPIO_Pin_5		       
#define GEARMOTOR_GPIO_PIN3				GPIO_Pin_6			       
#define GEARMOTOR_GPIO_PIN2				GPIO_Pin_7			 
#define GEARMOTOR_GPIO_PIN1				GPIO_Pin_3	


#define	digitalHi(p,i)		 {p->BSRR=i;}	 						//输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 						//输出低电平


#define REV_R		   		 {digitalHi(GEARMOTOR_GPIO_PORT_2,GEARMOTOR_GPIO_PIN1);\
												digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN2);}

#define FWD_R			     {digitalLo(GEARMOTOR_GPIO_PORT_2,GEARMOTOR_GPIO_PIN1);\
												digitalHi(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN2);}

#define FAST_STOP_L		 {digitalLo(GEARMOTOR_GPIO_PORT_2,GEARMOTOR_GPIO_PIN1);\
												digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN2);}
												
#define REV_L		   		 {digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN3);\
												digitalHi(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN4);}

#define FWD_L			     {digitalHi(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN3);\
												digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN4);}

#define FAST_STOP_R		 {digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN3);\
												digitalLo(GEARMOTOR_GPIO_PORT_1,GEARMOTOR_GPIO_PIN4);}

void GearMotor_Config(void);

												
#define Position_KP 6
#define Position_KI 0
#define Position_KD 0
												
float PID_L (float Encoder,float Target);
float PID_R (float Encoder,float Target);

void Set_TargetSpeed(float velocity_L,float velocity_R);

#endif   /*__GEAR_MOTOR_H*/

