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

// Stack 초기화
void StackInit(Stack* pstack);

// Stack에 데이터 입력 (Push)
void SPush(Stack* pstack, Data data);

// Stack에 데이터 출력 (Pop)
// 출력이라 리턴되야 하므로 자료형은 Data
Data SPop(Stack* pstack);

// Stack이 비어있는지 확인 (IsEmpty)
// True False 리턴
int SIsEmpty(Stack* pstack);

#endif // !_LINKED_LIST_STACK_H_
