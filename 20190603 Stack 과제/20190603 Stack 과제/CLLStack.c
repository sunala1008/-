#include <stdio.h>
#include <stdlib.h>
#include "CLLStack.h"

// Stack 초기화
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
	pstack->tail = NULL;
}

// Stack에 데이터 입력 (Push)
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
		// 데이터노드가 2개 일때야
		// newNode->next = pstack->tail->next;
		// 가 말이됨. 데이터노드가 늘어날 수록
		// 정확?하게 집어주려면 tail->next라고 해야 함
		pstack->head = newNode;
		pstack->tail->next = pstack->head;
	}
	
	printf("Push(%d) ", data);
}

// Stack에 데이터 출력 (Pop)
// 출력이라 리턴되야 하므로 자료형은 Data
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
		
// Stack이 비어있는지 확인 (IsEmpty)
// True False 리턴
int SIsEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}