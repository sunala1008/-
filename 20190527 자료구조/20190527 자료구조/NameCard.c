#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"

// 이름, 전화번호 멤버변수 초기화 //??
NameCard* Make_NameCard(char *name, char *phone)
{
	NameCard* nc = (NameCard*)malloc(sizeof(NameCard));

	strcpy(nc->name, name);
	strcpy(nc->phone, phone);

	return nc;
}

// 출력함수
void Show_NameCard(NameCard* pcard)
{
	printf("\n");
	printf("이름 : %s\n", pcard->name);
	printf("번호 : %s\n", pcard->phone);
}

// 이름을 검색해서 같으면 0, 다르면 1
int Search_NameCard(NameCard* pcard, char* name)
{
	// strcmp : 같으면 0 리턴, 0이외는 모두 틀린것
	return strcmp(pcard->name, name);
}

// 전화번호 변경 함수
void Change_PhoneNum(NameCard* pcard, char* phone)
{
	strcpy(pcard->phone, phone);
}