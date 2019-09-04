#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

/*
	 �� Stack ��
	  - LIFO (Last In First Out) ���Լ��� 
	  
	  - �迭������� �� �ڵ�
*/

// Stack �ʱ�ȭ
void StackInit(Stack* pstack)
{
	pstack->topIdex = -1; // 0�� �ƴ�. 0�� ������ �ִٴ� �ǹ� => �迭�̶�!
}

// Stack�� ������ �Է� (Push)
void SPush(Stack* pstack, Data data)
{					// ���� ������ ���Ѿ� topIndex�� 0 ���� �����ϹǷ�
	pstack->stackArray[++pstack->topIdex] = data;
	printf("Push(%d) ", data);

	// pstack->topIdex += 1;
	// pstack->stackArray[pstack->topIdex] = data;
}

// Stack�� ������ ��� (Pop)
// ����̶� ���ϵǾ� �ϹǷ� �ڷ����� Data
Data SPop(Stack* pstack)
{
	int idx;

	if (SIsEmpty(pstack))
	{
		printf("Stack�� ����ֽ��ϴ�.");
		exit(-1); // ���α׷� ����
	}

	idx = pstack->topIdex;

	pstack->topIdex -= 1;

	return pstack->stackArray[idx];

	// return pstack->stackArray[pstack->topIdex--];
	// ���� ���� ���ϸ� ����.. ����
}

// Stack�� ����ִ��� Ȯ�� (IsEmpty)
// True False ����
int SIsEmpty(Stack* pstack)
{
	if (pstack->topIdex == -1)
		return TRUE;  // ����ִ�
	else
		return FALSE; // �Ⱥ���ִ�
}