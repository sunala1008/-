#include <stdio.h>
//#include "CircularQueue.h"
#include "LinkedListQueue.h"

int main(void)
{
	// Queue 생성 및 초기화
	Queue queue;
	QueueInit(&queue);

	// Queue에 데이터 추가 및 저장
	Enqueue(&queue, 1);
	Enqueue(&queue, 2);
	Enqueue(&queue, 3);
	Enqueue(&queue, 4);
	Enqueue(&queue, 5);

	printf("\n");

	// Queue엣 데이터 출력
	while (!QIsEmpty(&queue))
		printf("Out(%d) ", Dequeue(&queue));

	return 0;
}