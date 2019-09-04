#include <stdio.h>
#include <stdlib.h>
#include "CircleLinkedList.h"

// 코드를 찬찬히 그려서 생각해보면 꽤 쉽습니다... 미래의 나여...ㅋ

//초기화
void ListInit(List* plist)
{
	// plist->tail = (Node*)malloc(sizeof(Node));
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	
	plist->numOfData = 0;
}

// 리스트에 데이터 추가 -> 꼬리에 저장 [꼬리를 기준으로]
void LInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // 꼬리에 저장된 데이터 없으면
	{
		plist->tail = newNode; // 데이터 넣고,
		newNode->next = newNode; // 그 데이터가 다음(꼬리)
	} // => 데이터가 하나밖에 없으면 머리이자 꼬리라서
	else // 꼬리에 저장된 데이터 있으면
	{
		// 신규 노드의 다음 노드가 꼬리의 다음 노드로???
		newNode->next = plist->tail->next; // 아!
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

// 리스트에 데이터 추가 -> 머리에 저장 [꼬리를 기준으로]
void LInsertFront(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		plist->tail->next = newNode;
		// newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

//첫번째인지 확인
int LFirst(List* plist, LData* data)
{
	if (plist->tail == NULL) // 데이터가 없을 경우
		return FALSE;

	// 데이터가 저장되어 있을 경우	

	// + before 머리의 앞이니까 꼬리가 됨
	plist->before = plist->tail; // 이전 노드를 꼬리로
	// 현재 노드를 이전 노드의 다음 노드로
	// + 조회는 머리에서 시작해서 꼬리로 가야함
	// + cur를 꼬리의 다음인 머리로 세팅
	plist->cur = plist->before->next;
	
	*data = plist->cur->data; // 데이터는 현재 노드의 데이터
	// 그 데이터가 있는 노드가 cur가 되는 것.

	return TRUE;

	// tail을 before로 두고, cur를 before 다음노드로
	// 꼬리 다음은 머리니까 cur가 있는 곳이 first?
	// => x 요건 좀 아닌듯?
}

//다음으로 이동
int LNext(List* plist, LData* data)
{
	if (plist->tail == NULL) // 데이터가 없을 경우
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->before->next;
	*data = plist->cur->data; // 그 데이터가 cur의 데이터

	return TRUE;

	// ??
	// 아...! LFirst에서 선택? 찾은 cur를 before로 두고
	// 그 before의 다음을 cur로 두면 cur가 다음으로 넘어간거!!
}

//리스트에서 데이터 삭제
LData LRemove(List* plist)
{
	Node* removeNode = plist->cur; // 삭제할 노드 = 현재 노드

	// 삭제할 데이터 = 현재 노드의 데이터
	LData removeData = plist->cur->data;

	if (plist->tail == removeNode) // 꼬리 삭제할 노드가 같으면
	{
		if (plist->tail == plist->tail->next) // 꼬리가 머리일 때 (데이터 1개)
		{
			plist->tail = NULL;
			plist->cur = NULL;
			plist->before = NULL;
		}
		else // 꼬리와 삭제할 노드가 같기만 한 경우 =>????
			plist->tail = plist->before;
		// + 꼬리를 삭제, 꼬리였으니까 앞으로 한 칸 옮겨야한대 ?
	}

	// cur를 삭제 할 거고, 이거를 removeNode라 함
	// plist->cur = removeNode 라고 위에서 선언했으니까..
	//						┌─ plist->cur
	plist->before->next = removeNode->next;

	plist->cur = plist->before;
	// 왜 이러냐면, cur의 다음을 읽어야 하니까
	// before를 cur로 두어야한다! 그래야 읽을 수 있음!

	free(removeNode);

	(plist->numOfData)--;
	
	return removeData;
}

//리스트에서 저장된 데이터 수
int LCount(List* plist)
{
	return plist->numOfData;
}