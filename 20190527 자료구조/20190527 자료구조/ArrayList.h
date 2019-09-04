#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
/*
	���� �ڷᱸ��(�迭 ���)�� ADT
*/

#include "NameCard.h"

#define LIST_LEN 100

// bool�� ��� ����?
#define TRUE 1
#define FALSE 0

// typedef int LData;
typedef NameCard* LData; // int �� ����ī��� �ٲٸ� ��...

typedef struct __ArrayList
{
	// �迭 ���
	LData arr[LIST_LEN];

	// ������ ����
	int numOfData;

	// ���� ��ġ
	int curPosition;
} ArrayList;

// ArrayList�� ���õ� ADT
typedef ArrayList List;

// �ʱ�ȭ
void ListInit(List * plist);

// ����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data);

// ù��° ���� Ȯ��
int LFirst(List* plist, LData * data);

// �������� �̵�
int LNext(List* plist, LData * data);

// ����Ʈ���� ������ ����
LData LRemove(List* plist);

// ����Ʈ���� ����� �������� ��
int LCount(List* plist);

#endif // !__ARRAY_LIST_H__

/*
	����(NameCard) ����ü�� �ϳ� �����.
	- name, phone

	�� �� �� �ְ� �ٲ۴�....
*/