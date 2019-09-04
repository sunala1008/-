#include <stdio.h>
#include <stdlib.h>
// #include "ArrayQueue.h"
#include "LinkedListQueue.h"

int main(void)
{
	// 큐 생성 및 초기화
	Queue queue;
	QueueInIt(&queue);

	// 큐에 데이터 입력
	QPush(&queue, 1);
	QPush(&queue, 2);
	QPush(&queue, 3);
	QPush(&queue, 4);
	QPush(&queue, 5);

	printf("\n");

	// 큐의 데이터 출력
	// QPop(&queue); // ArrayQueue
	while (!QIsEmpty(&queue))
		printf("Pop(%d) ", QPop(&queue));

	return 0;
}