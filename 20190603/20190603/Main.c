#include <stdio.h>
#include <stdlib.h>
//#include "ArrayStack.h"			// �迭 ����� Stack
#include "LinkedListStack.h"	// ��ũ�� ����Ʈ ����� Stack

// ������ �Ȱ���

int main()
{
	// ������ ���� �� �ʱ�ȭ
	Stack stack;
	StackInit(&stack);

	// ���ÿ� ������ �Է�
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	printf("\n");

	// �����ǵ����� ���
	while (!SIsEmpty(&stack)) // ������� ������ ��� ��
		printf("Pop(%d) ", SPop(&stack));
	
	return 0;
}