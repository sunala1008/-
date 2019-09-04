#include <stdio.h>
#include "TwoWayDummyLinkedList.h"

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
	printf("저장된 갯수 : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // 뒤로
			printf("%d ", data);

		printf("\n\n");
	}

	// 3의 배수를 가진 데이터 노드 삭제
	printf("3의 배수를 가진 데이터 노드 삭제 시작\n");
	if (LFirst(&list, &data))
	{
		if (data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 3 == 0)
				LRemove(&list);
		}
	}

	printf("\n3의 배수를 가진 데이터 노드 삭제 종료\n\n");

	// 삭제된 데이터 확인용 출력
	printf("저장된 갯수 : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // 뒤로
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}	