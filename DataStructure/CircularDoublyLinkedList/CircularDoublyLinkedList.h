#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node
{
	ElementType mData;
	struct Node* mPreNode;
	struct Node* mNextNode;
}Node;

Node* CreateNode(ElementType newData);
void DestroyNode(Node* node);
void AppendNode(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* newNode);
void RemoveNode(Node** head, Node* remove);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);
void PrintNode(Node* _Node);
#endif
