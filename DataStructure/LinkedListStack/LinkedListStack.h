#pragma once
#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct tagNode
{
	char* mData;
	struct tagNode* pNextNode;
	struct tageNode* pPrevNode;

}Node;

typedef struct tagLinkedListStack
{
	Node* mList;	// 헤드 노드 주소값
	Node* mTop;		// 꼬리 노드 주소값

}LinkedListStack;

void CreateStack(LinkedListStack** stack);
void DestroyStack(LinkedListStack* stack);

Node* CreateNode(char* data);
void DestroyNode(Node* node);

void Push(LinkedListStack* stack, Node* newNode);
Node* Pop(LinkedListStack* stack);

Node* FindTop(LinkedListStack* stack);
int GetSize(LinkedListStack* stack);
int IsEmpty(LinkedListStack* stack);

#endif // !LINKEDLIST_STACK_H
