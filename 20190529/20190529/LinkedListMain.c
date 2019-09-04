#include <stdio.h>
#include "LinkedList.h"

int SortConditionFunc(int d1, int d2) // ���� ����
{
	if (d1 < d2)  // ��������
		return 0; // d1�� d2���� ���ļ����� �տ� ��ġ��.
	else
		return 1; // d2�� d1���� ���ļ����� �տ� ��ġ��.
}

int main(void)
{
	// List�� ����, �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// ���� ������ ���� �� ����
	// SetSortRule �Լ��� ȣ���� �Ǹ鼭 ���� ������
	// Linked List����� comp�� ��ϵ�
	// �׸��� �����Ͱ� ������ �Ǹ鼭 comp�� ��ϵ�
	// ���� �������� �����͸� �����Ͽ� �����ϰ� ��
	SetSortRule(&list, SortConditionFunc);

	// ������ �Է�
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
	
	// �Էµ� ������ ���
	printf("�Էµ� �������� ���� : %d \n", LCount(&list));
	
	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	printf("\n");

	printf("3�� ����ϴ�.\n\n");

	// Ư�� ������ �˻� �� ����
	if (LFirst(&list, &data))
	{
		if (data == 3)
			LRemove(&list); 
		// �̷��� �Ǵ� ������ cur�� �־..
		// ���� ������ �˻��� �ߴٴ� cur�� ������

		while (LNext(&list, &data))
		{
			if (data == 3)
				LRemove(&list);
		}
	}

	// ��ü ������ ��� (���� �Ǿ����� ��Ȯ�� ����)
	printf("�Էµ� �������� ���� : %d \n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d \n", data);

		while (LNext(&list, &data))
			printf("%d \n", data);
	}

	return 0;
}