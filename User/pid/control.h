#ifndef __CONTROL_H
#define __CONTROL_H

#include "stm32f10x.h"

#define USE_PID 0

float Position_PID1 (float Encoder,float Target);
float Position_PID2 (float Encoder,float Target);
float Position_PID3 (float Encoder,float Target);
float Position_PID4 (float Encoder,float Target);
float Position_PID5 (float Encoder,float Target);
float Position_PID6 (float Encoder,float Target);

void Set_Pwm(float velocity1,float velocity2,float velocity3,float velocity4,float velocity5,float velocity6);


#endif	/* __CONTROL_H*/
