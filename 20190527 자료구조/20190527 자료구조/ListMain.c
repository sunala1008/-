#pragma warning(disable:4996)
#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	int sel = 0;

	List list;
	ListInit(&list);
	int data;
	
	NameCard* pcard; // ���� ������

	char name[NAME_LEN];
	char phone[PHONE_LEN];
	
	while (1)
	{
		system("cls");
		printf("--- ���� ���� ���α׷�---\n");
		printf("1. ���� ���� �Է�\n");
		printf("2. ���� ���� �˻�\n");
		printf("3. ���� ��ü ���\n");
		printf("4. ���� ���� ����\n");
		printf("5. ���α׷�  ����\n");
		printf("���� : ");
		scanf_s("%d", &sel);

		switch (sel)
		{
		case 1: // ���� ���� �Է�
			system("cls");
			printf("--- ���� ���� �Է� ---\n");
			
			//// scanf�� �Է¹��� ���� ��..
			//pcard = Make_NameCard("ȫ�浿", "010-7777-7777");
			//LInsert(&list, pcard);

			//pcard = Make_NameCard("�Ӳ���", "010-1234-5678");
			//LInsert(&list, pcard);

			//pcard = Make_NameCard("������", "010-5678-1234");
			//LInsert(&list, pcard);

			printf("�̸� : ");
			scanf("%s", &name);
			//scanf_s("%s", name);
			printf("��ȣ : ");
			//scanf_s("%s", phone);
			scanf("%s", &phone);
			printf("\n");

			// ���� �����Լ� ȣ��
			pcard = Make_NameCard(name, phone);
			LInsert(&list, pcard);

			

			break;
		case 2: // ���� ���� ��� => �˻� ��
			system("cls");
			printf("--- ���� ���� ��� ---\n");
			printf("�̸� �˻� : ");
			scanf("%s", name);

			if (LFirst(&list, &pcard)) // LFirst�� TRUE�� ����
			{
				if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "������")
					Show_NameCard(pcard);
				else
				{
					while (LNext(&list, &pcard))
					{
						if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "������")
							Show_NameCard(pcard);
					}
				}
			}
			getchar();
			getchar();
			break;
		case 3: // ���� ��ü ���
			system("cls");
			printf("����Ǿ��ִ� ������ �� : %d\n", LCount(&list));
			if (LFirst(&list, &pcard))
			{
				Show_NameCard(pcard);

				while (LNext(&list, &pcard))
				{
					Show_NameCard(pcard);
				}
			}
			getchar();
			getchar();
			break;
		case 4: // ���� ���� ����
			system("cls");
			printf("--- ���� ���� ���� ---\n");
			printf("�̸� �˻� : ");
			scanf("%s", name);

			if (LFirst(&list, &pcard)) // LFirst�� TRUE�� ����
			{
				if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "������")
				{
					pcard = LRemove(&list);
					free(pcard); // �޸� ���� ����
				}
				else
				{
					while (LNext(&list, &pcard))
					{
						if (!Search_NameCard(pcard, name)) // Search_NameCard(pcard, "������")
						{
							pcard = LRemove(&list);
							free(pcard); // �޸� ���� ����
							break;
						}
					}
				}
			}
			break;
		case 5: // ���α׷� ����
			printf("\n--- ���α׷� ���� ---\n");
			exit(1);
		default:
			printf("--- �޴� �缱�� ---\n\n");
			continue;
		}
	}
	
	//// ����Ʈ ���� �� �ʱ�ȭ
	//List list;			// ArrayList ����ü
	//ListInit(&list);
	//int data;

	//// ������ ����
	//LInsert(&list, 1);
	//LInsert(&list, 2);
	//LInsert(&list, 3);
	//LInsert(&list, 4);
	//LInsert(&list, 5);

	//// ����� ������ ��ü ���
	//printf("����� �������� �� : %d \n", LCount(&list));

	//// ������ ù��°�� ����� �ϴ� �Լ�
	//if (LFirst(&list, &data)) // ���� list�� ù��°�� �����Ͱ� ������ data�� �����ض�
	//{ // ù ��° ������ �˻�
	//	printf("%d", data);
	//	
	//	while (LNext(&list, &data))
	//		printf("%d", data);
	//}

	//printf("\n\n");

	//// ������ ���� => Ư�� �����͸� ����
	//if (LFirst(&list, &data))
	//{
	//	if (data == 3)
	//		LRemove(&list);

	//	while(LNext(&list, &data))
	//	{
	//		if(data == 3)
	//			LRemove(&list);
	//	}
	//}


	//// ���� �� ����� ������ ��ü ���
	//printf("����� �������� �� : %d \n", LCount(&list));

	//if (LFirst(&list, &data)) // ���� list�� ù��°�� �����Ͱ� ������ data�� �����ض�
	//{ // ù ��° ������ �˻�
	//	printf("%d", data);

	//	while (LNext(&list, &data))
	//		printf("%d", data);
	//}

	//printf("\n\n");

	return 0;
}