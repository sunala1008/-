#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

/*
	 ▶ Stack ◀
	  - LIFO (Last In First Out) 후입선출 
	  
	  - 배열기반으로 한 코드
*/

// Stack 초기화
void StackInit(Stack* pstack)
{
	pstack->topIdex = -1; // 0은 아님. 0은 데이터 있다는 의미 => 배열이라서!
}

// Stack에 데이터 입력 (Push)
void SPush(Stack* pstack, Data data)
{					// ┌─ 선증가 시켜야 topIndex가 0 부터 시작하므로
	pstack->stackArray[++pstack->topIdex] = data;
	printf("Push(%d) ", data);

	// pstack->topIdex += 1;
	// pstack->stackArray[pstack->topIdex] = data;
}

// Stack에 데이터 출력 (Pop)
// 출력이라 리턴되야 하므로 자료형은 Data
Data SPop(Stack* pstack)
{
	int idx;

	if (SIsEmpty(pstack))
	{
		printf("Stack이 비어있습니다.");
		exit(-1); // 프로그램 종료
	}

	idx = pstack->topIdex;

	pstack->topIdex -= 1;

	return pstack->stackArray[idx];

	// return pstack->stackArray[pstack->topIdex--];
	// 나는 위에 리턴만 했음.. ㅇㅇ
}

// Stack이 비어있는지 확인 (IsEmpty)
// True False 리턴
int SIsEmpty(Stack* pstack)
{
	if (pstack->topIdex == -1)
		return TRUE;  // 비어있다
	else
		return FALSE; // 안비어있다
}