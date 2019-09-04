#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

int main(void)
{
	// �� ���� �� �ʱ�ȭ
	Deque deque;
	DequeInit(&deque);
	int data;

	// �Ӹ��� Node �߰�
	DequeAddHead(&deque, 1);
	DequeAddHead(&deque, 2);
	DequeAddHead(&deque, 3);

	// ����� Node�� ������ ���
	while (!DequeIsEmpty(&deque))
		printf("%d ", DequeRemoveHead(&deque));

	printf("\n\n");

	// ������ Node �߰�
	DequeAddTail(&deque, 4);
	DequeAddTail(&deque, 5);
	DequeAddTail(&deque, 6);

	// ����� Node�� ������ ���
	while (!DequeIsEmpty(&deque))
		printf("%d ", DequeRemoveTail(&deque));

	printf("\n\n");

	return 0;
}