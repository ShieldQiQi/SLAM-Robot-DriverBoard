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
#include "Tim_Encoder.h"

uint8_t     car_Statu = 4;
uint8_t     car_StatuLast = 4;
uint8_t     car_StatuChangeCount =0;
uint8_t     Ctrl_Mode = 0;
uint8_t     i = 0;
int         j = 0; 
uint8_t     isTrueDataFlag = 0;
uint8_t     m =0;
uint8_t     tmp =0;
uint8_t     restCount =0;
uint8_t     triggerBeep =0;
uint16_t    time0 = 0;
uint8_t     time1 = 0;
uint8_t     time2 = 0;
uint8_t			count = 0;		
uint8_t			receiveData = 0;
uint8_t		  msgBuffer[3] = {0,0,0};
extern 			LinkQueue speedArray_Queue;

uint16_t		Count_br = 0;
uint16_t		Count_bl = 0;
float				encoder_blv = 0;
float				encoder_brv = 0;
float				brv[5] = {0,0,0,0,0};
float				blv[5] = {0,0,0,0,0};
extern			float targetSpeed_L;
extern			float targetSpeed_R;
float				targetSpeed_R_smooth = 0;
float				targetSpeed_L_smooth = 0;
float 			targetSpeed_R_buffer[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float 			targetSpeed_L_buffer[50] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

extern __IO uint16_t 		ADC_ConvertedValue[NOFCHANEL]; 	 
float 									ADC_ConvertedValueLocal[NOFCHANEL]; 


/*------------------------------------------------------------------------------------------------------------------------------------------------
定时中断：：100HZ / 10ms
-------------------------------------------------------------------------------------------------------------*/

void  BASIC_TIM_IRQHandler (void)
{
	if ( TIM_GetITStatus( BASIC_TIM, TIM_IT_Update) != RESET ) 
	{

		if(car_StatuLast != car_Statu)
		{
			FAST_STOP_L;
			FAST_STOP_R;
			car_StatuChangeCount++;
		}
		if(car_StatuChangeCount == 20)
		{
			car_StatuLast = car_Statu;
			switch(car_StatuLast)
			{
				case 0:
					FWD_R;
					FWD_L;
					break;
				case 1:
					FWD_R;
					REV_L;
					break;
				case 2:
					REV_R;
					FWD_L;
					break;
				case 3:
					REV_R;
					REV_L;
					break;
				case 4:
					break;
			}
			car_StatuChangeCount = 0;
		}
		
		// read the rotary encoders
		if(time1 % 2 == 0)
		{
			Count_bl = TIM4->CNT;
			Count_br = TIM5->CNT;
			TIM_SetCounter(TIM4, 30000);
			TIM_SetCounter(TIM5, 30000);
			for(j=3;j>=0;j--)
			{
				blv[j+1]=blv[j];
				brv[j+1]=brv[j];
			}
			brv[0]=0.25*(Count_br-30000)/0.02/12240*0.223;
			blv[0]=0.25*(Count_bl-30000)/0.02/12240*0.223;
			//加权滤波
			encoder_blv=0.4*(0.9*blv[0]+0.7*blv[1]+0.5*blv[2]+0.3*blv[3]+0.1*blv[4]);
			encoder_brv=0.4*(0.9*brv[0]+0.7*brv[1]+0.5*brv[2]+0.3*brv[3]+0.1*brv[4]);
			encoder_blv = encoder_blv>0?encoder_blv:-encoder_blv;
			encoder_brv = encoder_brv>0?encoder_brv:-encoder_brv;
			
			if(car_StatuLast == car_Statu)
			{
				for(i=49;i>0;i--)
				{
					targetSpeed_L_buffer[i] = targetSpeed_L_buffer[i-1];
					targetSpeed_R_buffer[i] = targetSpeed_R_buffer[i-1];
				}
				targetSpeed_L_buffer[0] = targetSpeed_L;
				targetSpeed_R_buffer[0] = targetSpeed_R;
				
				targetSpeed_L_smooth = 0;
				targetSpeed_R_smooth = 0;
				for(i=0;i<50;i++)
				{
					targetSpeed_L_smooth +=  targetSpeed_L_buffer[i];
					targetSpeed_R_smooth +=  targetSpeed_R_buffer[i];
				}
				targetSpeed_L_smooth /= 50;
				targetSpeed_R_smooth /= 50;
				
				Set_Speed(5,10000*(targetSpeed_L_smooth + PID_L(encoder_blv,targetSpeed_L_smooth)));
				Set_Speed(6,10000*(targetSpeed_R_smooth + PID_R(encoder_brv,targetSpeed_R_smooth)));
			}
			
		}

		
		//--------------------------------------
		if(time1 % 30 == 0)
		{
			LED1_TOGGLE;
			
			ADC_ConvertedValueLocal[0] =(float) ADC_ConvertedValue[0]/4096*3.3;
			ADC_ConvertedValueLocal[1] =(float) ADC_ConvertedValue[1]/4096*3.3;
			ADC_ConvertedValueLocal[2] =(float) ADC_ConvertedValue[2]/4096*3.3;
			ADC_ConvertedValueLocal[3] =(float) ADC_ConvertedValue[3]/4096*3.3;
			ADC_ConvertedValueLocal[4] =(float) ADC_ConvertedValue[4]/4096*3.3;
			ADC_ConvertedValueLocal[5] =(float) ADC_ConvertedValue[5]/4096*3.3;
			
			USART_SendData(Bluetooth_USART1,car_StatuLast);
			 	
		}
		
		if(/*time0 % 5 == 0 &&*/ Ctrl_Mode == 0){
			if(time2 < 255){
				if(msgBuffer[1] <= 127 && msgBuffer[2] <= 127){
					Set_TargetSpeed(msgBuffer[1]/127.0,msgBuffer[2]/127.0);
					car_Statu = 0;
				}else if(msgBuffer[1] > 127 && msgBuffer[2] <= 127){
					Set_TargetSpeed((255-msgBuffer[1])/127.0,msgBuffer[2]/127.0);
					car_Statu = 1;
				}else if(msgBuffer[1] <= 127 && msgBuffer[2] > 127){
					Set_TargetSpeed(msgBuffer[1]/127.0,(255-msgBuffer[2])/127.0);
					car_Statu = 2;
				}else{
					Set_TargetSpeed((255-msgBuffer[1])/127.0,(255-msgBuffer[2])/127.0);
					car_Statu = 3;
				}
			}else{
				Set_TargetSpeed(0,0);
				FAST_STOP_L;
				FAST_STOP_R;
				car_Statu = 4;
			}
		}
		
		time0++;
		time1++;
		if(time2 < 255)
			time2++;

		
		TIM_ClearITPendingBit(BASIC_TIM , TIM_FLAG_Update);  		 
	}
}


/*------------------------------------------------------------------------------------------------------------------------------------------------
定时中断：：100HZ / 10ms
接收TX2 RS485消息
-------------------------------------------------------------------------------------------------------------*/

void TX2_USART_IRQHandler(void) 
{
 
	if(USART_GetITStatus(TX2_USART3,USART_IT_RXNE)!=RESET)
	{	
		receiveData = USART_ReceiveData(TX2_USART3);
		LED2_TOGGLE;
		
		if(receiveData == 0xff || isTrueDataFlag != 0)
		{
			//接收报文内容
			msgBuffer[isTrueDataFlag] = receiveData;
			isTrueDataFlag++;
			if(isTrueDataFlag == 3){
				isTrueDataFlag = 0;	
			}
		}
		time2 = 0;
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
			Set_TargetSpeed(0.8,0.8);
			car_Statu = 0;
		}else if(ucTemp==49){
			Set_TargetSpeed(0.3,0.7);
			car_Statu = 1;
		}else if(ucTemp==50){
			Set_TargetSpeed(0.7,0.3);
			car_Statu = 2;
		}else if(ucTemp==51){
			Set_TargetSpeed(0.8,0.8);
			car_Statu = 3;
		}else if(ucTemp==52){
			Set_TargetSpeed(0,0);
			FAST_STOP_L;
			FAST_STOP_R;
			car_Statu = 4;
		}else if(ucTemp==53){
			Ctrl_Mode = 0;
			Set_TargetSpeed(0,0);
			FAST_STOP_L;
			FAST_STOP_R;
			car_Statu = 4;
		}else if(ucTemp==54){
			Ctrl_Mode = 1;
			Set_TargetSpeed(0,0);
			FAST_STOP_L;
			FAST_STOP_R;
			car_Statu = 4;
		}
	}
}

/**************************************************************END OF FILE**************************************************************/
