#ifndef _LINKED_LIST_QUEUE_H_
#define _LINKED_LIST_QUEUE_H_

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
	Node* front;
	Node* rear;
} LinkedListQueue;

typedef LinkedListQueue Queue;

void QueueInit(Queue* pq);

int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);

Data Dequeue(Queue* pq);

// 배열의 위치를 이동하는 함수
int NextMovePosition(int pos);



#endif // !_LINKED_LIST_QUEUE_H_
