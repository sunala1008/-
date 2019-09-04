#ifndef _DEQUE_H_
#define _DEQUE_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;
	struct _node* pref;
	// ������� ���� next�� pref�� ����
} Node;

typedef struct _linkedListDeque
{
	Node* head;
	Node* tail;
} LinkedListDeque;

typedef LinkedListDeque Deque;

// �ʱ�ȭ
void DequeInit(Deque* pd);

// Deque�� ����ִ��� Ȯ��
int DequeIsEmpty(Deque* pd);

// Node�� �տ��� �ִ� �Լ�
void DequeAddHead(Deque* pd, Data data);

// Node�� �ڿ��� �ִ� �Լ�
void DequeAddTail(Deque* pd, Data data);

// Node�� �տ��� �������� �Լ�
Data DequeRemoveHead(Deque* pd);

// Node�� �ڿ��� �������� �Լ�
Data DequeRemoveTail(Deque* pd);

// ù��° �����͸� �������� �Լ�
Data DequeGetFirst(Deque* pd);

// ������ �����͸� �������� �Լ�
Data DequeGetLast(Deque* pd);

#endif // !_DEQUE_H_
