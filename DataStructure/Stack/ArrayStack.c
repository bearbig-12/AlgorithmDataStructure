#include "ArrayStack.h"

void CreateStack(ArrayStack** stack, int capacity)
{
	// 스택을 자유 저장소에 생성
	(*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	// 입력된 Capacity 만큼의 노드를 자유 저장소에 생성
	(*stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity);

	// capacity 및 Top 초기화
	(*stack)->mCapacity = capacity;
	(*stack)->mTop = -1;
}

void DestroyStack(ArrayStack* stack)
{
	// 노드를 자유 저장소에서 해제
	free(stack->Nodes);
	// 스택을 자유 저장소에서 해제
	free(stack);
}

void Push(ArrayStack* stack, ElementType data)
{
	if (IsFull(stack))
	{
		Resize(stack);
	}
	stack->mTop++;
	stack->Nodes[stack->mTop].mData = data;
}

ElementType Pop(ArrayStack* stack)
{
	int pos = stack->mTop--;
	return stack->Nodes[pos].mData;
}

ElementType Top(ArrayStack* stack)
{
	return stack->Nodes[stack->mTop].mData;
}

int GetSize(ArrayStack* stack)
{
	return stack->mTop + 1;
}

int IsEmpty(ArrayStack* stack)
{
	return (stack->mTop == -1);
}

bool IsFull(ArrayStack* stack)
{
	if (stack->mTop == stack->mCapacity - 1)
	{
		return true;
	}
	return false;
}

void Resize(ArrayStack* stack)
{
	printf("The stack is Full, Resize the capacity...\n");
	int newCapacity = stack->mCapacity * 2;
	/*
	Node* newNodes = (Node*)malloc(sizeof(Node) * newCapacity);

	for (int i = 0; i < stack->mTop; ++i)
	{
		// 기존 노드의 값 복사
		newNodes[i] = stack->Nodes[i];
	}

	// 기존 노드 해제
	free(stack->Nodes);
	*/

	Node* newNodes = realloc(stack->Nodes, sizeof(Node) * newCapacity);
	//stack->Nodes = realloc(stack->Nodes, newCapacity * sizeof(Node)); // 동적배열 재할당.

	// Top 값은 변함 없음
	stack->mCapacity = newCapacity;
	stack->Nodes = newNodes;

}
