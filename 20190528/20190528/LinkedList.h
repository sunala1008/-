#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next; // 자기 자신을 참조
} Node; // => 자기 참조 구조체

typedef struct _linkdeList
{
	Node* head;
	Node* before; // cur 앞에 있는거 : 삭제 위해서
	Node* cur;
	Node* tail;

	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

LinkedList* PutData(int data);

void Show_Node(List* plist);

// 초기화
void ListInit(List* plist);

// 리스트에 데이터 추가
void LInsert(List* plist, LData data);

// 첫 번째인지 확인
int LFirst(List* plist, LData* data);

// 다음으로 이동
int LNext(List* plist, LData* data);

// 리스트에서 데이터 삭제
LData LRemove(List* plist);

// 리스트에서 저장된 데이터 수
int LCount(List* plist);

// 정렬 Rule 설정
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

#endif // !_LINKED_LIST_H_
