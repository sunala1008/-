#include <stdio.h>
#include "LinkedList.h"

// �ʱ�ȭ
void ListInit(List* plist)
{
	/*plist->head = NULL;
	plist->before = NULL;
	plist->cur = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;*/

	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

LinkedList* PutData(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL; // �̰� �߰��ϴϱ� ������ �ȳ� ��
	
	return node;
}

void NormalInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = data;
	
	newNode->next = plist->head->next;

	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SortInsert(List* plist, LData data)
{
	Node* checkedNode = plist->head;

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	while (checkedNode->next != NULL &&
		plist->comp(data, checkedNode->next->data) != 0)
		checkedNode = checkedNode->next;

	newNode->next = checkedNode->next;
	checkedNode->next = newNode;

	(plist->numOfData)++;
}

// ����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		NormalInsert(plist, data);
	else
		SortInsert(plist, data);
}

void Show_Node(List* plist)
{
	plist->cur = plist->head;
	printf("%d ", plist->cur->data);

	while (plist->cur->next != NULL)
	{
		plist->cur = plist->cur->next;
		printf("%d ", plist->cur->data);
	}

	printf("\n");
	/*if (plist->head->data == NULL)
		printf("��ĵ�� Node�� �����ϴ�.");
	else
	{
		plist->cur = plist->head;
		printf("%d ", plist->cur->data);

		while (plist->cur->next != NULL)
		{
			plist->cur = plist->cur->next;
			printf("%d ", plist->cur->data);
		}
	}*/
}

// ù ��°���� Ȯ��
int LFirst(List* plist, LData* data)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*data = plist->cur->data;
	return TRUE;

	/*if (plist->head == NULL)
		printf("��ĵ�� Node�� �����ϴ�.");
	else
	{
		plist->cur = plist->head;
		printf("���� Ŀ�� ��ġ : %d\n", plist->cur->data);
	}*/
}

// �������� �̵�
int LNext(List* plist, LData* data)
{
	//// ����Ʈ�� ������ �˻��� ��������� üũ
	//if (plist->cur >= (plist->numOfData) - 1)
	//	return FALSE;

	//plist->cur++;
	//*data = plist->tail->data;
	//return TRUE;	

	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*data = plist->cur->data;

	return TRUE;
}

// ����Ʈ���� ������ ����
LData LRemove(List* plist)
{
	/*if (plist->head == NULL)
		return 0;
	else
	{
		Node* delNode = plist->head;
		Node* delNextNode = plist->head->next;

		printf("%d �����Ͱ� �ִ� Node�� �����մϴ�.\n", plist->head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d �����Ͱ� �ִ� Node�� �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}*/

	Node* removeNode = plist->cur;
	LData removeData = removeNode->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(removeNode);
	(plist->numOfData)--;

	return removeData;
}

// ����Ʈ���� ����� ������ ��
int LCount(List* plist)
{
	return plist->numOfData;
}

// ���� Rule ����
void SetSortRule(List* plist, int(*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}