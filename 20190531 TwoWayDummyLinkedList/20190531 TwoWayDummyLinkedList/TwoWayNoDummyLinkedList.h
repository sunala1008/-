#ifndef _TW_NO_DLL_H_
#define _TW_NO_DLL_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* prev;
	struct _node* next;
} Node;

typedef struct _twoWayNodummyLinkedList
{
	Node* head;
	Node* cur;

	int numOfData;
} TwoWayNodummyLinkedList;

typedef TwoWayNodummyLinkedList List;

// 초기화
void ListInit(List* plist);

// 데이터 입력
void LInsert(List* plist, Data data);

// 첫 번째 확인
int LFirst(List* plist, Data* pdata);

// 이전 확인
int LPrevious(List* plist, Data* pdata);

// 다음 확인
int LNext(List* plist, Data* pdata);

// 데이터 수 확인
int LCount(List* plist);

#endif // !_TW_NO_DLL_H_
