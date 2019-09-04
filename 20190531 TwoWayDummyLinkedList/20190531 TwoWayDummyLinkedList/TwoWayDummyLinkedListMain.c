#include <stdio.h>
#include "TwoWayDummyLinkedList.h"

int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// ����� ���� ����Ʈ�� ������ ����
	LInsert(&list, 1);	LInsert(&list, 2);
	LInsert(&list, 3);	LInsert(&list, 4);
	LInsert(&list, 5);	LInsert(&list, 6);
	LInsert(&list, 7);	LInsert(&list, 8);

	// �̰� ���� head�� �տ� �߰��Ǵ°Ŷ�, head�� 8�̵�

	// ����� ������ ��ȸ �� ���
	printf("����� ���� : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // �ڷ�
			printf("%d ", data);

		printf("\n\n");
	}

	// 3�� ����� ���� ������ ��� ����
	printf("3�� ����� ���� ������ ��� ���� ����\n");
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

	printf("\n3�� ����� ���� ������ ��� ���� ����\n\n");

	// ������ ������ Ȯ�ο� ���
	printf("����� ���� : %d\n", LCount(&list));
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // �ڷ�
			printf("%d ", data);

		printf("\n\n");
	}

	return 0;
}	