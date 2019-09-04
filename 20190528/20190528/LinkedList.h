#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
	LData data;
	struct _node* next; // �ڱ� �ڽ��� ����
} Node; // => �ڱ� ���� ����ü

typedef struct _linkdeList
{
	Node* head;
	Node* before; // cur �տ� �ִ°� : ���� ���ؼ�
	Node* cur;
	Node* tail;

	int numOfData;
	int(*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

LinkedList* PutData(int data);

void Show_Node(List* plist);

// �ʱ�ȭ
void ListInit(List* plist);

// ����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data);

// ù ��°���� Ȯ��
int LFirst(List* plist, LData* data);

// �������� �̵�
int LNext(List* plist, LData* data);

// ����Ʈ���� ������ ����
LData LRemove(List* plist);

// ����Ʈ���� ����� ������ ��
int LCount(List* plist);

// ���� Rule ����
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2));

#endif // !_LINKED_LIST_H_
