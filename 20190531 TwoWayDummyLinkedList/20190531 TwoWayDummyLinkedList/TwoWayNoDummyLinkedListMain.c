#include <stdio.h>
#include "TwoWayNoDummyLinkedList.h"

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
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data)) // �ڷ�
			printf("%d ", data);    // �׷��� ��� 8���� ������
		
		printf("\nLNext ����\n\n");

		// ��~ ���� ���°� ���� 1�� ��� ���ϰ� ����
		// �ٵ� 
		// printf("%d ", data);
		// �̰� ������ 1 ���� ����
		while (LPrevious(&list, &data))
			printf("%d ", data);

		printf("\nLPrevious ����\n\n");
	}

	return 0;
}