#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}

	printf("In(%d) ", data);
}

Data Dequeue(Queue* pq)
{
	Node* removeNode;
	Data removeData;

	if (QIsEmpty(pq))
	{
		printf("삭제할 Node가 없습니다.");
		exit(-1);
	}

	removeNode = pq->front;
	removeData = removeNode->data; // 일단 데이터 백업

	// front를 다음 Node를 가르키도록 함
	pq->front = pq->front->next;

	free(removeNode);

	return removeData;
}
