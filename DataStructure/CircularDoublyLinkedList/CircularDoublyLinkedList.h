#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* CreateNode(ElementType NewData);
void  DestroyNode(Node* Node);
void  AppendNode(Node** Head, Node* NewNode);
void  InsertAfter(Node* Current, Node* NewNode);
void  RemoveNode(Node** Head, Node* Remove);
Node* GetNodeAt(Node* Head, int Location);
int   GetNodeCount(Node* Head);

#endif
