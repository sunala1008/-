#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node *)malloc(sizeof(Node)); // ���̳�� ����
	plist->head->next = NULL;
	plist->comp = NULL; // ���Ľ� �ʿ�
	plist->numOfData = 0; // ���̳�常 �ְ� �����ͳ�尡 �����ϱ� 0
}

// 1. ���� ���� ������ �߰�
void NormalInsert(List * plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); // �����͸� ������ �����ͳ�� ����

	newNode->data = data;

	// 1��
	newNode->next = plist->head->next;

	// 2��
	plist->head->next = newNode;

	(plist->numOfData)++;

	/*
		����>���̳��[head] ����> 4(������)
		������			������
		 2�٦������������ড������1��
			   ����> 3(������)
	*/
}

// 2. ���� �� ������ �߰�
void SortInsert(List* plist, LData data)
{
	// �������� ������ ���ؼ� ������ ��ġ����
	Node* checkedNode = plist->head;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// Linkde List���� ������ ��ġ Ȯ��
	while (checkedNode->next != NULL && plist->comp(data, checkedNode->next->data) != 0)
		checkedNode = checkedNode->next; // ��ġ�̵�

	newNode->next = checkedNode->next;
	checkedNode->next = newNode;

	(plist->numOfData)++;
}

//����Ʈ�� ������ �߰�
void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL) // 1. ���� ���� ������ �߰�
		NormalInsert(plist, data);
	else // 2. �����Լ��� ����ؼ� ������ �߰�
		SortInsert(plist, data);
}

//ù��°���� Ȯ��
int LFirst(List * plist, LData * data)
{
	if (plist->head->next == NULL)
		return FALSE; // �����Ͱ� �����ϱ� ���x �׷��� FALSE(0)�� ��ȯ�Ǿ� ������ LFirst�� ���� �ȵ�

	plist->before = plist->head;
	plist->cur = plist->head->next;

	//*data = plist->head->next; // ���� ������
	*data = plist->cur->data;
	return TRUE; // �갡 ��ȯ�Ǿ�� ��� ����
}

//�������� �̵�
int LNext(List * plist, LData * data)
{
	// ���� �����ͳ�尡 �ִ����� üũ
	if (plist->cur->next == NULL)
		return FALSE; // �����Ͱ� ������ ����ϸ� �ȵǴϱ�...

	// �����ͳ��� �̵�
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	// ������ ����� �����͸� �����;� ��.
	*data = plist->cur->data; // ���� ������

	return TRUE;
}

//����Ʈ���� ������ ����
LData LRemove(List * plist)
{
	//������ ������ ��带 ����
	Node * removeNode = plist->cur;
	//������ ������ ����� �����͸� ���
	LData removeData = removeNode->data;

	//������ ������ ��带 �������� �ճ��� �ڳ�带 ����.
	plist->before->next = plist->cur->next;
	//���� ������ ��带 �˻��ϱ�����
	//������ ��ġ�� before�� ��ġ�� �̵�.
	plist->cur = plist->before;

	//������ ������ ��尡 Linked List���� �и��Ǿ����Ƿ�
	//free��.
	free(removeNode);

	//������ ��尡 free�Ǿ����Ƿ�, ������ �����
	//������ ������.
	(plist->numOfData)--;

	return removeData;
}

//����Ʈ���� ����� ������ ��
int LCount(List * plist)
{
	return plist->numOfData;
}

//���� Rule ����
void SetSortRule(List * plist, int(*comp)(LData d1, LData d2))
{
	/*if (strcmp(d1, d2))
	{

	}*/

	plist->comp = comp;
}