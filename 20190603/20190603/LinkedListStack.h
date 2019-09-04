#ifndef _LINKED_LIST_STACK_H_
#define _LINKED_LIST_STACK_H_

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node* next;

} Node;

typedef struct _linkedListStack
{
	Node* head;
} LinkedListStack;

typedef LinkedListStack Stack;

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

#endif // !_LINKED_LIST_STACK_H_
