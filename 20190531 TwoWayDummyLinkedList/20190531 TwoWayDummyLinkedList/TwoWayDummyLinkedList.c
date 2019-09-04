#include <stdio.h>
#include "TwoWayDummyLinkedList.h"

// 초기화
void ListInit(List* plist)
{
	// 더미노드용 노드 2개를 추가
	plist->head = (Node*)malloc(sizeof(Node)); // 더미노드
	plist->tail = (Node*)malloc(sizeof(Node)); // 더미노드
	
	plist->head->prev = NULL; // ☆
	plist->head->next = plist->tail; // ★

	plist->tail->next = NULL; // ☆
	plist->tail->prev = plist->head; // ★

	plist->numOfData = 0;

	/*
		[head와 tail 각각 더미노드를 만듦]
		 head		 tail	
		□□■■■□□		□□■■■□□	
		p DM n	  	p DM n
		└────│──────│────└───────>> 얘네는 NULL로 해줌 ☆	
			 └──────└──────>> 얘네를 연결시켜줌 ★
	*/
}

// 데이터 입력
/*
		 head		newNode		 tail		
		□□■■■□□		□□■■■□□		□□■■■□□
		p DM n	   p data n		p DM n
			 └─────┤	  └─────┤
				   └─>>1, 2연결	└─>>3, 4연결
*/
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	// 1
	newNode->prev = plist->tail->prev;
	//newNode->prev = plist->head;

	// 2
	plist->tail->prev->next = newNode;
	// plist->head->next = newNode; // 얘는 왜 안되는거징 => 순서?가 중요하대

	// 3
	newNode->next = plist->tail;
	// newNode->next = plist->head->next;

	// 4
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

// 첫 번째 확인
int LFirst(List* plist, Data* pdata)
{
	// 데이터에 노드가 없는 경우
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

// 다음 확인
int LNext(List* plist, Data* pdata)
{
	// 얘는 첫번재 확인하고 cur가 거기로 옮겨져서??
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

// 데이터 삭제
Data LRemove(List* plist)
{
	/*
		 head	  removeNode 	 tail
		□□■■■□□		□□■■■□□		□□■■■□□
		p DM n	   p data n		p DM n
		     └──────────────────└──────>> 1, 2 얘네를 다시 연결시킴
	*/

	Node* removeNode = plist->cur;
	Data removeData = removeNode->data;

	// 1
	plist->cur->prev->next = plist->cur->next;

	// 2
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev; // cur 위치 옮김
	
	free(removeNode);

	(plist->numOfData)--;

}

// 데이터 수 확인
int LCount(List* plist)
{
	return plist->numOfData;
}