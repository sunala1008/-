#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/*
	 ▶ 트리 Tree ◀
	  - 계층적 관계를 ㅍ현하는 자료구조
	  - ex) 컴퓨터의 디렉토리, 기업 등의 조직도

	 ▶ 용어 ◀
	  1. 노드 (node)
	  2. 간선 (edge)
	  3. 루트노드 (root node)
	  4. 단말노드 (termital node)
	  5. 내부노드 (internal node)

	 ▶ 이진트리 Binary Tree 구현 ◀
	  1. 이진트리 자체 구현
	  2. 이진트리 순회 구현
			[순회의 종류]
			= 전위순회 : 루트노드가 첫번째로 순회
			 -> 루트노드 - 왼쪽 서브트리 - 오른쪽 서브트리
			= 중위순회 : 루트노드가 두번째로 순회
			  -> 왼쪽 서브트리 - 루트노드 - 오른쪽 서브트리
			= 후위순회 : 루트노드가 세번째로 순회
			  -> 왼쪽 서브트리 - 오른쪽 서브트리 - 루트노드	
	    - 데이터 조회용
		- BinaryTreeNode free용
*/

// [이진트리 순회 구현]
void BinaryTreeTraverse(BinaryTreeNode* btnd)
{
	if (btnd == NULL)
		return; // 재귀 탈출

	// [중위순회 순서]
	// 왼쪽 순회
	BinaryTreeTraverse(btnd->left);
	// 자기자신 순회
	printf("%d  ", btnd->data);
	// 오른쪽 순회
	BinaryTreeTraverse(btnd->right);

	/*
	// [전위순회 순서]
	// 자기자신 순회
	printf("%d  ", btnd->data);
	// 왼쪽 순회
	BinaryTreeTraverse(btnd->left);
	// 오른쪽 순회
	BinaryTreeTraverse(btnd->right);
	*/

	/*
	// [후위순회 순서]
	// 왼쪽 순회
	BinaryTreeTraverse(btnd->left);
	// 오른쪽 순회
	BinaryTreeTraverse(btnd->right);
	// 자기자신 순회
	printf("%d  ", btnd->data);
	*/
}

int main()
{
	// [이진트리 자체 구현]
	// 1.이진트리 구성요소인 BinaryTreeNode 생성
	BinaryTreeNode* bt1 = MakeBinaryTreeNode();
	BinaryTreeNode* bt2 = MakeBinaryTreeNode();
	BinaryTreeNode* bt3 = MakeBinaryTreeNode();
	BinaryTreeNode* bt4 = MakeBinaryTreeNode();
	
	// 2. 생성된 BinaryTreeNode에 데이터 저장
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	// 3. 2번까지 만든 BinaryTreeNode를 가지고 이진트리로 구성
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	/*
			 bt1
			□■■■□
		 bt2│   │bt3
		□■■■□   □■■■□
	 bt4│
	□■■■□

	전위순회 : bt1 - bt2 - bt4 - bt3
	중위순회 : bt4 - bt2 - bt1 - bt3
	후위순회 : bt4 - bt2 - bt3 - bt1
	*/

	// 4. 데이터 조회
	// bt2(: bt1의 왼쪽 자식 노드)의 데이터 조회
	printf("bt2 : %d \n", GetData(GetLeftSubTree(bt1)));

	// bt4(: bt2의 왼쪽 자식 노드)의 데이터 조회
	printf("bt4 : %d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	
	// 중위순회
	printf("\n[중위순회]\n");
	BinaryTreeTraverse(bt1);

	printf("\n");

	// 이진트리 공간 전체 해제
	RemoveBinaryTree(bt1);

	return 0;
}