#define _CRT_SECURE_NO_WARNINGS // strcpy? scanf? 오류 (2019 버전)

#include <stdio.h>
#include <stdlib.h>

// 일반적인 Linked List(DummyNode가 아님)
typedef struct _node
{
	int data;			// 데이터를 담을 공간
	struct _node* next; // 연결을 위한 도구 => 자기자신
} Node;

int main(void)
{
	// Linked List 초기화
	Node* head = NULL;
	Node* cur = NULL;
	Node* tail = NULL;
	Node* newNode = NULL;

	int readData;

	// 1. 데이터 입력, Node 생성, Node 연결
	while (1)
	{
		printf("정수 입력 : ");
		scanf("%d", &readData);

		if (readData < 1)
			break;

		// 데이터 저장을 위한 Node 생성
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode; 
		 // ????
		tail = newNode;
	}

	// 2. Node를 스캔, 데이터를 출력
	printf("\nNode 데이터 전체 출력\n");

	if (head == NULL) // 데이터가 없을 때
		printf("스캔할 Node가 없습니다.");
	else
	{
		cur = head; // 커서가 헤드에 있을 때
		printf("%d ", cur->data); // 커서가 가리키는 head 의 data를 출력

		while (cur->next != NULL) // 다음이 없을 때 까지? (tail 까지..)
		{
			cur = cur->next; // 커서는 cur->next로 움직이고? => 다음에 저장된 애들의
			printf("%d ", cur->data); // 데이터를 출력
		}
	}

	printf("\n\n");

	// 3. Node의 메모리 공간 해제
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d 데이터가 있는 Node를 삭제합니다.\n", head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 데이터가 있는 Node를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}