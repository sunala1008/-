#include <stdio.h>
#include "TwoWayNoDummyLinkedList.h"

int main(void)
{
	// 양방향 연걸 리스트의 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 양방향 연결 리스트에 데이터 저장
	LInsert(&list, 1);	LInsert(&list, 2);
	LInsert(&list, 3);	LInsert(&list, 4);
	LInsert(&list, 5);	LInsert(&list, 6);
	LInsert(&list, 7);	LInsert(&list, 8);

	// 이게 지금 head의 앞에 추가되는거라서, head는 8이됨

	// 저장된 데이터 조회 및 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // 뒤로
			printf("%d ", data);    // 그래서 얘는 8부터 시작함
		
		printf("\nLNext 종료\n\n");

		// 아~ 갔다 오는거 ㅋㅋ 1은 출력 안하고 ㅋㅋ
		// 근데 
		// printf("%d ", data);
		// 이거 넣으면 1 나옴 ㅋㅋ
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\nLPrevious 종료\n\n");
	}

	return 0;
}