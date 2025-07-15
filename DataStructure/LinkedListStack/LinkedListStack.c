#include "LinkedListStack.h"

static int mCount = 0;

void CreateStack(LinkedListStack** stack)
{
	(*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*stack)->mList = NULL;
	(*stack)->mTop = NULL;
}

void DestroyStack(LinkedListStack* stack)
{
	while (!IsEmpty(stack))
	{
		Node* Popped = Pop(stack);
		DestroyNode(Popped);
	}
	free(stack);
}

Node* CreateNode(char* data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->mData = (char*)malloc(strlen(data) + 1);

	// strcpy <- 이 친구 그냥 쓰면 unsafe 에러뜸 방지 할려면 strcpy_s 쓰거나
	// #define _CRT_SECURE_NO_WARNINGS <- 이거 추가해줘야 함
	strcpy(newNode->mData, data);



	//strcpy_s(newNode->mData, strlen(data) + 1, data); //  데이터를 저장한다. 

	newNode->pNextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화한다. 



	return newNode;
}

void DestroyNode(Node* node)
{
	free(node->mData);
	free(node);
}

void Push(LinkedListStack* stack, Node* newNode)
{
	if (stack->mList == NULL)
	{
		stack->mList = newNode;
	}
	else
	{
		stack->mTop->pNextNode = newNode;
	}
	stack->mTop = newNode;
	++mCount;
}

Node* Pop(LinkedListStack* stack)
{
	Node* TopNode = stack->mTop;

	if (stack->mList == stack->mTop)
	{
		stack->mList = NULL;
		stack->mTop = NULL;
	}
	else
	{
		// Top 아래에 있던 노드를 새로운 CurrentTop에 저장 
		Node* currentTop = stack->mList;
		while (currentTop != NULL && currentTop->pNextNode != stack->mTop)
		{
			currentTop = currentTop->pNextNode;
		}
		// CurrentTop을 Top에 저장
		stack->mTop = currentTop;
		// 기존에 있던 Top을 Pop 시킴. CurrentTop이 새로운 Top으로
		stack->mTop->pNextNode = NULL;
	}
	--mCount;
	return TopNode;
}

Node* FindTop(LinkedListStack* stack)
{
	return stack->mTop;
}

int GetSize(LinkedListStack* stack)
{
	/*int mCount = 0;
	Node* current = stack->mList;
	while (current != NULL)
	{
		current = current->pNextNode;
		count++;
	}*/
	return mCount;
}

int IsEmpty(LinkedListStack* stack)
{
	return (stack->mList == NULL);
}
