#ifndef _CIRCULAR_QUEUE_H_
#define _CIRCULAR_QUEUE_H_

#define QUEUE_LEN 50

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _circularQueue
{
	int front;
	int rear;
	Data queueArr[QUEUE_LEN];
} CircualarQueue;

typedef CircualarQueue Queue;

void QueueInit(Queue* pq);

int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);

Data Dequeue(Queue* pq);

// 배열의 위치를 이동하는 함수
int NextMovePosition(int pos);

#endif // !_CIRCULAR_QUEUE_H_
