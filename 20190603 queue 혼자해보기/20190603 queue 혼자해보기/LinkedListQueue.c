#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

// 원형큐와 링크드큐 중 링크드큐가 훨씬 연산측면?에서 쌈(?)ㅋㅋ

// 초기화
void QueueInIt(Queue* pqueue)
{
	pqueue->head = NULL;
}

// Queue에 데이터 입력 (Push)
void QPush(Queue* pqueue, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (pqueue->head == NULL)
		newNode = pqueue->head;
	else
	{

	}


	//if (pqueue->head == NULL)
	//	pqueue->head = newNode;
	//	//newNode = pqueue->head;
	//else
	//{
	//	//newNode = pqueue->head->next;
	//	pqueue->head->next = newNode;
	//	newNode->next = newNode;
	//}
	
	printf("Push(%d) ", data);
}

// Queue에 데이터 출력 (Pop)
int QPop(Queue* pqueue)
{
	Node* popNode = pqueue->head;
	int data = popNode->data;

	/*if (QIsEmpty(pqueue))
	{
		printf("Queue가 비어있습니다.");
		exit(-1);
	}

	
	popNode->next = pqueue->head->next;
	pqueue->head->next = pqueue->head;

	free(popNode);*/

	return data;
}

// Queue가 비었는지 확인
int QIsEmpty(Queue* pqueue)
{
	if (pqueue->head == NULL)
		return TRUE;
	else
		return FALSE;
}
