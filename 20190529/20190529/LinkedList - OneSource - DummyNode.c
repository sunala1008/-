#define _CRT_SECURE_NO_WARNINGS // strcpy? scanf? 오류 (2019 버전)

#include <stdio.h>
#include <stdlib.h>

// DummyNode가 적용된 Linked List
// 더미노드는 모양만 노드고, 데이터를 저장하지 않음
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

	// 더미노드 추가=> 헤더가 됨
	head = (Node*)malloc(sizeof(Node)); // 더미 노드 생성됨 : head
	// 근데 첫 생성?시에는 노드가 하나밖에 없으니까 처음 생성된 노드가 head이자 tail이 되야함
	tail = head;
	// 추가된 노드가 Linked List에서 볼 때, 머리이자 꼬리가 됨

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

		/*if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;*/ // => 더미노드가 생성되어 필요없음
		
		tail->next = newNode; // => 대신 얘는 필요
		// 더미노드를 사용하니 if~else로 머리냐 꼬리냐 구분 없이 그냥 꼬리 뒤에 붙이기만 하면 됨
		tail = newNode;
	}

	// 2. Node를 스캔, 데이터를 출력
	printf("\nNode 데이터 전체 출력\n");

	if (head == NULL) // 데이터가 없을 때
		printf("스캔할 Node가 없습니다.");
	else
	{
		cur = head; // 커서가 헤드에 있을 때
		// printf("%d ", cur->data); // 커서가 가리키는 head 의 data를 출력
		// ==> 더미노드가 head인데, 더미노드는 데이터가 없으니까 출력 할 게 없음! 

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

		/*printf("%d 데이터가 있는 Node를 삭제합니다.\n", head->data);
		free(delNode);*/
		// 두 번째 이후부터 데이터가 있기 때문에, head인 더미노드는 삭제하면 안됨

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