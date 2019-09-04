#ifndef _STACK_H_
#define _STACK_H_

// �迭����� Stack �ڷᱸ���� ADT

#define STACK_SIZE 50 // �迭 ũ��
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _arrayStack
{
	Data stackArray[STACK_SIZE];
	int topIdex;
} ArrayStack;

typedef ArrayStack Stack;

// Stack �ʱ�ȭ
void StackInit(Stack* pstack);

// Stack�� ������ �Է� (Push)
void SPush(Stack* pstack, Data data);

// Stack�� ������ ��� (Pop)
// ����̶� ���ϵǾ� �ϹǷ� �ڷ����� Data
Data SPop(Stack* pstack); 

// Stack�� ����ִ��� Ȯ�� (IsEmpty)
// True False ����
int SIsEmpty(Stack* pstack);

#endif // !_STACK_H_
