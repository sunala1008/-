#include <stdio.h>
#include <stdlib.h>
#include "CircleLinkedList.h"

// �ڵ带 ������ �׷��� �����غ��� �� �����ϴ�... �̷��� ����...��

//�ʱ�ȭ
void ListInit(List* plist)
{
	// plist->tail = (Node*)malloc(sizeof(Node));
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	
	plist->numOfData = 0;
}

// ����Ʈ�� ������ �߰� -> ������ ���� [������ ��������]
void LInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL) // ������ ����� ������ ������
	{
		plist->tail = newNode; // ������ �ְ�,
		newNode->next = newNode; // �� �����Ͱ� ����(����)
	} // => �����Ͱ� �ϳ��ۿ� ������ �Ӹ����� ������
	else // ������ ����� ������ ������
	{
		// �ű� ����� ���� ��尡 ������ ���� ����???
		newNode->next = plist->tail->next; // ��!
		plist->tail->next = newNode;
		plist->tail = newNode;
	}

	(plist->numOfData)++;
}

// ����Ʈ�� ������ �߰� -> �Ӹ��� ���� [������ ��������]
void LInsertFront(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		plist->tail->next = newNode;
		// newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

//ù��°���� Ȯ��
int LFirst(List* plist, LData* data)
{
	if (plist->tail == NULL) // �����Ͱ� ���� ���
		return FALSE;

	// �����Ͱ� ����Ǿ� ���� ���	

	// + before �Ӹ��� ���̴ϱ� ������ ��
	plist->before = plist->tail; // ���� ��带 ������
	// ���� ��带 ���� ����� ���� ����
	// + ��ȸ�� �Ӹ����� �����ؼ� ������ ������
	// + cur�� ������ ������ �Ӹ��� ����
	plist->cur = plist->before->next;
	
	*data = plist->cur->data; // �����ʹ� ���� ����� ������
	// �� �����Ͱ� �ִ� ��尡 cur�� �Ǵ� ��.

	return TRUE;

	// tail�� before�� �ΰ�, cur�� before ��������
	// ���� ������ �Ӹ��ϱ� cur�� �ִ� ���� first?
	// => x ��� �� �ƴѵ�?
}

//�������� �̵�
int LNext(List* plist, LData* data)
{
	if (plist->tail == NULL) // �����Ͱ� ���� ���
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->before->next;
	*data = plist->cur->data; // �� �����Ͱ� cur�� ������

	return TRUE;

	// ??
	// ��...! LFirst���� ����? ã�� cur�� before�� �ΰ�
	// �� before�� ������ cur�� �θ� cur�� �������� �Ѿ��!!
}

//����Ʈ���� ������ ����
LData LRemove(List* plist)
{
	Node* removeNode = plist->cur; // ������ ��� = ���� ���

	// ������ ������ = ���� ����� ������
	LData removeData = plist->cur->data;

	if (plist->tail == removeNode) // ���� ������ ��尡 ������
	{
		if (plist->tail == plist->tail->next) // ������ �Ӹ��� �� (������ 1��)
		{
			plist->tail = NULL;
			plist->cur = NULL;
			plist->before = NULL;
		}
		else // ������ ������ ��尡 ���⸸ �� ��� =>????
			plist->tail = plist->before;
		// + ������ ����, ���������ϱ� ������ �� ĭ �Űܾ��Ѵ� ?
	}

	// cur�� ���� �� �Ű�, �̰Ÿ� removeNode�� ��
	// plist->cur = removeNode ��� ������ ���������ϱ�..
	//						���� plist->cur
	plist->before->next = removeNode->next;

	plist->cur = plist->before;
	// �� �̷��ĸ�, cur�� ������ �о�� �ϴϱ�
	// before�� cur�� �ξ���Ѵ�! �׷��� ���� �� ����!

	free(removeNode);

	(plist->numOfData)--;
	
	return removeData;
}

//����Ʈ���� ����� ������ ��
int LCount(List* plist)
{
	return plist->numOfData;
}