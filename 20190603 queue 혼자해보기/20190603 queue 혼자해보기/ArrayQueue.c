#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

// �ʱ�ȭ
void QueueInIt(Queue* pqueue)
{
	pqueue->topIndex = -1;
}

// Queue�� ������ �Է� (Push)
void QPush(Queue* pqueue, Data data)
{
	pqueue->queueArray[++pqueue->topIndex] = data;

	printf("Push(%d) ", data);
}

// Queue�� ������ ��� (Pop)
void QPop(Queue* pqueue)
{
	int idx;

	if (QIsEmpty(pqueue))
	{
		printf("Queue�� ����ֽ��ϴ�.");
		exit(-1);
	}

	idx = pqueue->topIndex;

	for (int i = 1; i <= idx + 1; i++)
		printf("Pop(%d) ", i);
}

// Queue�� ������� Ȯ��
int QIsEmpty(Queue* pqueue)
{
	if (pqueue->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}