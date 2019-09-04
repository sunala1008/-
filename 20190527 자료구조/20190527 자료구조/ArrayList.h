#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	순차 자료구조(배열 기반)의 ADT
*/

#include "NameCard.h"

#define LIST_LEN 100

// bool형 상수 정의?
#define TRUE 1
#define FALSE 0

// typedef int LData;
typedef NameCard* LData; // int 를 네임카드로 바꾸면 됨...

typedef struct __ArrayList
{
	// 배열 멤버
	LData arr[LIST_LEN];

	// 데이터 숫자
	int numOfData;

	// 현재 위치
	int curPosition;
} ArrayList;

// ArrayList와 관련된 ADT
typedef ArrayList List;

// 초기화
void ListInit(List * plist);

// 리스트에 데이터 추가
void LInsert(List* plist, LData data);

// 첫번째 인지 확인
int LFirst(List* plist, LData * data);

// 다음으로 이동
int LNext(List* plist, LData * data);

// 리스트에서 데이터 삭제
LData LRemove(List* plist);

// 리스트에서 저장된 데이터의 수
int LCount(List* plist);

#endif // !__ARRAY_LIST_H__

/*
	명함(NameCard) 구조체를 하나 만든다.
	- name, phone

	를 할 수 있게 바꾼다....
*/