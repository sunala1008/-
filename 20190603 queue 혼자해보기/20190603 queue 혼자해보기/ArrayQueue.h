#ifndef _QUEUE_H_
#define _QUEUE_H_

#define QUEUE_SIZE 50

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _arrayQueue
{
	Data queueArray[QUEUE_SIZE];

	int topIndex;
} ArrayQueue;

typedef ArrayQueue Queue;

// 초기화
void QueueInIt(Queue* pqueue);

// Queue에 데이터 입력 (Push)
void QPush(Queue* pqueue, Data data);

// Queue에 데이터 출력 (Pop)
void QPop(Queue* pqueue);

// Queue가 비었는지 확인
int QIsEmpty(Queue* pqueue);

#endif // !_QUEUE_H_
