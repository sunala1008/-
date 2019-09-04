#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// BinaryTree 의 구성요소 Node를 만듦
BinaryTreeNode* MakeBinaryTreeNode(void)
{
	BinaryTreeNode* btnd = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	btnd->left = NULL;
	btnd->right = NULL;
	
	return btnd;
}

// 데이터 저장 함수
void SetData(BinaryTreeNode* bt, BTData data)
{
	bt->data = data;
}

// 데이터 조회 함수
BTData GetData(BinaryTreeNode* bt)
{
	return bt->data;
}

// 왼쪽 자식 노드 가져오는 함수
BinaryTreeNode* GetLeftSubTree(BinaryTreeNode* bt)
{
	return bt->left;
}

// 오른쪽 자식 노드 가져오는 함수
BinaryTreeNode* GetRightSubTree(BinaryTreeNode* bt)
{
	return bt->right;
}

// 왼쪽 자식 Tree 생성 함수
void MakeLeftSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub)
{
	if (parent->left != NULL)
		free(parent->left);

	parent->left = sub;
}

// 오른쪽 자식 Tree 생성 함수
void MakeRightSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub)
{
	if (parent->right != NULL)
		free(parent->right);

	parent->right = sub;
}

// 이진트리 공간 전체 해제
void RemoveBinaryTree(BinaryTreeNode* btnd)
{
	if (btnd == NULL)
		return;

	RemoveBinaryTree(btnd->left);
	printf("\nbtnd->left : %d 해제\n", btnd->data);

	RemoveBinaryTree(btnd->right);
	printf("\nbtnd->right : %d 해제\n", btnd->data);
	
	free(btnd);
	printf("\n해제 완료!\n");
}