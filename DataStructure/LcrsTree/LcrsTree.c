#include "LCRSTree.h"



LCRSNode* CreateNode(ElementType newData)
{
	LCRSNode* newNode = (LCRSNode*)malloc(sizeof(LCRSNode));

	newNode->LeftChild = NULL;
	newNode->RightSibling = NULL;
	newNode->mData = newData;
}
void DestroyNode(LCRSNode* node)
{
	free(node);
}
void DestroyTree(LCRSNode* root)
{
	if (root->RightSibling != NULL)
	{
		DestroyTree(root->RightSibling);
	}
	if (root->LeftChild != NULL)
	{
		DestroyTree(root->LeftChild);
	}

	root->LeftChild = NULL;
	root->RightSibling = NULL;

	DestroyNode(root);
}

void AddChildNode(LCRSNode* parentNode, LCRSNode* childNode)
{
	if (parentNode->LeftChild == NULL)
	{
		parentNode->LeftChild = childNode;
	}
	else
	{
		LCRSNode* tempNode = parentNode->LeftChild;
		while (tempNode->RightSibling != NULL)
		{
			tempNode = tempNode->RightSibling;
		}
		tempNode->RightSibling = childNode;
	}
}
void PrintTree(LCRSNode* node, int depth)
{
	// 들여쓰기
	int i = 0;
	for (i = 0; i < depth - 1; i++)
	{
		printf("   ");
	}
	if (depth > 0) // 자식 노드 여부 표시
		printf("+--");

	// 노드 데이터 출력
	printf("%c\n", node->mData);

	if (node->LeftChild != NULL)
		PrintTree(node->LeftChild, depth + 1);

	if(node->RightSibling != NULL)
		PrintTree(node->RightSibling, depth);

}

void PrintLevel(LCRSNode* node, int level)
{
	if (node == NULL)
		return;
	if (level == 0)
	{
		printf("%c\n", node->mData);
	}
	else if (level > 0)
	{
		if (node->LeftChild != NULL)
		{
			// 자식 노드로 내려가기 (level - 1)
			PrintLevel(node->LeftChild, level - 1);
		}
	}
	if (node->RightSibling != NULL)
	{
		// 형제 노드는 같은 level
		PrintLevel(node->RightSibling, level);
	}




	
	//LCRSNode* temp = node;

	//while (temp != NULL)
	//{
	//	if (level == 0)
	//	{
	//		// 출력 대상
	//		printf("%c ", temp->mData);
	//	}
	//	else if (level > 0)
	//	{
	//		// 자식 방향으로 한 단계 내려가기
	//		PrintLevel(temp->LeftChild, level - 1);
	//	}

	//	// 형제 방향으로 같은 레벨 유지
	//	temp = temp->RightSibling;
	//}


	
}

void LevelPrintTree(LCRSNode* Tree, int level) 
{
	if (level < 0) return;

	if (level == 0) {
		printf("%c, ", Tree->mData);
	}

	if (Tree->LeftChild != NULL) {
		LevelPrintTree(Tree->LeftChild, level - 1);
	}

	if (Tree->RightSibling != NULL) {
		LevelPrintTree(Tree->RightSibling, level);
	}
}


void LevelPrintTree2(LCRSNode* Node, int level, int Depth) 
{
	// level과 depth를 매개변수로 받아서 사용하는 방법
	if (level < Depth) {
		return;
	}

	if (Depth == level) {
		printf("%c ", Node->mData);
	}

	if (Node->LeftChild != NULL) {
		LevelPrintTree2(Node->LeftChild, level, Depth + 1);
	}

	if (Node->RightSibling != NULL) {
		LevelPrintTree2(Node->RightSibling, level, Depth);
	}
}

