#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#define TRUE 1
#define FALSE 0

typedef int BTData;

typedef struct _binaryTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BinaryTreeNode;

// BinaryTree �� ������� Node�� ����
BinaryTreeNode* MakeBinaryTreeNode(void);

// ������ ���� �Լ�
void SetData(BinaryTreeNode* bt, BTData data);

// ������ ��ȸ �Լ�
BTData GetData(BinaryTreeNode* bt);

// ���� �ڽ� ��� �������� �Լ�
BinaryTreeNode* GetLeftSubTree(BinaryTreeNode* bt);

// ������ �ڽ� ��� �������� �Լ�
BinaryTreeNode* GetRightSubTree(BinaryTreeNode* bt);

// ���� �ڽ� Tree ���� �Լ�
void MakeLeftSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub);

// ������ �ڽ� Tree ���� �Լ�
void MakeRightSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub);

// ����Ʈ�� ���� ��ü ����
void RemoveBinaryTree(BinaryTreeNode* btnd);

#endif // !_BINARY_TREE_H_
