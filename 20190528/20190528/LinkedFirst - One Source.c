#define _CRT_SECURE_NO_WARNINGS // strcpy? scanf? ���� (2019 ����)

#include <stdio.h>
#include <stdlib.h>

// �Ϲ����� Linked List(DummyNode�� �ƴ�)
typedef struct _node
{
	int data;			// �����͸� ���� ����
	struct _node* next; // ������ ���� ���� => �ڱ��ڽ�
} Node;

int main(void)
{
	// Linked List �ʱ�ȭ
	Node* head = NULL;
	Node* cur = NULL;
	Node* tail = NULL;
	Node* newNode = NULL;

	int readData;

	// 1. ������ �Է�, Node ����, Node ����
	while (1)
	{
		printf("���� �Է� : ");
		scanf("%d", &readData);

		if (readData < 1)
			break;

		// ������ ������ ���� Node ����
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

	// 2. Node�� ��ĵ, �����͸� ���
	printf("\nNode ������ ��ü ���\n");

	if (head == NULL) // �����Ͱ� ���� ��
		printf("��ĵ�� Node�� �����ϴ�.");
	else
	{
		cur = head; // Ŀ���� ��忡 ���� ��
		printf("%d ", cur->data); // Ŀ���� ����Ű�� head �� data�� ���

		while (cur->next != NULL) // ������ ���� �� ����? (tail ����..)
		{
			cur = cur->next; // Ŀ���� cur->next�� �����̰�? => ������ ����� �ֵ���
			printf("%d ", cur->data); // �����͸� ���
		}
	}

	printf("\n\n");

	// 3. Node�� �޸� ���� ����
	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d �����Ͱ� �ִ� Node�� �����մϴ�.\n", head->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d �����Ͱ� �ִ� Node�� �����մϴ�.\n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}