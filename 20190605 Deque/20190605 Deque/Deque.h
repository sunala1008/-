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
	// 양방향을 위해 next와 pref를 만듦
} Node;

typedef struct _linkedListDeque
{
	Node* head;
	Node* tail;
} LinkedListDeque;

typedef LinkedListDeque Deque;

// 초기화
void DequeInit(Deque* pd);

// Deque이 비어있는지 확인
int DequeIsEmpty(Deque* pd);

// Node를 앞에서 넣는 함수
void DequeAddHead(Deque* pd, Data data);

// Node를 뒤에서 넣는 함수
void DequeAddTail(Deque* pd, Data data);

// Node를 앞에서 가져오는 함수
Data DequeRemoveHead(Deque* pd);

// Node를 뒤에서 가져오는 함수
Data DequeRemoveTail(Deque* pd);

// 첫번째 데이터를 가져오는 함수
Data DequeGetFirst(Deque* pd);

// 마지막 데이터를 가져오는 함수
Data DequeGetLast(Deque* pd);

#endif // !_DEQUE_H_
