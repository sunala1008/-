#include <stdio.h>
#include "ArrayList.h"

// 초기화
void ListInit(List* plist)
{
	plist->numOfData = 0;

	// plist->curPosition = 0; // 0 하면 안된대
	plist->curPosition = -1;   // 0을 줘버리면 시작된거라서, -1을 줘서 시작 안됐다고 하는 것.

	//for (int i = 0; i < LIST_LEN; i++)
	//	plist->arr[i] = 0;
}

// 리스트에 데이터 추가
void LInsert(List* plist, LData data)
{
	// 데이터의 최대 저장 범위
	if (plist->numOfData > LIST_LEN)
	{
		printf("저장 공간이 없습니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	plist->numOfData++;

	/*if (plist->numOfData == LIST_LEN)
		printf("데이터 추가 불가");
	else
	{
		plist->arr[plist->numOfData] = data;
		plist->curPosition++;
		plist->numOfData++;
	}*/	
}

// 첫번째 인지 확인
int LFirst(List* plist, LData* data)
{
	if (plist->numOfData == 0) // 데이터가 없음
	{
		// data = plist->arr[0];
		return FALSE;
	}
	else // 데이터 있음, 위치 옮겨야함
	{
		/*printf("첫 번째 데이터로 이동합니다.");
		plist->numOfData == 0;*/

		plist->curPosition = 0;
		*data = plist->arr[0];
		// *data = plist->arr[plist->curPosition];
		
		return TRUE;
	}
}

// 다음으로 이동
int LNext(List* plist, LData* data)
{
	/*plist->numOfData++;
	printf("다음 데이터로 이동합니다.");
	
	for (int i = 1; i < plist->numOfData; i++)
	{
		data = plist->arr[i];
	}*/

	// 리스트의 끝까지 검색한 경우인지를 체크
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	
	plist->curPosition++;
	*data = plist->arr[plist->curPosition];
	return TRUE;
}

// 리스트에서 데이터 삭제
LData LRemove(List* plist)
{
	/*for (int i = 0; i < plist->curPosition; i++)
	{
		for (int j = i; j < plist->curPosition - 1; j++)
		{
			plist->arr[j] = plist->arr[j + 1];
		}
	}*/

	int removePosition = plist->curPosition;
	int num = plist->numOfData;
	LData removeData = plist->arr[removePosition]; // 백업

	for (int i = removePosition; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	plist->numOfData--;
	plist->curPosition--;

	return removeData;
}

// 리스트에서 저장된 데이터의 수
int LCount(List* plist)
{
	return plist->numOfData;
}