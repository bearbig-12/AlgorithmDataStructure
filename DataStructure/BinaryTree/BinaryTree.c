#include "BinaryTree.h"

SBTNode* CreateNode(ElementType newData)
{
	SBTNode* newNode = (SBTNode*)malloc(sizeof(SBTNode));

	newNode->Left = NULL;
	newNode->Right = NULL;
	newNode->mData = newData;

	return newNode;
}


void DestroyNode(SBTNode* node)
{
	free(node);
}

void DestroyTree(SBTNode* root)
{
	if (root == NULL)
	{
		return;
	}

	// 왼쪽 하위 트리 제거
	DestroyNode(root->Left);
	// 오른쪽 하위 트리 제거
	DestroyNode(root->Right);
	// 뿌리 노드 제거
	DestroyNode(root);
}

void PreOrderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return;

	//  뿌리 노드 출력 
	printf(" %c", node->mData);

	//  왼쪽 하위 트리 출력 
	PreOrderPrintTree(node->Left);

	//  오른쪽 하위 트리 출력 
	PreOrderPrintTree(node->Right);
}

void InOrderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return;

	//  왼쪽 하위 트리 출력 
	InOrderPrintTree(node->Left);

	//  뿌리 노드 출력 
	printf(" %c", node->mData);

	//  오른쪽 하위 트리 출력 
	InOrderPrintTree(node->Right);

}

void PostOrderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return;

	//  왼쪽 하위 트리 출력 
	PostOrderPrintTree(node->Left);

	//  오른쪽 하위 트리 출력 
	PostOrderPrintTree(node->Right);

	//  뿌리 노드 출력 
	printf(" %c", node->mData);


}
