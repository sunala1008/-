#include <stdio.h>
#include <stdlib.h>
#include "LinkedListQueue.h"

// ����ť�� ��ũ��ť �� ��ũ��ť�� �ξ� ��������?���� ��(?)����

// �ʱ�ȭ
void QueueInIt(Queue* pqueue)
{
	pqueue->head = NULL;
}

// Queue�� ������ �Է� (Push)
void QPush(Queue* pqueue, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (pqueue->head == NULL)
		newNode = pqueue->head;
	else
	{

	}


	//if (pqueue->head == NULL)
	//	pqueue->head = newNode;
	//	//newNode = pqueue->head;
	//else
	//{
	//	//newNode = pqueue->head->next;
	//	pqueue->head->next = newNode;
	//	newNode->next = newNode;
	//}
	
	printf("Push(%d) ", data);
}

// Queue�� ������ ��� (Pop)
int QPop(Queue* pqueue)
{
	Node* popNode = pqueue->head;
	int data = popNode->data;

	/*if (QIsEmpty(pqueue))
	{
		printf("Queue�� ����ֽ��ϴ�.");
		exit(-1);
	}

	
	popNode->next = pqueue->head->next;
	pqueue->head->next = pqueue->head;

	free(popNode);*/

	return data;
}

// Queue�� ������� Ȯ��
int QIsEmpty(Queue* pqueue)
{
	if (pqueue->head == NULL)
		return TRUE;
	else
		return FALSE;
}
