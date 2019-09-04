#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// 초기화
void QueueInIt(Queue* pqueue)
{
	pqueue->topIndex = -1;
}

// Queue에 데이터 입력 (Push)
void QPush(Queue* pqueue, Data data)
{
	pqueue->queueArray[++pqueue->topIndex] = data;

	printf("Push(%d) ", data);
}

// Queue에 데이터 출력 (Pop)
void QPop(Queue* pqueue)
{
	int idx;

	if (QIsEmpty(pqueue))
	{
		printf("Queue가 비어있습니다.");
		exit(-1);
	}

	idx = pqueue->topIndex;

	for (int i = 1; i <= idx + 1; i++)
		printf("Pop(%d) ", i);
}

// Queue가 비었는지 확인
int QIsEmpty(Queue* pqueue)
{
	if (pqueue->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}