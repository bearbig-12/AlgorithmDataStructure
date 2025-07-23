#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char ElementType;
typedef struct tagETNode
{
	struct  tagETNode* Left;
	struct  tagETNode* Right;

	ElementType mData;

}ETNode;

ETNode* CreateNode(ElementType newData);
void DestroyNode(ETNode* node);
void DestroyTree(ETNode* root);

void PreorderPrintTree(ETNode* node);
void InorderPrintTree(ETNode* node);
void PostorderPrintTree(ETNode* node);
void BuildExpressionTree(char* postFixExpression, ETNode** node);
double Evaluate(ETNode* tree);
#endif


