/*******************************************************************
*	Date:2019-03-23
*	Author:SHIELD_QIQI
*	Project:E:six-axis manipulator
*****************************************/ 
	
#include "blue_tooth.h"

//����1��ʼ������
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

  // ���������ɱ�־
	//USART_ClearFlag(USART1, USART_FLAG_TC);     
}

///�ض���c�⺯��printf�����ڣ��ض�����ʹ��printf����
//int fputc(int ch, FILE *f)
//{
//	USART_SendData(Bluetooth_USART1, (uint8_t) ch);
//	
//	while (USART_GetFlagStatus(Bluetooth_USART1, USART_FLAG_TXE) == RESET);		

//	return (ch);
//}

/////�ض���c�⺯��scanf�����ڣ���д����ʹ��scanf��getchar�Ⱥ���
//int fgetc(FILE *f)
//{
//		while (USART_GetFlagStatus(Bluetooth_USART1, USART_FLAG_RXNE) == RESET);

//		return (int)USART_ReceiveData(Bluetooth_USART1);
//}

/************************END OF FILE********************/

