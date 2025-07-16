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

	// strcpy <- �� ģ�� �׳� ���� unsafe ������ ���� �ҷ��� strcpy_s ���ų�
	// #define _CRT_SECURE_NO_WARNINGS <- �̰� �߰������ ��
	strcpy(newNode->mData, data);



	//strcpy_s(newNode->mData, strlen(data) + 1, data); //  �����͸� �����Ѵ�. 

	newNode->pNextNode = NULL; // ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ�Ѵ�. 
	newNode->pPrevNode = NULL;



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
		newNode->pPrevNode = stack->mTop;
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
		//// Top �Ʒ��� �ִ� ��带 ���ο� CurrentTop�� ���� 
		//Node* currentTop = stack->mList;
		//while (currentTop != NULL && currentTop->pNextNode != stack->mTop)
		//{
		//	currentTop = currentTop->pNextNode;
		//}
		//// CurrentTop�� Top�� ����
		//stack->mTop = currentTop;
		//// ������ �ִ� Top�� Pop ��Ŵ. CurrentTop�� ���ο� Top����
		//stack->mTop->pNextNode = NULL;

		stack->mTop = stack->mTop->pPrevNode;
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
