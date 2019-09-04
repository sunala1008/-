#include <stdio.h>
#include <stdlib.h>
#include "McDonald.h"

void QueueInit(Queue* pq)
{
	// Queue ����� ������ ���ó�� �׸�����!

	// front�� rear�� �迭�� [0]�� ����Ű���� ��
	// => ť�� empty ���·� �ʱ�ȭ
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear) // ť�� ����ִ� ���
		return TRUE;
	else
		return FALSE;
}

// �迭�� ��ġ�� �̵��ϴ� �Լ� => ���� �迭 ��� Queue�� �ٽ�
int NextMovePosition(int pos)
{
	if (pos == QUEUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) // ������ �Է� => ��������
{
	// front�� rear(����)�� 1�� ���̸� ������ full����
	if (NextMovePosition(pq->rear) == pq->front)
	{
		printf("Queue�� ��������� �����ϴ�.");
		exit(-1);
	}

	pq->rear = NextMovePosition(pq->rear);
	pq->queueArr[pq->rear] = data;

	//printf("In(%d) ", data);
}

Data Dequeue(Queue* pq) // ������ ��� => ���Լ��� FIFO
{
	if (QIsEmpty(pq))
	{
		printf("Queue�� ����� �����Ͱ� �����ϴ�.");
		exit(-1);
	}

	// FIFO�� �ǵ��� front�� ��ġ�� �̵���Ŵ
	pq->front = NextMovePosition(pq->front);

	return pq->queueArr[pq->front];
}