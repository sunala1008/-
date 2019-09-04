#include <stdio.h>
#include "TwoWayNoDummyLinkedList.h"

// 초기화
void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

// 데이터 입력
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node* )malloc(sizeof(Node));

	newNode->data = data;

	newNode->next = plist->head; // head가 NULL이라 NULL로 초기화
	if (plist->head != NULL) // 기존에 데이터 노드가 있는 경우
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

// 첫 번째 확인
int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	*pdata = plist->cur->data;

	return TRUE;
}

// 이전 확인
int LPrevious(List* plist, Data* pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

// 다음 확인
int LNext(List* plist, Data* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

// 데이터 수 확인
int LCount(List* plist)
{
	return plist->numOfData;
}
