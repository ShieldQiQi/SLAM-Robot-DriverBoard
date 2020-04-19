#ifndef __MSG_QUEUE
#define __MSG_QUEUE

#include "stm32f10x.h"
#include <stdio.h>
#include <stdlib.h>


/*单链队列－－队列的链式存储结构 */
typedef struct QNode
{
	uint16_t	theta[6];
	struct	 	QNode *next;
}QNode,*QueuePtr;



typedef struct
{
	QueuePtr front,rear; 
}LinkQueue;


uint8_t InitQueue(LinkQueue *Q);

uint8_t DestroyQueue(LinkQueue *Q);

uint8_t ClearQueue(LinkQueue *Q);

uint8_t is_QueueEmpty(LinkQueue Q);

uint8_t QueueLength(LinkQueue Q);

uint8_t Push(LinkQueue *Q,uint16_t theta[6]);

uint8_t pop(LinkQueue *Q);

uint8_t QueueTraverse(LinkQueue Q);

uint8_t Init_usartMsg_Queue(void);


#endif  /*__MSG_QUEUE*/












