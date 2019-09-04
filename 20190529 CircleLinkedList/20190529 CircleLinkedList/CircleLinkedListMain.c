#include <stdio.h>
#include "CircleLinkedList.h"

// ���� ��ũ�� ����Ʈ�� �Ӹ��� ������ �������� �ϴ� �� ���� ����� �ִµ�,
// �� �ű⿡���� �����տ��� �ְų� ���� �ڿ��� �ְų�...? �ϴ� �ΰ����� ���־�?!
// ��ư �𸣰ڰ� ������ ������� �ϴ� �ڵ巡

int main(void)
{
	// 1. List�� ����, �ʱ�ȭ
	List list;
	int data;
	
	// ���� ����Ʈ�� �ݺ��ؼ� ����� �ǹǷ� �ݺ� ���� ������ �߰�
	int stop;

	ListInit(&list);

	// 2. ������ ����
	// ������ ��带 �߰�
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	// �Ӹ��� ��带 �߰�
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 3. ����� �����͸� 2ȸ�� ���
	if (LFirst(&list, &data)) // ������ ��尡 �ִ��� üũ
	{
		printf("%d ", data);

		for (stop = 0; stop < LCount(&list) * 2 - 1; stop++) 
		{ // LCount(&list) - 1 : ������ �� �� ����ؼ�
			if (LNext(&list, &data))
				printf("%d ", data);
		}
	}

	printf("\n\n");

	// 4. ������ ����
	if (LFirst(&list, &data))
	{
		if (data == 2)
		{
			LRemove(&list);
			printf("%d ���� �Ϸ�\n", data);
		}

		while (LNext(&list, &data))
		{
			if (data == 2)
			{ 
				LRemove(&list);
				printf("%d ���� �Ϸ�\n", data);
				break;
			}
			
		}
	}
	
	// 5. ���� Ȯ�ο� ����� - 1ȸ����
	if (LFirst(&list, &data)) // ������ ��尡 �ִ��� üũ
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