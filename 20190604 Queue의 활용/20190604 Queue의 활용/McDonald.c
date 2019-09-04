#include <stdio.h>
#include <stdlib.h>
#include "McDonald.h"

void QueueInit(Queue* pq)
{
	// Queue 모양을 도너츠 모양처럼 그리셨음!

	// front와 rear이 배열의 [0]을 가리키도록 함
	// => 큐를 empty 상태로 초기화
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear) // 큐가 비어있는 경우
		return TRUE;
	else
		return FALSE;
}

// 배열의 위치를 이동하는 함수 => 원형 배열 기반 Queue의 핵심
int NextMovePosition(int pos)
{
	if (pos == QUEUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data) // 데이터 입력 => 꼬리기준
{
	// front와 rear(꼬리)가 1의 차이를 가져야 full상태
	if (NextMovePosition(pq->rear) == pq->front)
	{
		printf("Queue에 저장공간이 없습니다.");
		exit(-1);
	}

	pq->rear = NextMovePosition(pq->rear);
	pq->queueArr[pq->rear] = data;

	//printf("In(%d) ", data);
}

Data Dequeue(Queue* pq) // 데이터 출력 => 선입선출 FIFO
{
	if (QIsEmpty(pq))
	{
		printf("Queue에 저장된 데이터가 없습니다.");
		exit(-1);
	}

	// FIFO가 되도록 front의 위치를 이동시킴
	pq->front = NextMovePosition(pq->front);

	return pq->queueArr[pq->front];
}