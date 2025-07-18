#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tageNode
{
	ElementType mData;
}Node;

typedef struct tagCircularQueue
{
	int mCapacity;	//전체 용량
	int mFront;		// 전단 인덱스
	int mRear;		// 후단 인덱스
	
	Node* mNodes;
}CircularQueue;

void CreateQueue(CircularQueue** queue, int capacity);
void DestroyQueue(CircularQueue* queue);
void EnQueue(CircularQueue* queue, ElementType data);
ElementType DeQueue(CircularQueue* queue);
int GetSize(CircularQueue* queue);
int IsEmpty(CircularQueue* queue);
int IsFull(CircularQueue* queue);

#endif
