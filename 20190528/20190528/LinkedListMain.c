#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <stdio.h>
#include "LinkedList.h"

int main(void)
{
	List list;
	ListInit(&list);
	LinkedList* node;

	int data;

	while (1)
	{
		printf("정수 입력 : ");
		scanf("%d", &data);

		if (data < 1)
			break;

		// 데이터 저장
		node = PutData(data);
		LInsert(&list, node);
	}

	printf("\n== 입력된 정수들 출력 ==\n");
	printf("입력된 정수 갯수 : %d\n", LCount(&list));
	
	if (LFirst(&list, &node)) // 데이터 출력
	{
		printf("입력된 정수들 : ");
		Show_Node(&list);

		while (LNext(&list, &node))
			Show_Node(&list);
	}

	// 전체 삭제
	printf("\n== 입력된 정수 삭제 ==\n");

	LRemove(&list);
	
	//// 비교 위해 재 출력
	//printf("\n== 입력된 정수들 출력 ==\n");
	//printf("입력된 정수 갯수 : %d\n", LCount(&list));

	//if (LFirst(&list, &node)) // 데이터 출력
	//{
	//	printf("입력된 정수들 : ");
	//	Show_Node(&list);

	//	while (LNext(&list, &node))
	//		Show_Node(&list);
	//}




	return 0;
}