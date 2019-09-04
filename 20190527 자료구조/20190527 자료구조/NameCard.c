#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"

// �̸�, ��ȭ��ȣ ������� �ʱ�ȭ //??
NameCard* Make_NameCard(char *name, char *phone)
{
	NameCard* nc = (NameCard*)malloc(sizeof(NameCard));

	strcpy(nc->name, name);
	strcpy(nc->phone, phone);

	return nc;
}

// ����Լ�
void Show_NameCard(NameCard* pcard)
{
	printf("\n");
	printf("�̸� : %s\n", pcard->name);
	printf("��ȣ : %s\n", pcard->phone);
}

// �̸��� �˻��ؼ� ������ 0, �ٸ��� 1
int Search_NameCard(NameCard* pcard, char* name)
{
	// strcmp : ������ 0 ����, 0�ܴ̿� ��� Ʋ����
	return strcmp(pcard->name, name);
}

// ��ȭ��ȣ ���� �Լ�
void Change_PhoneNum(NameCard* pcard, char* phone)
{
	strcpy(pcard->phone, phone);
}