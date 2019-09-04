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
	Node * before; // cur �տ� �ִ°� : ���� ���ؼ�
	int numOfData;
	int(*comp)(LData d1, LData d2); // ���� �� �ʿ�
} LinkedList;

typedef LinkedList List;

//�ʱ�ȭ
void ListInit(List * plist);

//����Ʈ�� ������ �߰�
void LInsert(List * plist, LData data);

//ù��°���� Ȯ��
int LFirst(List * plist, LData* data);

//�������� �̵�
int LNext(List * plist, LData* data);

//����Ʈ���� ������ ����
LData LRemove(List * plist);

//����Ʈ���� ����� ������ ��
int LCount(List * plist);

//���� Rule ����
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2));

#endif // !__LIKNED_LIST_H__
