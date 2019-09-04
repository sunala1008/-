#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// BinaryTree �� ������� Node�� ����
BinaryTreeNode* MakeBinaryTreeNode(void)
{
	BinaryTreeNode* btnd = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	btnd->left = NULL;
	btnd->right = NULL;
	
	return btnd;
}

// ������ ���� �Լ�
void SetData(BinaryTreeNode* bt, BTData data)
{
	bt->data = data;
}

// ������ ��ȸ �Լ�
BTData GetData(BinaryTreeNode* bt)
{
	return bt->data;
}

// ���� �ڽ� ��� �������� �Լ�
BinaryTreeNode* GetLeftSubTree(BinaryTreeNode* bt)
{
	return bt->left;
}

// ������ �ڽ� ��� �������� �Լ�
BinaryTreeNode* GetRightSubTree(BinaryTreeNode* bt)
{
	return bt->right;
}

// ���� �ڽ� Tree ���� �Լ�
void MakeLeftSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub)
{
	if (parent->left != NULL)
		free(parent->left);

	parent->left = sub;
}

// ������ �ڽ� Tree ���� �Լ�
void MakeRightSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub)
{
	if (parent->right != NULL)
		free(parent->right);

	parent->right = sub;
}

// ����Ʈ�� ���� ��ü ����
void RemoveBinaryTree(BinaryTreeNode* btnd)
{
	if (btnd == NULL)
		return;

	RemoveBinaryTree(btnd->left);
	printf("\nbtnd->left : %d ����\n", btnd->data);

	RemoveBinaryTree(btnd->right);
	printf("\nbtnd->right : %d ����\n", btnd->data);
	
	free(btnd);
	printf("\n���� �Ϸ�!\n");
}