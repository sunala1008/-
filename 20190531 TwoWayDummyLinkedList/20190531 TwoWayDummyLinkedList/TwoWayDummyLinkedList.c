#include <stdio.h>
#include "TwoWayDummyLinkedList.h"

// �ʱ�ȭ
void ListInit(List* plist)
{
	// ���̳��� ��� 2���� �߰�
	plist->head = (Node*)malloc(sizeof(Node)); // ���̳��
	plist->tail = (Node*)malloc(sizeof(Node)); // ���̳��
	
	plist->head->prev = NULL; // ��
	plist->head->next = plist->tail; // ��

	plist->tail->next = NULL; // ��
	plist->tail->prev = plist->head; // ��

	plist->numOfData = 0;

	/*
		[head�� tail ���� ���̳�带 ����]
		 head		 tail	
		��������		��������	
		p DM n	  	p DM n
		��������������������������������������������������>> ��״� NULL�� ���� ��	
			 ����������������������������>> ��׸� ��������� ��
	*/
}

// ������ �Է�
/*
		 head		newNode		 tail		
		��������		��������		��������
		p DM n	   p data n		p DM n
			 ��������������	  ��������������
				   ����>>1, 2����	����>>3, 4����
*/
void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;

	// 1
	newNode->prev = plist->tail->prev;
	//newNode->prev = plist->head;

	// 2
	plist->tail->prev->next = newNode;
	// plist->head->next = newNode; // ��� �� �ȵǴ°�¡ => ����?�� �߿��ϴ�

	// 3
	newNode->next = plist->tail;
	// newNode->next = plist->head->next;

	// 4
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

// ù ��° Ȯ��
int LFirst(List* plist, Data* pdata)
{
	// �����Ϳ� ��尡 ���� ���
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;

	*pdata = plist->cur->data;

	return TRUE;
}

// ���� Ȯ��
int LNext(List* plist, Data* pdata)
{
	// ��� ù���� Ȯ���ϰ� cur�� �ű�� �Ű�����??
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;

	return TRUE;
}

// ������ ����
Data LRemove(List* plist)
{
	/*
		 head	  removeNode 	 tail
		��������		��������		��������
		p DM n	   p data n		p DM n
		     ����������������������������������������������������>> 1, 2 ��׸� �ٽ� �����Ŵ
	*/

	Node* removeNode = plist->cur;
	Data removeData = removeNode->data;

	// 1
	plist->cur->prev->next = plist->cur->next;

	// 2
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev; // cur ��ġ �ű�
	
	free(removeNode);

	(plist->numOfData)--;

}

// ������ �� Ȯ��
int LCount(List* plist)
{
	return plist->numOfData;
}