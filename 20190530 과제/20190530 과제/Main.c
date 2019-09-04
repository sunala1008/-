#define _CRT_SECURE_NO_WARNINGS // scanf ����

#include <stdio.h>
#include <stdlib.h >
#include "EmployeeInfo.h"

/*
	1. ����� ����� �̸�����, ����� ������ ����
	2. 4���� ����� ���� ���� ����Ʈ�� ����
	  - scanf�� �Է¹��� �ʾƵ� ok
	  - �������� ����
	  - ���� ���Ḯ��Ʈ���� ����ü ������ �ּ� ���� ����
	3. Ư�ٽ������� �� �� ����Ѵٰ� ����
	  - ������ ���α׷��� ��ϵǴ� ��� ������
	  - ��� ����� A-B-C�� Ư�� ������ A-B-C-A-B-C
	4. Ư�� ����� �˻�
	  - ��� �̸��� �ϳ��� ���ڸ� ���ڷ� �˻��ϴ� �Լ� ȣ��
	  - ���޵� �̸��� ����� Ư�� �� ����, ���޵� ���ڿ� �ش��ϴ�
	    ��ŭ�� ������ ���� Ư���� ���� �Ǵ� ������ ���� ��ȯ
	  - �������, '������'�� '7'�� ���޵Ǹ� '������' ������
	    7��° ���� Ư�� ����� ������ ��ȯ�Ǿ�� ��
*/

int main(void)
{
	List list;
	ListInit(&list); // �ʱ�ȭ
	Employee* emp;

	char name[NAME_LEN]; // ��� �̸�
	int emp_num;		 // ��� ��ȣ

	int day;

	/*
	printf("[ 4 ���� ��� ������ �Է��ϼ���. ]\n");
	for (int i = 0; i < 4; i++)
	{
		printf("- ��� �̸� : ");
		scanf("%s", name);

		printf("- ��� ��ȣ : ");
		scanf("%d", &emp_num);

		printf("\n");
		emp = EInfo(name, emp_num);
		EInfoInsert(&list, emp);
	}
	*/

	// �����, ��� �Է�
	emp = EInfo("ȫ�浿", 101);
	EInfoInsert(&list, emp);

	emp = EInfo("������", 102);
	EInfoInsert(&list, emp);

	emp = EInfo("�̼���", 103);
	EInfoInsert(&list, emp);

	emp = EInfo("�Ӳ���", 104);
	EInfoInsert(&list, emp);

	// ��� ���� ���
	//system("cls");
	printf("= �Է��� ��� ����� �� : %d", ECount(&list));
	printf(" ��\n");

	if (EFirst(&list, &emp))
	{
		Show_Employee(emp);

		for (int i = 0; i < ECount(&list) - 1; i++) // 1ȸ���� ��
		{
			if(ENext(&list, &emp))
				Show_Employee(emp);
		}
	}
	
	//getchar();
	// getchar();

	printf("\n");

	// Ư�� ����� �˻� [�� 1 - �� 2 - �� 3 - �� 4]
	//system("cls");
	printf("= ������ Ư�� ����� : ");
	scanf("%s", name);
	printf("= ���÷κ��� �� �� ���� Ư�� ������� ������ ���ðڽ��ϱ�? : ");
	scanf("%d", &day);

	if (EFirst(&list, &emp))
	{
		if (!Serch_Overtime_Employee_Name(emp, name))
		{
			Serch_Next(&list, emp, day);
			printf("\n");
		}
		else
		{
			while (ENext(&list, &emp))
			{
				if (!Serch_Overtime_Employee_Name(emp, name))
				{
					Serch_Next(&list, emp, day);
					printf("\n");
					break;
				}
			}
		}
	}

	return 0;
}