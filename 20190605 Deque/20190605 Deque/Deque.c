#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 초기화
void DequeInit(Deque* pd)
{
	pd->head = NULL;
	pd->tail = NULL;
}

// Deque이 비어있는지 확인
int DequeIsEmpty(Deque* pd)
{
	if (pd->head == NULL)
		return TRUE;
	else
		return FALSE;
}

// Node를 앞에서 넣는 함수
void DequeAddHead(Deque* pd, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pd->head;

	if (DequeIsEmpty(pd))
		pd->tail = newNode;
	else
		pd->head->pref = newNode;

	newNode->pref = NULL;
	pd->head = newNode;
}

// Node를 뒤에서 넣는 함수
void DequeAddTail(Deque* pd, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->pref = pd->tail;

	if (DequeIsEmpty(pd))
		pd->head = newNode;
	else
		pd->tail->next = newNode;

	newNode->next = NULL;
	pd->tail = newNode;
}

// Node를 앞에서 가져오는 함수
Data DequeRemoveHead(Deque* pd)
{
	Node* removeNode = pd->head;
	Data removeData = pd->head->data;

	if (DequeIsEmpty(pd))
	{
		printf("Deque에 저장된 Node가 없습니다.");
		exit(-1);
	}

	pd->head = pd->head->next;
	
	free(removeNode);

	if (pd->head == NULL)
		pd->tail = NULL;
	else
		pd->head->pref = NULL;

	return removeData;
}

// Node를 뒤에서 가져오는 함수
Data DequeRemoveTail(Deque* pd)
{
	Node* removeNode = pd->tail;
	Data removeData = pd->tail->data;

	if (DequeIsEmpty(pd))
	{
		printf("Deque에 저장된 Node가 없습니다.");
		exit(-1);
	}

	pd->tail = pd->tail->pref;

	free(removeNode);

	if (pd->tail == NULL)
		pd->head = NULL;
	else
		pd->tail->next = NULL;

	return removeData;
}

// 첫번째 데이터를 가져오는 함수
Data DequeGetFirst(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("Deque에 저장된 Node가 없습니다.");
		exit(-1);
	}
	
	return pd->head->data;
}

// 마지막 데이터를 가져오는 함수
Data DequeGetLast(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("Deque에 저장된 Node가 없습니다.");
		exit(-1);
	}
	
	return pd->tail->data;
}