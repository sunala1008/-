#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node)); // 더미노드 생성
	plist->head->next = NULL;
	plist->comp = NULL; // 정렬시 필요
	plist->numOfData = 0; // 더미노드만 있고 데이터노드가 없으니까 0
}

// 1. 정렬 없이 데이터 추가
void NormalInsert(List * plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // 데이터를 저장할 데이터노드 생성

	newNode->data = data;

	// 1☆
	newNode->next = plist->head->next;

	// 2☆
	plist->head->next = newNode;

	(plist->numOfData)++;

	/*
		┌─>더미노드[head] ┌─> 4(데이터)
		■■■□□			■■■□□
		 2☆└───■■■□□───┘1☆
			   └─> 3(데이터)
	*/
}

// 2. 정렬 후 데이터 추가
void SortInsert(List* plist, LData data)
{
	// 오름차순 정렬을 위해서 진행한 위치변수
	Node* checkedNode = plist->head;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// Linkde List에서 저장할 위치 확인
	while (checkedNode->next != NULL && plist->comp(data, checkedNode->next->data) != 0)
		checkedNode = checkedNode->next; // 위치이동

	newNode->next = checkedNode->next;
	checkedNode->next = newNode;

	(plist->numOfData)++;
}

//리스트에 데이터 추가
void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL) // 1. 정렬 없이 데이터 추가
		NormalInsert(plist, data);
	else // 2. 정렬함수를 사용해서 데이터 추가
		SortInsert(plist, data);
}

//첫번째인지 확인
int LFirst(List * plist, LData * data)
{
	if (plist->head->next == NULL)
		return FALSE; // 데이터가 없으니까 출력x 그래서 FALSE(0)가 반환되어 메인의 LFirst가 실행 안됨

	plist->before = plist->head;
	plist->cur = plist->head->next;

	//*data = plist->head->next; // 이중 포인터
	*data = plist->cur->data;
	return TRUE; // 얘가 반환되어야 출력 가능
}

//다음으로 이동
int LNext(List * plist, LData * data)
{
	// 다음 데이터노드가 있는지를 체크
	if (plist->cur->next == NULL)
		return FALSE; // 데이터가 없으면 출력하면 안되니까...

	// 데이터노드로 이동
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	// 데이터 노드의 데이터를 가져와야 함.
	*data = plist->cur->data; // 이중 포인터

	return TRUE;
}

//리스트에서 데이터 삭제
LData LRemove(List * plist)
{
	//삭제할 데이터 노드를 선택
	Node * removeNode = plist->cur;
	//삭제할 데이터 노드의 데이터를 백업
	LData removeData = removeNode->data;

	//삭제될 데이터 노드를 기준으로 앞노드와 뒤노드를 연결.
	plist->before->next = plist->cur->next;
	//다음 데이터 노드를 검색하기위해
	//현재의 위치를 before의 위치로 이동.
	plist->cur = plist->before;

	//삭제할 데이터 노드가 Linked List에서 분리되었으므로
	//free함.
	free(removeNode);

	//데이터 노드가 free되었으므로, 데이터 노드의
	//갯수를 차감함.
	(plist->numOfData)--;

	return removeData;
}

//리스트에서 저장된 데이터 수
int LCount(List * plist)
{
	return plist->numOfData;
}

//정렬 Rule 설정
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	/*if (strcmp(d1, d2))
	{

	}*/

	plist->comp = comp;
}