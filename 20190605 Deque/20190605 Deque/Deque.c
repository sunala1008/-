#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// �ʱ�ȭ
void DequeInit(Deque* pd)
{
	pd->head = NULL;
	pd->tail = NULL;
}

// Deque�� ����ִ��� Ȯ��
int DequeIsEmpty(Deque* pd)
{
	if (pd->head == NULL)
		return TRUE;
	else
		return FALSE;
}

// Node�� �տ��� �ִ� �Լ�
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

// Node�� �ڿ��� �ִ� �Լ�
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

// Node�� �տ��� �������� �Լ�
Data DequeRemoveHead(Deque* pd)
{
	Node* removeNode = pd->head;
	Data removeData = pd->head->data;

	if (DequeIsEmpty(pd))
	{
		printf("Deque�� ����� Node�� �����ϴ�.");
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

// Node�� �ڿ��� �������� �Լ�
Data DequeRemoveTail(Deque* pd)
{
	Node* removeNode = pd->tail;
	Data removeData = pd->tail->data;

	if (DequeIsEmpty(pd))
	{
		printf("Deque�� ����� Node�� �����ϴ�.");
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

// ù��° �����͸� �������� �Լ�
Data DequeGetFirst(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("Deque�� ����� Node�� �����ϴ�.");
		exit(-1);
	}
	
	return pd->head->data;
}

// ������ �����͸� �������� �Լ�
Data DequeGetLast(Deque* pd)
{
	if (DequeIsEmpty(pd))
	{
		printf("Deque�� ����� Node�� �����ϴ�.");
		exit(-1);
	}
	
	return pd->tail->data;
}