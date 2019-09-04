#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main(void)
{
	// 덱 생성 및 초기화
	Deque deque;
	DequeInit(&deque);
	int data;

	// 머리에 Node 추가
	DequeAddHead(&deque, 1);
	DequeAddHead(&deque, 2);
	DequeAddHead(&deque, 3);

	// 저장된 Node의 데이터 출력
	while (!DequeIsEmpty(&deque))
		printf("%d ", DequeRemoveHead(&deque));

	printf("\n\n");

	// 꼬리에 Node 추가
	DequeAddTail(&deque, 4);
	DequeAddTail(&deque, 5);
	DequeAddTail(&deque, 6);

	// 저장된 Node의 데이터 출력
	while (!DequeIsEmpty(&deque))
		printf("%d ", DequeRemoveTail(&deque));

	printf("\n\n");

	return 0;
}