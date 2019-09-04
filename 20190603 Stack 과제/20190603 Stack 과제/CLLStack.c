#include <stdio.h>
#include <stdlib.h>
#include "CLLStack.h"

// Stack �ʱ�ȭ
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	pstack->tail = NULL;
}

// Stack�� ������ �Է� (Push)
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (pstack->tail == NULL)
	{
		pstack->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = pstack->tail->next;
		// �����ͳ�尡 2�� �϶���
		// newNode->next = pstack->tail->next;
		// �� ���̵�. �����ͳ�尡 �þ ����
		// ��Ȯ?�ϰ� �����ַ��� tail->next��� �ؾ� ��
		pstack->head = newNode;
		pstack->tail->next = pstack->head;
	}
	
	printf("Push(%d) ", data);
}

// Stack�� ������ ��� (Pop)
// ����̶� ���ϵǾ� �ϹǷ� �ڷ����� Data
Data SPop(Stack* pstack)
{
	Node* popNode = pstack->head;
	Data popData = popNode->data;

	if (pstack->head == pstack->tail)
		pstack->head = NULL;
	else
		pstack->head = pstack->head->next;

	free(popNode);

	return popData;
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