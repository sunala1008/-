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
	// Node* head; // ������ �������� �Ұű� ������ head�� �ʿ� ����
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
} CList;

typedef CList List;

// �ʱ�ȭ
void ListInit(List* plist);

// ����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data);

// �Ӹ��� ��带 �߰�
// �� head������ ������, (��·�� ����) tail�� ������ �Ӹ��� �ǹǷ�.. 
void LInsertFront(List* plist, LData data);

// ù��°���� Ȯ��
int LFirst(List* plist, LData* data);

// �������� �̵�
int LNext(List* plist, LData* data);

// ����Ʈ���� ������ ����
LData LRemove(List* plist);

// ����Ʈ���� ����� ������ ��
int LCount(List* plist);

#endif // !__C_LIKNED_LIST_H__
