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

// �ʱ�ȭ
void ListInit(List* plist);

// ������ �Է�
void LInsert(List* plist, Data data);

// ù ��° Ȯ��
int LFirst(List* plist, Data* pdata);

// ���� Ȯ��
int LPrevious(List* plist, Data* pdata);

// ���� Ȯ��
int LNext(List* plist, Data* pdata);

// ������ �� Ȯ��
int LCount(List* plist);

#endif // !_TW_NO_DLL_H_
