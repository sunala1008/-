#include <stdio.h>
//#include "CircularQueue.h"
#include "LinkedListQueue.h"

int main(void)
{
	// Queue ���� �� �ʱ�ȭ
	Queue queue;
	QueueInit(&queue);

	// Queue�� ������ �߰� �� ����
	Enqueue(&queue, 1);
	Enqueue(&queue, 2);
	Enqueue(&queue, 3);
	Enqueue(&queue, 4);
	Enqueue(&queue, 5);

	printf("\n");

	// Queue�� ������ ���
	while (!QIsEmpty(&queue))
		printf("Out(%d) ", Dequeue(&queue));

	return 0;
}