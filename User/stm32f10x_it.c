/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:six-axis manipulator
*****************************************/

#include <math.h>
#include "stm32f10x_it.h"
#include "usart.h"
#include "blue_tooth.h"
#include "TiMbase.h"
#include "led.h"
#include "adc.h"
#include "beep.h"
#include "AdvanceTim_PWM.h"
#include "msg_queue.h"
#include "control.h"	
#include "gear_motor.h"

uint8_t     i =0;
uint8_t     m =0;
uint8_t     tmp =0;
uint8_t     restCount =0;
uint8_t     triggerBeep =0;
uint16_t    time0 = 0;
uint8_t     time1 = 0;
uint16_t    time2 = 0;
uint8_t     time3 = 0;
uint8_t     is_nextText = 0;
uint8_t     is_meetEnd = 0;
uint8_t			isTrueDataFlag = 0;
uint8_t			onWriting = 0;
uint8_t			count = 0;
uint8_t			sendFlag = 0;		
uint8_t			receiveData = 0;
uint16_t		msgBuffer[6];
extern 			LinkQueue thetaArray_Queue;

extern float						Position_KP,Position_KI,Position_KD;  
extern float		 				Velocity1,Velocity2,Velocity3,Velocity4,Velocity5,Velocity6;
extern float 						Position1,Position2,Position3,Position4,Position5,Position6;
float										currentAngles[6] = {0,0,0,0,0,0};
float										deltaMax = 0;
float										time_finish = 0;
float										time_used = 0;
float										coefficients[6][4];

extern __IO uint16_t 		ADC_ConvertedValue[NOFCHANEL]; 	 
float 									ADC_ConvertedValueLocal[NOFCHANEL]; 


/*------------------------------------------------------------------------------------------------------------------------------------------------
定时中断：：100HZ / 10ms
-------------------------------------------------------------------------------------------------------------*/

void  BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{	
		
		//--------------------------------------
		if(time1 % 15 == 0)
		{
			LED1_TOGGLE;
			LED2_TOGGLE;
			
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
			
		  
		  USART_SendData(RasberryPi_USART3, 68);
		
		}
		
		time0++;
		time1++;
		

		
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  		 
	}
}


/*------------------------------------------------------------------------------------------------------------------------------------------------
定时中断：：100HZ / 10ms
接收树莓派串口消息
-------------------------------------------------------------------------------------------------------------*/

void RasberryPi_USART_IRQHandler(void) 
{
 
	if(USART_GetITStatus(RasberryPi_USART3,USART_IT_RXNE)!=RESET)
	{	
//		receiveData = USART_ReceiveData(RasberryPi_USART3);
//		LED2_ON;
//		USART_SendData(RasberryPi_USART3, 55);
//		//接收报文内容
//		if(isTrueDataFlag >= 2)
//		{
//			if(isTrueDataFlag % 2 == 0)	//取低8位
//				msgBuffer[isTrueDataFlag/2-1] = receiveData;
//			else												//取高8位
//				msgBuffer[isTrueDataFlag/2-1] = (((uint16_t)receiveData) << 8) | (msgBuffer[isTrueDataFlag/2-1] & 0x00FF);
//			
//			isTrueDataFlag++;
//			if(isTrueDataFlag == 14){
//				Push(&thetaArray_Queue,msgBuffer);
//				isTrueDataFlag = 0;
//			}
//		}
//		
//		//接收报文头
//		if(receiveData == 255 && isTrueDataFlag < 2){
//			isTrueDataFlag++;
//		}
		
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------
定时中断：：100HZ / 10ms
接收蓝牙串口消息
-------------------------------------------------------------------------------------------------------------*/

void Bluetooth_USART1_IRQHandler(void) 
{
  uint8_t ucTemp=1;
	if(USART_GetITStatus(Bluetooth_USART1,USART_IT_RXNE)!=RESET)
	{
		ucTemp=USART_ReceiveData(Bluetooth_USART1);
		if(ucTemp==48){
			beep_ON;
			LED2_ON;
			USART_SendData(Bluetooth_USART1, 48);
		}
		else if(ucTemp==49){
			beep_OFF;
		}
	}
}

/**************************************************************END OF FILE**************************************************************/
