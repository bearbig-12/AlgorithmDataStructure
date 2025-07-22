#ifndef BINARY_TREE_H
#define BINARY_TREE_H


#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct tagSBTNode
{
	struct  tagSBTNode* Left;
	struct  tagSBTNode* Right;

	ElementType mData;
}SBTNode;

SBTNode* CreateNode(ElementType newData);
void DestroyNode(SBTNode* node);
void DestroyTree(SBTNode* root);

void PreOrderPrintTree(SBTNode* node);
void InOrderPrintTree(SBTNode* node);
void PostOrderPrintTree(SBTNode* node);

#endif