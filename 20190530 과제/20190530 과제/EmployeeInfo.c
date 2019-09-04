#pragma warning(disable:4996)   

#include <stdio.h>
#include <stdlib.h >
#include "EmployeeInfo.h"

// �ʱ�ȭ
void ListInit(List* plist)
{
	plist->before = NULL;
	plist->cur = NULL;
	plist->tail = NULL;

	plist->numOfData = 0;
}

// ��� ���� ����
Employee* EInfo(char* name, int num)
{
	Employee* emp = (Employee*)malloc(sizeof(Employee));

	strcpy(emp->Name, name);
	emp->EmlpoyeeNum = num;

	return emp;
}

// ����Ʈ�� ��� ���� �߰� => ������ �߰��ϴ� �������
void EInfoInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

// ù ��° ������� Ȯ��
int EFirst(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->before->next;

	*data = plist->cur->data;

	return TRUE;
}

// ���� ������� �̵�
int ENext(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->before->next;

	*data = plist->cur->data;
	
	return TRUE;
}

// ��� ���� ���
void Show_Employee(Employee* pemp)
{
	printf("\n");
	printf("- ��� �̸� : %s\n", pemp->Name);
	printf("- ��� ��ȣ : %d\n", pemp->EmlpoyeeNum);
}

// �˻� �� �̸��� ������. ������ 0, �ٸ��� 1
int Serch_Overtime_Employee_Name(Employee* pemp, char* name)
{
	return strcmp(pemp->Name, name);
}

// Ư�� ����� �˻�, ���
void Serch_Next(List* plist, LData* data, int num)
{
	int i = 0;

	while (i < num)
	{
		plist->before = plist->cur;
		plist->cur = plist->before->next;
		
		*data = plist->cur->data;
		i++;
	}

	printf("\n");
	printf("= %d�� ���� Ư�� �����\n", num);
	printf("- ��� �̸� : %s\n", plist->cur->data->Name);
	printf("- ��� ��ȣ : %d\n", plist->cur->data->EmlpoyeeNum);
}

// ����Ʈ�� ����� ��� ��
int ECount(List* plist)
{
	return plist->numOfData;
}