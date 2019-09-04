#include <stdio.h>
#include <stdlib.h>
#include "LinkedListStack.h"

/*
	 ▶ Stack ◀
	  - LIFO (Last In First Out) 후입선출

	  - Linked List를 기반으로 한 코드
*/

// Stack 초기화
void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

// Stack에 데이터 입력 (Push)
void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pstack->head;
	pstack->head = newNode;

	printf("Push(%d)", data);
}

// Stack에 데이터 출력 (Pop)
// 출력이라 리턴되야 하므로 자료형은 Data
Data SPop(Stack* pstack)
{
	Node* newNode;
	int data;

	// newNode를 head로 설정
	newNode = pstack->head;

	// 꺼낼 data값은 newNode의 data
	data = newNode->data;

	// head를 newNode의 next로
	pstack->head = newNode->next;
	
	// 메모리 해제
	free(newNode);

	return data;
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