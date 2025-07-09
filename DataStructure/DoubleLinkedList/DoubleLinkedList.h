#pragma once
#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H


#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* prevNode;
	struct tagNode* nextNode;

} Node;


Node* CreateNode(ElementType newData);
void DestroyNode(Node* node);
void AppendNode(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* newNode);
void RemoveNode(Node** head, Node* remove);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);
void PrintNode(Node* _Node);

#endif