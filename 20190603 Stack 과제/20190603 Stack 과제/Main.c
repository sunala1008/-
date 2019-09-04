#include <stdio.h>
#include <stdlib.h>
#include "CLLStack.h"

/*
	지난 5/29(수)에 구현했던, 원형링크드리스트를 사용하여, Stack 자료구조를 구현

	메인의 함수는 아래를 사용하도록 구현
*/

int main(void)
{
	// Stack의 생성 및 초기화
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기
	SPush(&stack, 1);  
	SPush(&stack, 2);
	SPush(&stack, 3);  
	SPush(&stack, 4);
	SPush(&stack, 5);

	printf("\n");

	// 데이터 꺼내기
	while (!SIsEmpty(&stack))
		printf("Pop(%d) ", SPop(&stack));

	return 0;
}