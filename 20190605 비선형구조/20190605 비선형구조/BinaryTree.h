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

// BinaryTree 의 구성요소 Node를 만듦
BinaryTreeNode* MakeBinaryTreeNode(void);

// 데이터 저장 함수
void SetData(BinaryTreeNode* bt, BTData data);

// 데이터 조회 함수
BTData GetData(BinaryTreeNode* bt);

// 왼쪽 자식 노드 가져오는 함수
BinaryTreeNode* GetLeftSubTree(BinaryTreeNode* bt);

// 오른쪽 자식 노드 가져오는 함수
BinaryTreeNode* GetRightSubTree(BinaryTreeNode* bt);

// 왼쪽 자식 Tree 생성 함수
void MakeLeftSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub);

// 오른쪽 자식 Tree 생성 함수
void MakeRightSubTree(BinaryTreeNode* parent, BinaryTreeNode* sub);

// 이진트리 공간 전체 해제
void RemoveBinaryTree(BinaryTreeNode* btnd);

#endif // !_BINARY_TREE_H_
