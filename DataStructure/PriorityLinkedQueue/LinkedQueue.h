#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tagNode
{
	int priority; // 우선 순위
	char* mData;
	struct tagNode* mNextNode;

}Node;

typedef struct tagLinkedQueue
{
	Node* mFront;
	Node* mRear;
	int mCount;

}LinkedQueue;

void  CreateQueue(LinkedQueue** Queue);
void  DestroyQueue(LinkedQueue* Queue);

Node* CreateNode(int Priority , char* Data);
void  DestroyNode(Node* _Node);

void  Enqueue(LinkedQueue* Queue, Node* NewNode);
Node* Dequeue(LinkedQueue* Queue);

int   IsEmpty(LinkedQueue* Queue);

#endif
