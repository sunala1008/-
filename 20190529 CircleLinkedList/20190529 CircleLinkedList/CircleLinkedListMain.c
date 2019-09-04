#include <stdio.h>
#include "CircleLinkedList.h"

// 원형 링크드 리스트는 머리와 꼬리를 기준으로 하는 두 가지 방법이 있는데,
// 또 거기에서도 꼬리앞에다 넣거나 꼬리 뒤에다 넣거나...? 하는 두가지가 또있어?!
// 여튼 모르겠고 꼬리를 기준잡고 하는 코드래

int main(void)
{
	// 1. List의 생성, 초기화
	List list;
	int data;
	
	// 원형 리스트는 반복해서 출력이 되므로 반복 제어 변수를 추가
	int stop;

	ListInit(&list);

	// 2. 데이터 저장
	// 꼬리로 노드를 추가
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	// 머리로 노드를 추가
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 3. 저장된 데이터를 2회만 출력
	if (LFirst(&list, &data)) // 데이터 노드가 있는지 체크
	{
		printf("%d ", data);

		for (stop = 0; stop < LCount(&list) * 2 - 1; stop++) 
		{ // LCount(&list) - 1 : 위에서 한 번 출력해서
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	printf("\n\n");

	// 4. 데이터 삭제
	if (LFirst(&list, &data))
	{
		if (data == 2)
		{
			LRemove(&list);
			printf("%d 삭제 완료\n", data);
		}

		while (LNext(&list, &data))
		{
			if (data == 2)
			{ 
				LRemove(&list);
				printf("%d 삭제 완료\n", data);
				break;
			}
			
		}
	}
	
	// 5. 삭제 확인용 재출력 - 1회전만
	if (LFirst(&list, &data)) // 데이터 노드가 있는지 체크
	{
		printf("%d ", data);

		for (stop = 0; stop < LCount(&list) - 1; stop++)
		{
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	return 0;
}