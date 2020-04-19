/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 
	
#include "blue_tooth.h"

//串口1初始化配置
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	DEBUG_USART1_GPIO_APBxClkCmd(DEBUG_USART1_GPIO_CLK, ENABLE);
	DEBUG_USART1_APBxClkCmd(DEBUG_USART1_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin = DEBUG_USART1_TX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART1_TX_GPIO_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = DEBUG_USART1_RX_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DEBUG_USART1_RX_GPIO_PORT, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = DEBUG_USART1_BAUDRATE;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(Bluetooth_USART1, &USART_InitStructure);
	
	USART_ITConfig(Bluetooth_USART1, USART_IT_RXNE, ENABLE);	
	
	USART_Cmd(Bluetooth_USART1, ENABLE);		

  // 清除发送完成标志
	//USART_ClearFlag(USART1, USART_FLAG_TC);     
}

///重定向c库函数printf到串口，重定向后可使用printf函数
//int fputc(int ch, FILE *f)
//{
//	USART_SendData(Bluetooth_USART1, (uint8_t) ch);
//	
//	while (USART_GetFlagStatus(Bluetooth_USART1, USART_FLAG_TXE) == RESET);		

//	return (ch);
//}

/////重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
//int fgetc(FILE *f)
//{
//		while (USART_GetFlagStatus(Bluetooth_USART1, USART_FLAG_RXNE) == RESET);

//		return (int)USART_ReceiveData(Bluetooth_USART1);
//}

/************************END OF FILE********************/

