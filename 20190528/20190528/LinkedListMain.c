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
		printf("���� �Է� : ");
		scanf("%d", &data);

		if (data < 1)
			break;

		// ������ ����
		node = PutData(data);
		LInsert(&list, node);
	}

	printf("\n== �Էµ� ������ ��� ==\n");
	printf("�Էµ� ���� ���� : %d\n", LCount(&list));
	
	if (LFirst(&list, &node)) // ������ ���
	{
		printf("�Էµ� ������ : ");
		Show_Node(&list);

		while (LNext(&list, &node))
			Show_Node(&list);
	}

	// ��ü ����
	printf("\n== �Էµ� ���� ���� ==\n");

	LRemove(&list);
	
	//// �� ���� �� ���
	//printf("\n== �Էµ� ������ ��� ==\n");
	//printf("�Էµ� ���� ���� : %d\n", LCount(&list));

	//if (LFirst(&list, &node)) // ������ ���
	//{
	//	printf("�Էµ� ������ : ");
	//	Show_Node(&list);

	//	while (LNext(&list, &node))
	//		Show_Node(&list);
	//}




	return 0;
}