#include <stdio.h>
#include <stdlib.h>
//#include "ArrayStack.h"			// 배열 기반의 Stack
#include "LinkedListStack.h"	// 링크드 리스트 기반의 Stack

// 메인은 똑같음

int main()
{
	// 스택의 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	// 스택에 데이터 입력
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	printf("\n");

	// 스택의데이터 출력
	while (!SIsEmpty(&stack)) // 비어있지 않으면 출력 ☆
		printf("Pop(%d) ", SPop(&stack));
	
	return 0;
}