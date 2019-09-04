#include <stdio.h>
#include "TwoWayNoDummyLinkedList.h"

// �ʱ�ȭ
void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

// ������ �Է�
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node* )malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = plist->head; // head�� NULL�̶� NULL�� �ʱ�ȭ
	if (plist->head != NULL) // ������ ������ ��尡 �ִ� ���
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

// ù ��° Ȯ��
int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

// ���� Ȯ��
int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

// ���� Ȯ��
int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

// ������ �� Ȯ��
int LCount(List* plist)
{
	return plist->numOfData;
}
