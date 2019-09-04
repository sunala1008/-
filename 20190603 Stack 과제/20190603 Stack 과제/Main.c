#include <stdio.h>
#include <stdlib.h>
#include "CLLStack.h"

/*
	���� 5/29(��)�� �����ߴ�, ������ũ�帮��Ʈ�� ����Ͽ�, Stack �ڷᱸ���� ����

	������ �Լ��� �Ʒ��� ����ϵ��� ����
*/

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	// ������ �ֱ�
	SPush(&stack, 1);  
	SPush(&stack, 2);
	SPush(&stack, 3);  
	SPush(&stack, 4);
	SPush(&stack, 5);

	printf("\n");

	// ������ ������
	while (!SIsEmpty(&stack))
		printf("Pop(%d) ", SPop(&stack));

	return 0;
}