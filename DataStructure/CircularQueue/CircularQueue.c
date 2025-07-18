#include "CircularQueue.h"

void CreateQueue(CircularQueue** queue, int capacity)
{
	//  큐를 자유 저장소에 생성 
	(*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	//  입력된 Capacity+1 만큼의 노드를 자유 저장소에 생성 
	(*queue)->mNodes = (Node*)malloc(sizeof(Node)* (capacity + 1));
	// capacity + 1을 한 이유는 queue가 가득찬 경우 혹은 없는 경우를 확인하기 위하여
	(*queue)->mCapacity = capacity;
	(*queue)->mFront = 0;
	(*queue)->mRear = 0;
}

void DestroyQueue(CircularQueue* queue)
{
	free(queue->mNodes);
	free(queue);
}

void EnQueue(CircularQueue* queue, ElementType data)
{
	int position = 0;

	if (queue->mRear == queue->mCapacity)
	{
		position = queue->mRear;
		queue->mRear = 0;
	}
	else
	{
		position = queue->mRear++;
	}
	queue->mNodes[position].mData = data;
}

ElementType DeQueue(CircularQueue* queue)
{
	int position = queue->mFront;

	if (queue->mFront == queue->mCapacity) // mFront가 배열의 끝이니 0으로 이동시켜야 함
	{
		queue->mFront = 0;
	}
	else
	{
		queue->mFront++;
	}
	return queue->mNodes[position].mData;
}

int GetSize(CircularQueue* queue)
{
	if (queue->mFront <= queue->mRear)
		return queue->mRear - queue->mFront;
	else
		return queue->mRear + (queue->mCapacity - queue->mFront) + 1;
}

int IsEmpty(CircularQueue* queue)
{
	return (queue->mFront == queue->mRear);
}

int IsFull(CircularQueue* queue)
{
	if (queue->mFront < queue->mRear)
	{
		return (queue->mRear - queue->mFront) == queue->mCapacity;
	}
	else
	{
		return (queue->mRear + 1) == queue->mFront;
	}
}
