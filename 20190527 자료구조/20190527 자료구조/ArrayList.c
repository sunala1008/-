#include <stdio.h>
#include "ArrayList.h"

// �ʱ�ȭ
void ListInit(List* plist)
{
	plist->numOfData = 0;

	// plist->curPosition = 0; // 0 �ϸ� �ȵȴ�
	plist->curPosition = -1;   // 0�� ������� ���۵ȰŶ�, -1�� �༭ ���� �ȵƴٰ� �ϴ� ��.

	//for (int i = 0; i < LIST_LEN; i++)
	//	plist->arr[i] = 0;
}

// ����Ʈ�� ������ �߰�
void LInsert(List* plist, LData data)
{
	// �������� �ִ� ���� ����
	if (plist->numOfData > LIST_LEN)
	{
		printf("���� ������ �����ϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	plist->numOfData++;

	/*if (plist->numOfData == LIST_LEN)
		printf("������ �߰� �Ұ�");
	else
	{
		plist->arr[plist->numOfData] = data;
		plist->curPosition++;
		plist->numOfData++;
	}*/	
}

// ù��° ���� Ȯ��
int LFirst(List* plist, LData* data)
{
	if (plist->numOfData == 0) // �����Ͱ� ����
	{
		// data = plist->arr[0];
		return FALSE;
	}
	else // ������ ����, ��ġ �Űܾ���
	{
		/*printf("ù ��° �����ͷ� �̵��մϴ�.");
		plist->numOfData == 0;*/

		plist->curPosition = 0;
		*data = plist->arr[0];
		// *data = plist->arr[plist->curPosition];
		
		return TRUE;
	}
}

// �������� �̵�
int LNext(List* plist, LData* data)
{
	/*plist->numOfData++;
	printf("���� �����ͷ� �̵��մϴ�.");
	
	for (int i = 1; i < plist->numOfData; i++)
	{
		data = plist->arr[i];
	}*/

	// ����Ʈ�� ������ �˻��� ��������� üũ
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;
	
	plist->curPosition++;
	*data = plist->arr[plist->curPosition];
	return TRUE;
}

// ����Ʈ���� ������ ����
LData LRemove(List* plist)
{
	/*for (int i = 0; i < plist->curPosition; i++)
	{
		for (int j = i; j < plist->curPosition - 1; j++)
		{
			plist->arr[j] = plist->arr[j + 1];
		}
	}*/

	int removePosition = plist->curPosition;
	int num = plist->numOfData;
	LData removeData = plist->arr[removePosition]; // ���

	for (int i = removePosition; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	plist->numOfData--;
	plist->curPosition--;

	return removeData;
}

// ����Ʈ���� ����� �������� ��
int LCount(List* plist)
{
	return plist->numOfData;
}