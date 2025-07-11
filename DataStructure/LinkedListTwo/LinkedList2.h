#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* NextNode;
} Node;

// 함수 원형 선언 
Node* CreateNode(ElementType NewData);
void  DestroyNode(Node* Node);
void  AppendNode(Node** Head, Node* NewNode);
void  InsertAfter(Node* Current, Node* NewNode);
void InsertBefore(Node* Current, Node* NewNode, Node** Head);
void  InsertNewHead(Node** Head, Node* NewHead);
void  RemoveNode(Node** Head, Node* Remove);
Node* GetNodeAt(Node* Head, int Location);
int   GetNodeCount(Node* Head);

#endif