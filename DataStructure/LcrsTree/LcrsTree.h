#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct tageLCRSNode* LeftChild;
	struct tageLCRSNode* RightSibling;

	ElementType mData;
}LCRSNode;

LCRSNode* CreateNode(ElementType newData);
void DestroyNode(LCRSNode* node);
void DestroyTree(LCRSNode* root);

void AddChildNode(LCRSNode* parentNode, LCRSNode* childNode);
void PrintTree(LCRSNode* node, int depth);
void PrintLevel(LCRSNode* node, int level);




#endif