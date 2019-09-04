#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

/*
	 �� Ʈ�� Tree ��
	  - ������ ���踦 �����ϴ� �ڷᱸ��
	  - ex) ��ǻ���� ���丮, ��� ���� ������

	 �� ��� ��
	  1. ��� (node)
	  2. ���� (edge)
	  3. ��Ʈ��� (root node)
	  4. �ܸ���� (termital node)
	  5. ���γ�� (internal node)

	 �� ����Ʈ�� Binary Tree ���� ��
	  1. ����Ʈ�� ��ü ����
	  2. ����Ʈ�� ��ȸ ����
			[��ȸ�� ����]
			= ������ȸ : ��Ʈ��尡 ù��°�� ��ȸ
			 -> ��Ʈ��� - ���� ����Ʈ�� - ������ ����Ʈ��
			= ������ȸ : ��Ʈ��尡 �ι�°�� ��ȸ
			  -> ���� ����Ʈ�� - ��Ʈ��� - ������ ����Ʈ��
			= ������ȸ : ��Ʈ��尡 ����°�� ��ȸ
			  -> ���� ����Ʈ�� - ������ ����Ʈ�� - ��Ʈ���	
	    - ������ ��ȸ��
		- BinaryTreeNode free��
*/

// [����Ʈ�� ��ȸ ����]
void BinaryTreeTraverse(BinaryTreeNode* btnd)
{
	if (btnd == NULL)
		return; // ��� Ż��

	// [������ȸ ����]
	// ���� ��ȸ
	BinaryTreeTraverse(btnd->left);
	// �ڱ��ڽ� ��ȸ
	printf("%d  ", btnd->data);
	// ������ ��ȸ
	BinaryTreeTraverse(btnd->right);

	/*
	// [������ȸ ����]
	// �ڱ��ڽ� ��ȸ
	printf("%d  ", btnd->data);
	// ���� ��ȸ
	BinaryTreeTraverse(btnd->left);
	// ������ ��ȸ
	BinaryTreeTraverse(btnd->right);
	*/

	/*
	// [������ȸ ����]
	// ���� ��ȸ
	BinaryTreeTraverse(btnd->left);
	// ������ ��ȸ
	BinaryTreeTraverse(btnd->right);
	// �ڱ��ڽ� ��ȸ
	printf("%d  ", btnd->data);
	*/
}

int main()
{
	// [����Ʈ�� ��ü ����]
	// 1.����Ʈ�� ��������� BinaryTreeNode ����
	BinaryTreeNode* bt1 = MakeBinaryTreeNode();
	BinaryTreeNode* bt2 = MakeBinaryTreeNode();
	BinaryTreeNode* bt3 = MakeBinaryTreeNode();
	BinaryTreeNode* bt4 = MakeBinaryTreeNode();
	
	// 2. ������ BinaryTreeNode�� ������ ����
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	// 3. 2������ ���� BinaryTreeNode�� ������ ����Ʈ���� ����
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);

	/*
			 bt1
			������
		 bt2��   ��bt3
		������   ������
	 bt4��
	������

	������ȸ : bt1 - bt2 - bt4 - bt3
	������ȸ : bt4 - bt2 - bt1 - bt3
	������ȸ : bt4 - bt2 - bt3 - bt1
	*/

	// 4. ������ ��ȸ
	// bt2(: bt1�� ���� �ڽ� ���)�� ������ ��ȸ
	printf("bt2 : %d \n", GetData(GetLeftSubTree(bt1)));

	// bt4(: bt2�� ���� �ڽ� ���)�� ������ ��ȸ
	printf("bt4 : %d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	
	// ������ȸ
	printf("\n[������ȸ]\n");
	BinaryTreeTraverse(bt1);

	printf("\n");

	// ����Ʈ�� ���� ��ü ����
	RemoveBinaryTree(bt1);

	return 0;
}