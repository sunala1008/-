#include <stdio.h>
#include <stdlib.h>
// #include "ArrayQueue.h"
#include "LinkedListQueue.h"

int main(void)
{
	// ť ���� �� �ʱ�ȭ
	Queue queue;
	QueueInIt(&queue);

	// ť�� ������ �Է�
	QPush(&queue, 1);
	QPush(&queue, 2);
	QPush(&queue, 3);
	QPush(&queue, 4);
	QPush(&queue, 5);

	printf("\n");

	// ť�� ������ ���
	// QPop(&queue); // ArrayQueue
	while (!QIsEmpty(&queue))
		printf("Pop(%d) ", QPop(&queue));

	return 0;
}