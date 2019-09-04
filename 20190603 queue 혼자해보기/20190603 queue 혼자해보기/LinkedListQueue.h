#ifndef _QUEUE_H_
#define _QUEUE_H_

#define QUEUE_SIZE 50

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
} Node;

typedef struct _linkedListQueue
{
	Node* head;
} LinkedListQueue;

typedef LinkedListQueue Queue;

// 초기화
void QueueInIt(Queue* pqueue);

// Queue에 데이터 입력 (Push)
void QPush(Queue* pqueue, Data data);

// Queue에 데이터 출력 (Pop)
int QPop(Queue* pqueue);

// Queue가 비었는지 확인
int QIsEmpty(Queue* pqueue);

#endif // !_QUEUE_H_
