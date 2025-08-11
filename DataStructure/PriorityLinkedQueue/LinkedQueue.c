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

Node* CreateNode(int Priority, char* NewData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->mData = (char*)malloc(strlen(NewData) + 1);

	strcpy(newNode->mData, NewData);  //  데이터를 저장한다. 

	newNode->priority = Priority;
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
	/*if (Queue->mFront == NULL)
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
	}*/
	Node* current = Queue->mFront;
	Node* previous = NULL;
	if (Queue->mFront == NULL)
	{
		Queue->mFront = NewNode;
		Queue->mRear = NewNode;
		Queue->mCount++;
		return;
	}
	else
	{
		while (current != NULL)
		{
			if (current->priority <= NewNode->priority)
			{
				// 헤드인 경우
				if (previous == NULL)
				{
					NewNode->mNextNode = current;
					Queue->mFront = NewNode;
					Queue->mCount++;
					return;

				}
				else
				{
 					if (current->priority == NewNode->priority)
					{
						NewNode->mNextNode = current->mNextNode;
						current->mNextNode = NewNode;
						Queue->mCount++;
						return;
					}
					else
					{
						previous->mNextNode = NewNode;
						NewNode->mNextNode = current;
						Queue->mCount++;
						return;
					}
				

				}
			}
			if (current == Queue->mRear && current->priority > NewNode->priority)
			{
				current->mNextNode = NewNode;
				Queue->mRear = NewNode;
				Queue->mCount++;
				return;
			}
			previous = current;
			current = current->mNextNode;
		}
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

Node* Dequeue2(LinkedQueue* Queue, int target)
{
	//  LQ_Dequeue() 함수가 반환할 최상위 노드 
	Node* current = Queue->mFront;
	Node* previous = NULL;
	
	while (current != NULL)
	{
		
		// 타켓 노드 찾음
		if (current->priority == target)
		{
			// 노드가 1개 밖에 없음
			if (current == Queue->mFront && current->mNextNode == NULL)
			{
				Queue->mFront = NULL;
				Queue->mRear = NULL;
				Queue->mCount--;
				return current;
			}
			// 뺄 노드가 Front
			if (current == Queue->mFront)
			{
				Queue->mFront = current->mNextNode;
				current->mNextNode = NULL;
				Queue->mCount--;
				return current;

			}
			// 뺄 노드가 Rear
			else if (current == Queue->mRear)
			{
				Queue->mRear = previous;
				previous->mNextNode = NULL;
				Queue->mCount--;
				return current;
			}
			else
			{
				previous->mNextNode = current->mNextNode;
				current->mNextNode = NULL;
				Queue->mCount--;
				return current;
			}

		}
		previous = current;
		current = current->mNextNode;
	}
	// 못찾음
	return NULL;
}

int IsEmpty(LinkedQueue* Queue)
{
	return (Queue->mFront == NULL);
}
