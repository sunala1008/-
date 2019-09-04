#ifndef __LIKNED_LIST_H__
#define __LIKNED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node * next;
} Node;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before; // cur 앞에 있는거 : 삭제 위해서
	int numOfData;
	int(*comp)(LData d1, LData d2); // 정렬 시 필요
} LinkedList;

typedef LinkedList List;

//초기화
void ListInit(List * plist);

//리스트에 데이터 추가
void LInsert(List * plist, LData data);

//첫번째인지 확인
int LFirst(List * plist, LData* data);

//다음으로 이동
int LNext(List * plist, LData* data);

//리스트에서 데이터 삭제
LData LRemove(List * plist);

//리스트에서 저장된 데이터 수
int LCount(List * plist);

//정렬 Rule 설정
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif // !__LIKNED_LIST_H__
