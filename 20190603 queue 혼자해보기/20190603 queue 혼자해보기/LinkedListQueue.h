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

// �ʱ�ȭ
void QueueInIt(Queue* pqueue);

// Queue�� ������ �Է� (Push)
void QPush(Queue* pqueue, Data data);

// Queue�� ������ ��� (Pop)
int QPop(Queue* pqueue);

// Queue�� ������� Ȯ��
int QIsEmpty(Queue* pqueue);

#endif // !_QUEUE_H_
