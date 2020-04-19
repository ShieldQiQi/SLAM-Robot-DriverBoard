/*
Author:SHIELD_QI
Date:2019-12-19
************************************/

#include "msg_queue.h"
#include "usart.h"
#include "blue_tooth.h"

LinkQueue thetaArray_Queue;

/*�������*/
uint8_t InitQueue(LinkQueue *Q)
{
	Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		return 0;
	Q->front->next=NULL;
	return 1;
}

/*���ٶ���*/
uint8_t DestroyQueue(LinkQueue *Q)
{ 
	while((*Q).front)
	{
	 Q->rear=Q->front->next;
	 free(Q->front);
	 Q->front=Q->rear;
	}
	return 1;
}

/*��ն���*/
uint8_t ClearQueue(LinkQueue *Q)
{ 
	QueuePtr p,q;
	Q->rear=Q->front;
	p=Q->front->next;
	Q->front->next=NULL;
	while(p)
	{
	 q=p;
	 p=p->next;
	 free(q);
	}
	return 1;
}

/*����Ϊ�շ���1�����򷵻�0*/
uint8_t is_QueueEmpty(LinkQueue Q)
{ 
	if(Q.front==Q.rear)
	 return 1;
	else
	 return 0;
}

/*���ض��г���*/
uint8_t QueueLength(LinkQueue Q)
{ 
	int i=0;
	QueuePtr p;
	p=Q.front;
	while(Q.rear!=p)
	{
	 i++;
	 p=p->next;
	}
	return i;
}

/*������*/
uint8_t Push(LinkQueue *Q,uint16_t theta[6])
{ 
	int i;
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return 0;
	for(i=0;i<6;i++)
		p->theta[i] = theta[i];
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
	return 1;
}
/*������*/
uint8_t pop(LinkQueue *Q)
{ 
	QueuePtr p;
	if(Q->front==Q->rear)
	 return 0;
	p=Q->front->next;

	Q->front->next=p->next;
	if(Q->rear==p)
	 Q->rear=Q->front;
	free(p);
	return 1;
}

/*��������*/
uint8_t QueueTraverse(LinkQueue Q)
{ 
	QueuePtr p;
	p=Q.front->next;
	while(p)
	{
	  p=p->next;
	}
	return 1;
}

uint8_t Init_usartMsg_Queue(void)
{
	//��ʼ������
	if(!(InitQueue(&thetaArray_Queue)))
		return 0;
	return 1;
}

















