#define _CRT_SECURE_NO_WARNINGS


#include "LinkedQueue.h"

void CreateQueue(LinkedQueue** Queue)
{
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->mFront = NULL;
	(*Queue)->mRear = NULL;
	(*Queue)->mCount = 0;
}

void DestroyQueue(LinkedQueue* Queue)
{
	while (!IsEmpty(Queue))
	{
		Node* Popped = Dequeue(Queue);
		DestroyNode(Popped);
	}
	free(Queue);
}

Node* CreateNode(char* NewData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->mData = (char*)malloc(strlen(NewData) + 1);

	strcpy(newNode->mData, NewData);  //  데이터를 저장한다. 

	newNode->mNextNode = NULL; //  다음 노드에 대한 포인터는 NULL로 초기화한다. 

	return newNode;//  노드의 주소를 반환한다. 
}

void  DestroyNode(Node* _Node)
{
	free(_Node->mData);
	free(_Node);
}

void Enqueue(LinkedQueue* Queue, Node* NewNode)
{
	if (Queue->mFront == NULL)
	{
		Queue->mFront = NewNode;
		Queue->mRear = NewNode;
		Queue->mCount++;
	}
	else
	{
		Queue->mRear->mNextNode = NewNode;
		Queue->mRear = NewNode;
		Queue->mCount++;
	}
}

Node* Dequeue(LinkedQueue* Queue)
{
	//  LQ_Dequeue() 함수가 반환할 최상위 노드 
	Node* Front = Queue->mFront;

	if (Queue->mFront->mNextNode == NULL)
	{
		Queue->mFront = NULL;
		Queue->mRear = NULL;
	}
	else
	{
		Queue->mFront = Queue->mFront->mNextNode;
	}

	Queue->mCount--;

	return Front;
}

int IsEmpty(LinkedQueue* Queue)
{
	return (Queue->mFront == NULL);
}
