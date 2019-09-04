#ifndef __C_LIKNED_LIST_H__
#define __C_LIKNED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next;
} Node;

typedef struct _CLL
{
	// Node* head; // 꼬리를 기준으로 할거기 때문에 head는 필요 없음
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

// 초기화
void ListInit(List* plist);

// 리스트에 데이터 추가
void LInsert(List* plist, LData data);

// 머리에 노드를 추가
// ※ head변수는 없지만, (어쨌든 간에) tail의 다음은 머리가 되므로.. 
void LInsertFront(List* plist, LData data);

// 첫번째인지 확인
int LFirst(List* plist, LData* data);

// 다음으로 이동
int LNext(List* plist, LData* data);

// 리스트에서 데이터 삭제
LData LRemove(List* plist);

// 리스트에서 저장된 데이터 수
int LCount(List* plist);

#endif // !__C_LIKNED_LIST_H__
