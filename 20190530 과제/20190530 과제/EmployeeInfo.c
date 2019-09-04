#pragma warning(disable:4996)   

#include <stdio.h>
#include <stdlib.h >
#include "EmployeeInfo.h"

// 초기화
void ListInit(List* plist)
{
	plist->before = NULL;
	plist->cur = NULL;
	plist->tail = NULL;

	plist->numOfData = 0;
}

// 사원 정보 받음
Employee* EInfo(char* name, int num)
{
	Employee* emp = (Employee*)malloc(sizeof(Employee));

	strcpy(emp->Name, name);
	emp->EmlpoyeeNum = num;

	return emp;
}

// 리스트에 사원 정보 추가 => 꼬리에 추가하는 방식으로
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

// 첫 번째 사원인지 확인
int EFirst(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->before->next;

	*data = plist->cur->data;

	return TRUE;
}

// 다음 사원으로 이동
int ENext(List* plist, LData* data)
{
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->before->next;

	*data = plist->cur->data;
	
	return TRUE;
}

// 사원 정보 출력
void Show_Employee(Employee* pemp)
{
	printf("\n");
	printf("- 사원 이름 : %s\n", pemp->Name);
	printf("- 사원 번호 : %d\n", pemp->EmlpoyeeNum);
}

// 검색 중 이름이 같은지. 같으면 0, 다르면 1
int Serch_Overtime_Employee_Name(Employee* pemp, char* name)
{
	return strcmp(pemp->Name, name);
}

// 특근 출근자 검색, 출력
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
	printf("= %d일 후의 특근 출근자\n", num);
	printf("- 사원 이름 : %s\n", plist->cur->data->Name);
	printf("- 사원 번호 : %d\n", plist->cur->data->EmlpoyeeNum);
}

// 리스트에 저장된 사원 수
int ECount(List* plist)
{
	return plist->numOfData;
}