#include <stdio.h>
#include "LinkedList.h"

int SortConditionFunc(int d1, int d2) // 정렬 조건
{
	if (d1 < d2)  // 오름차순
		return 0; // d1이 d2보다 정렬순서상 앞에 위치함.
	else
		return 1; // d2이 d1보다 정렬순서상 앞에 위치함.
}

int main(void)
{
	// List의 생성, 초기화
	List list;
	int data;
	ListInit(&list);

	// 정렬 조건을 선택 후 설정
	// SetSortRule 함수가 호출이 되면서 정렬 기준이
	// Linked List멤버의 comp에 등록됨
	// 그리고 데이터가 저장이 되면서 comp에 등록된
	// 정렬 기준으로 데이터를 정렬하여 저장하게 됨
	SetSortRule(&list, SortConditionFunc);

	// 데이터 입력
	LInsert(&list, 99);
	LInsert(&list, 1);
	LInsert(&list, 10);
	LInsert(&list, 4);
	LInsert(&list, 21);
	LInsert(&list, 3);
	LInsert(&list, 3);
	LInsert(&list, 3);
	LInsert(&list, 61);
	LInsert(&list, 12);
	LInsert(&list, 88);
	LInsert(&list, 94);
	
	// 입력된 데이터 출력
	printf("입력된 데이터의 갯수 : %d \n", LCount(&list));
	
	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	printf("\n");

	printf("3을 지웁니다.\n\n");

	// 특정 데이터 검색 후 삭제
	if (LFirst(&list, &data))
	{
		if (data == 3)
			LRemove(&list); 
		// 이렇게 되는 이유는 cur가 있어서..
		// 내가 어디까지 검색을 했다는 cur가 있으서

		while (LNext(&list, &data))
		{
			if (data == 3)
				LRemove(&list);
		}
	}

	// 전체 데이터 출력 (삭제 되었는지 비교확인 위해)
	printf("입력된 데이터의 갯수 : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	return 0;
}