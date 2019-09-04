#include <stdio.h>
#include <stdlib.h>
#include "LinkedListStack.h"

/*
	 �� Stack ��
	  - LIFO (Last In First Out) ���Լ���

	  - Linked List�� ������� �� �ڵ�
*/

// Stack �ʱ�ȭ
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

// Stack�� ������ �Է� (Push)
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pstack->head;
	pstack->head = newNode;

	printf("Push(%d)", data);
}

// Stack�� ������ ��� (Pop)
// ����̶� ���ϵǾ� �ϹǷ� �ڷ����� Data
Data SPop(Stack* pstack)
{
	Node* newNode;
	int data;

	// newNode�� head�� ����
	newNode = pstack->head;

	// ���� data���� newNode�� data
	data = newNode->data;

	// head�� newNode�� next��
	pstack->head = newNode->next;
	
	// �޸� ����
	free(newNode);

	return data;
}

// Stack�� ����ִ��� Ȯ�� (IsEmpty)
// True False ����
int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}