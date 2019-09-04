#include <stdio.h>
#include "LinkedList.h"

// 초기화
void ListInit(List* plist)
{
	/*plist->head = NULL;
	plist->before = NULL;
	plist->cur = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;*/

	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

LinkedList* PutData(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL; // 이걸 추가하니까 오류가 안남 ㅎ
	
	return node;
}

void NormalInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = data;
	
	newNode->next = plist->head->next;

	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SortInsert(List* plist, LData data)
{
	Node* checkedNode = plist->head;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	while (checkedNode->next != NULL &&
		plist->comp(data, checkedNode->next->data) != 0)
		checkedNode = checkedNode->next;

	newNode->next = checkedNode->next;
	checkedNode->next = newNode;

	(plist->numOfData)++;
}

// 리스트에 데이터 추가
void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		NormalInsert(plist, data);
	else
		SortInsert(plist, data);
}

void Show_Node(List* plist)
{
	plist->cur = plist->head;
	printf("%d ", plist->cur->data);

	while (plist->cur->next != NULL)
	{
		plist->cur = plist->cur->next;
		printf("%d ", plist->cur->data);
	}

	printf("\n");
	/*if (plist->head->data == NULL)
		printf("스캔할 Node가 없습니다.");
	else
	{
		plist->cur = plist->head;
		printf("%d ", plist->cur->data);

		while (plist->cur->next != NULL)
		{
			plist->cur = plist->cur->next;
			printf("%d ", plist->cur->data);
		}
	}*/
}

// 첫 번째인지 확인
int LFirst(List* plist, LData* data)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;

	/*if (plist->head == NULL)
		printf("스캔할 Node가 없습니다.");
	else
	{
		plist->cur = plist->head;
		printf("현재 커서 위치 : %d\n", plist->cur->data);
	}*/
}

// 다음으로 이동
int LNext(List* plist, LData* data)
{
	//// 리스트의 끝까지 검색한 경우인지를 체크
	//if (plist->cur >= (plist->numOfData) - 1)
	//	return FALSE;

	//plist->cur++;
	//*data = plist->tail->data;
	//return TRUE;	

	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;

	return TRUE;
}

// 리스트에서 데이터 삭제
LData LRemove(List* plist)
{
	/*if (plist->head == NULL)
		return 0;
	else
	{
		Node* delNode = plist->head;
		Node* delNextNode = plist->head->next;

		printf("%d 데이터가 있는 Node를 삭제합니다.\n", plist->head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 데이터가 있는 Node를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}*/

	Node* removeNode = plist->cur;
	LData removeData = removeNode->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(removeNode);
	(plist->numOfData)--;

	return removeData;
}

// 리스트에서 저장된 데이터 수
int LCount(List* plist)
{
	return plist->numOfData;
}

// 정렬 Rule 설정
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}